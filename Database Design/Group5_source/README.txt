Database creation SQL code is in Phase3.sql
All queries are embedded into the website.
For example, the delete patient query is in delete.php
as it is a deletion query. It looks like this:

if($function == "deletePatient"){
        $patientID = empty($_POST['patientID']) ? '' : $_POST['patientID'];
       
        $sql = "DELETE FROM `deliversblood` WHERE PersonID=$patientID;
                 DELETE FROM `patient` WHERE PersonID = $patientID;
                 DELETE FROM `person` WHERE PersonID = $patientID";

        if($connection->multi_query($sql) === TRUE){		
			echo "Deletion successful!";
        }
        else {
            echo "Error: " . $sql . "<br>" . $connection->error;
        }	
    }

Each query, with variable usage, is stored in a variable $sql.

Insert Donor is our insertion function.
Delete Patient is our deletion function.
Modify Medical data is our modification function.
Most Donated includes a table join.
Average Donors uses the AVG and COUNT operations.
Tracking is a keyword query, and so is Display Donors.