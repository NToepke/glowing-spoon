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
        
    if($function == "mostDonated"){
        $sql = "SELECT TotalDonations,person.FirstName FROM (SELECT Counted.PersonID,MAX(Donations) as 'TotalDonations' FROM (SELECT Count(*) as 'Donations',PersonID FROM donateat GROUP BY PersonID ORDER BY COUNT(*) DESC) AS Counted) AS NEW JOIN person where NEW.PersonID = person.PERSONID";
        
        if($result = $connection->query($sql)){
			$row = $result->fetch_assoc();
			//$donations = $result->fetch_array()[0];
			//$name = $result->fetch_array()[1];
            echo "Most Donations: ".$row['TotalDonations']."  By:  ".$row['FirstName'];
            $result->free_result();
        }
        else {
            echo "Error querying the Most Donations";
        }
    }
    
    if($function == "displayReminder"){
        echo "For times' sake, not completed";
    }

    if($function == "totalDonors"){
        echo "For times' sake, not completed";
    }

    if($function == "averageDonors"){
        $sql = "SELECT AVG(Donations) as 'Average Donations' FROM (SELECT COUNT(*) as 'Donations' FROM Donateat as R1 GROUP BY PersonID ORDER BY COUNT(*) DESC) as sums";
        
        if($result = $connection->query($sql)){
			$tourresult = $result->fetch_array()[0];
            echo "Average Donations Per Donor: " . $tourresult;
            $result->free_result();
        }
        else {
            echo "Error querying the Average Donations Per Donor";
        }
    }

    if($function == "tracking"){
        $personID = empty($_POST['personID']) ? '' : $_POST['personID'];
        
        $sql = "SELECT TrackingNumber FROM `deliversblood` WHERE PersonID = $personID";
        
        if($result = $connection->query($sql)){
			$tourresult = $result->fetch_array()[0];
            echo "Tracking Number: " . $tourresult;
            $result->free_result();
        }
        else {
            echo "Error querying the Tracking Number";
        }
    }

    if($function == "mostRecent"){
        echo "For times' sake, not completed";
    }

    if($function == "possibleDonors"){
        echo "For times' sake, not completed";
    }

    if($function == "possibleRecipients"){
        echo "For times' sake, not completed";
    }

    if($function == "findContact"){
        echo "For times' sake, not completed";
    }

    if($function == "findActiveSites"){
        $sql = "SELECT SiteID,LocationName FROM `donationsite` WHERE StartDate < CURRENT_DATE && EndDate > CURRENT_DATE";
        
        if($result = $connection->query($sql)){
			echo "Current Active site ID's:<br>";

		while($row = $result->fetch_assoc())
		{
			echo $row['SiteID']."   ".$row['LocationName']."<br>";
		}
        $result->free_result();
        }
        else {
            echo "Error querying the Active Donation Sites";
        }
    }

    if($function == "displayDonors"){
        $state = empty($_POST['state']) ? '' : $_POST['state'];
        $sql = "SELECT PersonID,City FROM `donor` where State = '$state'";
        
        if($result = $connection->query($sql)){
				echo "Donors ID's of donors in $state:<br>";
		while($row = $result->fetch_assoc())
		{
			echo $row['PersonID']."<br>";
		}
            $result->free_result();
        }
        else {
            echo "Error querying the Donors From " . $state;
        }
    }

    $connection->close();

?>