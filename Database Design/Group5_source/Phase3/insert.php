<?php
    $server = "localhost";
    $user = "root";
    $pass = "";
    $db = "bloodbank!";
    
    $connection = new mysqli($server, $user, $pass, $db);

    if($connection->connect_error){
        die("Connection failed: " . $connection->connect_error);
    }

    $function = empty($_POST['subButton']) ? '' : $_POST['subButton'];

    if($function == "insertBank"){
        echo "For times' sake, not implemented";
    }
    
    if($function == "insertDonationSite"){
        echo "For times' sake, not implemented";
    }

    if($function == "insertDonor"){
        $donorFName = empty($_POST['donorFName']) ? 'NULL' : $_POST['donorFName'];
        $donorMName = empty($_POST['donorMName']) ? 'NULL' : $_POST['donorMName'];
        $donorLName = empty($_POST['donorLName']) ? 'NULL' : $_POST['donorLName'];
        $donorID = empty($_POST['donorID']) ? 'NULL' : $_POST['donorID'];
        $bloodGroup = empty($_POST['bloodGroup']) ? 'NULL' : $_POST['bloodGroup'];
        $medicalData = empty($_POST['medicalData']) ? 'NULL' : $_POST['medicalData'];
        $donorPhone = empty($_POST['donorPhone']) ? 'NULL' : $_POST['donorPhone'];
        $donorAddress = empty($_POST['donorAddress']) ? 'NULL' : $_POST['donorAddress'];
        $donorCity = empty($_POST['donorCity']) ? 'NULL' : $_POST['donorCity'];
        $donorState = empty($_POST['donorState']) ? 'NULL' : $_POST['donorState'];
        $donorZipcode = empty($_POST['donorZipcode']) ? 'NULL' : $_POST['donorZipcode'];
        $donationDate = empty($_POST['donationDate']) ? 'NULL' : $_POST['donationDate'];
        $siteID = empty($_POST['siteID']) ? 'NULL' : $_POST['siteID'];
        $emergencyName = empty($_POST['emergencyName']) ? 'NULL' : $_POST['emergencyName'];
        $emergencyNumber = empty($_POST['emergencyNumber']) ? 'NULL' : $_POST['emergencyNumber'];
        $relation = empty($_POST['relation']) ? 'NULL' : $_POST['relation'];
        $emergencyAddress = empty($_POST['emergencyAddress']) ? 'NULL' : $_POST['emergencyAddress'];
        $emergencyCity = empty($_POST['emergencyCity']) ? 'NULL' : $_POST['emergencyCity'];
        $emergencyState = empty($_POST['emergencyState']) ? 'NULL' : $_POST['emergencyState'];
        $emergencyZipcode = empty($_POST['emergencyZipcode']) ? 'NULL' : $_POST['emergencyZipcode'];
		//$donorID = mysql_insert_PersonID();
        
        $sql = "INSERT INTO `person`(`PersonID`, `FirstName`, `MiddleName`, `LastName`, `BloodGroup`, `MedicalData`) 
                 VALUES ($donorID,'$donorFName','$donorMName','$donorLName','$bloodGroup','$medicalData');
 
                 INSERT INTO `donor`(`PersonID`, `DonorPhoneNo`, `StreetAddress`, `City`, `State`, `Zipcode`)
                 VALUES ($donorID,'$donorPhone','$donorAddress','$donorCity','$donorState',$donorZipcode);
 
                 INSERT INTO `emergency contact`(`PersonID`, `ContactName`, `ContactPhoneNo`, `Relationship`, `StreetAddress`, `City`, `State`, `Zipcode`)
                 VALUES ($donorID,'$emergencyName','$emergencyNumber','$relation','$emergencyAddress','$emergencyCity','$emergencyState',$emergencyZipcode); 
 
                 INSERT INTO `donateat`(`PersonID`, `SiteID`, `DonationDate`) 
				 VALUES ($donorID,$siteID,'$donationDate');
				 ";
        
        if($connection->multi_query($sql) === TRUE){
            echo "Insertion successful!";
        }
        else {
            echo "Error: " . $sql . "<br>" . $connection->error;
        }
    }

    if($function == "insertPatient"){
        echo "For times' sake, not implemented";
    }

    $connection->close();

?>