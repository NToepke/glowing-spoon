CREATE DATABASE `BloodBank!`;

CREATE TABLE `person` (
  `PersonID` int(8) NOT NULL AUTO_INCREMENT,
  `FirstName` varchar(25) NOT NULL,
  `MiddleName` varchar(25) DEFAULT NULL,
  `LastName` varchar(25) NOT NULL,
  `BloodGroup` varchar(3) NOT NULL,
  `MedicalData` varchar(250) DEFAULT NULL,
   PRIMARY KEY (PersonID)
);

CREATE TABLE `donor` (
  `PersonID` int(8) NOT NULL,
  `DonorPhoneNo` varchar(14) NOT NULL,
  `StreetAddress` varchar(50) NOT NULL,
  `City` varchar(30) NOT NULL,
  `State` varchar(20) NOT NULL,
  `Zipcode` int(5) UNSIGNED NOT NULL,
   PRIMARY KEY (PersonID),
   FOREIGN KEY (PersonID) REFERENCES person(PersonID)
);

CREATE TABLE `emergency contact` (
  `PersonID` int(8) NOT NULL,
  `ContactName` varchar(25) NOT NULL,
  `ContactPhoneNo` varchar(14) NOT NULL,
  `Relationship` varchar(20) DEFAULT NULL,
  `StreetAddress` varchar(50) NOT NULL,
  `City` varchar(30) NOT NULL,
  `State` varchar(20) NOT NULL,
  `Zipcode` int(5) UNSIGNED NOT NULL,
  PRIMARY KEY (PersonID,ContactName),
  FOREIGN KEY (PersonID) REFERENCES person(PersonID)
);

CREATE TABLE `donationsite` (
  `SiteID` int(4) NOT NULL,
  `LocationAddress` varchar(50) NOT NULL,
  `LocationName` varchar(25) NOT NULL,
  `StartDate` date NOT NULL DEFAULT current_timestamp(),
  `EndDate` date NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (SiteID)
);

CREATE TABLE `donateat` (
  `PersonID` int(8) NOT NULL,
  `SiteID` int(4) NOT NULL,
  `DonationDate` date NOT NULL DEFAULT current_timestamp(),
  PRIMARY KEY (PersonID,SiteID),
  FOREIGN KEY (PersonID) REFERENCES person(PersonID),
  FOREIGN KEY (SiteID) REFERENCES donationsite(SiteID)
);

CREATE TABLE `bloodbank` (
  `BankName` varchar(20) NOT NULL,
  `BankAddress` varchar(50) NOT NULL,
  `BankPhoneNo` varchar(14) NOT NULL,
  `ManagerName` varchar(25) DEFAULT NULL,
  PRIMARY KEY (BankName)
);

CREATE TABLE `transfersblood` (
  `SiteID` int(4) NOT NULL,
  `BankName` varchar(20) NOT NULL,
  PRIMARY KEY (BankName,SiteID),
  FOREIGN KEY (BankName) REFERENCES bloodbank(BankName),
  FOREIGN KEY (SiteID) REFERENCES donationsite(SiteID)
);

CREATE TABLE `patient` (
  `PersonID` int(8) NOT NULL,
  `TransactionSite` varchar(50) NOT NULL,
  PRIMARY KEY (PersonID),
  FOREIGN KEY (PersonID) REFERENCES person(PersonID)
);

CREATE TABLE `deliversblood` (
  `BankName` varchar(20) NOT NULL,
  `PersonID` int(8) NOT NULL,
  `TrackingNumber` int(15) NOT NULL,
  PRIMARY KEY (BankName,PersonID),
  FOREIGN KEY (BankName) REFERENCES bloodbank(BankName),
  FOREIGN KEY (PersonID) REFERENCES person(PersonID)
);

-- populate person
INSERT INTO `person` (`PersonID`, `FirstName`, `MiddleName`, `LastName`, `BloodGroup`, `MedicalData`) 
VALUES ('1', 'Sylvanus', 'Vinal', 'Sheridan', 'A-', 'Broke arm in 7th grade.'),
 ('2', 'John Paul', NULL, 'Martell', 'AB-', NULL),
 ('3', 'Tessa', 'Giolla', 'Bhrighde', 'B+', NULL),
 ('4', 'Lester', NULL, 'Leoni', 'O-', NULL),
 ('5', 'Jayda', 'Prochoros', 'Gustafsson', 'O+', 'Stage 4 liver cancer.'),
 ('6', 'Garland', 'Ottone', 'Winter', 'AB-', 'Habitual blood donor.'),
 ('7', 'Hester', 'Gunilla', 'Albanesi', 'AB+', NULL),
 ('8', 'Cecily', NULL, 'Bulgarelli', 'B+', NULL),
 ('9', 'Shevon', 'Jaala', 'Scordato', 'B-', 'On blood thinners.'),
 ('10', 'Rossella', 'Gunner', 'Ferrara', 'A-', 'Has athlete\'s foot.'),
 ('11', 'Hjalmar', 'Camron', 'Silvestra', 'O-', 'Has a rare antigen in their blood.'),
 ('12', 'Adrian', NULL, 'Riain', 'O+', NULL),
 ('13', 'Romola', 'Aurelio', 'Waterman', 'B-', NULL),
 ('14', 'Drake', 'Byron', 'Busto', 'AB+', 'Wishes they were a doctor.'),
 ('15', 'Ivano', 'Ash', 'Figueroa', 'A+', NULL);
 
 -- Example of autoincrement insertion
 INSERT INTO `person`(`FirstName`, `MiddleName`, `LastName`, `BloodGroup`, `MedicalData`) 
 VALUES ('Gigi','Raniero','Cowden','AB-',NULL);
 
 -- populate patient
 INSERT INTO `patient` (`PersonID`, `TransactionSite`) 
 VALUES ('1', 'Mercy Hospital'),
 ('2', 'University Hospital'),
 ('3', 'Mercy Hospital'),
 ('4', 'University Hospital'),
 ('5', 'Depaul Hospital'),
 ('13', 'University Hospital');
 
 -- populate donor
 INSERT INTO `donor` (`PersonID`, `DonorPhoneNo`, `StreetAddress`, `City`, `State`, `Zipcode`) 
 VALUES ('6', '803-555-0152', '57 Grove St.', 'Freeport', 'New York', '11520'),
 ('7', '803-555-0195', '8484 Sherman Street', 'Roy', 'Utah', '84067'),
 ('8', '803-555-0137', '84 Bald Hill Drive', 'Huntsville', 'Alabama', '35803'),
 ('9', '803-555-0122', '204 Homewood Street', 'Wallingford', 'Connecticut', '44512'),
 ('10', '803-555-0118', '9825 Garfield Road', 'Dubuque', 'Iowa', '52001'),
 ('11', '803-555-0149', '47 West Goldfield Street', 'Youngstown', 'Ohio', '44512'),
 ('12', '803-555-0177', '47 Vine Street', 'Fall River', 'Massachusetts', '02720'),
 ('14', '404-555-0182', '9851 South Devon Street', 'Hicksville', 'New York', '11801'),
 ('15', '404-555-0195', '7179 Honey Creek Avenue', 'Gwynn Oak', 'Maryland', '21207'),
 ('16', '404-555-0128', '78 Blackburn Avenue', 'Glenside', 'Pennsylvania', '19038');
 
 -- populate bloodbank
 INSERT INTO `bloodbank` (`BankName`, `BankAddress`, `BankPhoneNo`, `ManagerName`)
 VALUES ('McCarthy North', '304C East Wintergreen Ave.', '626-555-0192', 'James McCarthy'),
 ('Humbolt Center', '494 La Sierra St.', '512-555-0104', 'Tim McGraw'),
 ('University Bank', '925 Rose St. ', '410-555-0122', NULL);
 
 -- populate donationsite
 INSERT INTO `donationsite` (`SiteID`, `LocationAddress`, `LocationName`, `StartDate`, `EndDate`)
 VALUES ('8733', '26 Bellevue Court', 'McCarthy South', '2021-04-05', '2021-05-04'),
 ('2253', '123 Newbridge Ave.', 'Jones Elementary', '2017-05-17', '2023-05-26'),
 ('5555', '7193 Iroquois St.', 'Taylor Center', '2021-01-04', '2021-05-14'),
 ('4355', '8393 Hillcrest Street', 'Akron High', '2021-05-01', '2021-05-15'),
 ('0144', '9 Logan Street', 'University Central', '2014-05-14', '2030-05-25'),
 ('0775', '214 Sugar St.', 'St. James Center', '2016-12-08', '2019-01-17');
 
 -- populate transfersblood
 INSERT INTO `transfersblood` (`SiteID`, `BankName`)
 VALUES ('4355', 'University Bank'),
 ('5555', 'Humbolt Center'),
 ('2253', 'McCarthy North'),
 ('775', 'Humbolt Center'),
 ('144', 'University Bank'),
 ('8733', 'McCarthy North');
 
 -- populate donateat
 INSERT INTO `donateat` (`PersonID`, `SiteID`, `DonationDate`)
 VALUES ('6', '144', '2020-05-12'),
 ('6', '8733', '2021-05-01'),
 ('6', '2253', '2022-06-16'),
 ('7', '144', '2026-05-07'),
 ('8', '8733', '2021-05-02'),
 ('9', '2253', '2019-02-19'),
 ('10', '775', '2017-09-09'),
 ('11', '5555', '2021-02-10'),
 ('12', '4355', '2021-05-11'),
 ('14', '4355', '2021-05-11'),
 ('15', '775', '2018-03-10'),
 ('16', '144', '2021-08-07');

-- populate deliversblood`
INSERT INTO `deliversblood` (`BankName`, `PersonID`, `TrackingNumber`)
 VALUES ('Humbolt Center', '1', '15'),
 ('Humbolt Center', '2', '8333'),
 ('McCarthy North', '3', '9255'),
 ('McCarthy North', '4', '4777'),
 ('University Bank', '5', '8612'),
 ('University Bank', '13', '1198');
 
 -- populate emergency contact`
 INSERT INTO `emergency contact` (`PersonID`, `ContactName`, `ContactPhoneNo`, `Relationship`, `StreetAddress`, `City`, `State`, `Zipcode`)
 VALUES ('6', 'Sandra Howard', '617-555-0144', 'Roommate', '683 Center Ave.', 'Aliquippa', 'Pennsylvania', '15001'),
 ('7', 'Caitlin Albero', '617-555-0133', 'Fiancee', '56 Rosewood Street', 'Sarasota', 'Florida', '34231'),
 ('8', 'John Bulgarelli', '701-555-0148', 'Spouse', '8685 Hill Field Lane', 'Whitehall', 'Pennsylvania', '18052'),
 ('9', 'Jaala Scordato', '636-555-0199', 'Parent', '431 High Ridge Avenue', 'Dorchester Center', 'Massachusetts', '02124'),
 ('11', 'Karolyn Lyons', '225-555-0134', 'Significant Other', '993 Mayfair Dr.', 'Raeford', 'North Carolina', '28376'),
 ('10', 'Beyonce Smith', '303-555-0165', NULL, '26 Crescent St.', 'Poughkeepsie', 'New York', '12601'),
 ('12', 'Adrian Riain Sr.', '208-555-0131', 'Father', '804 Bow Ridge St.', 'Chippewa Falls', 'Wisconsin', '54729'),
 ('14', 'Wilma Busto', '225-555-0197', 'Mother', '84 High Ridge St', 'Elizabethtown', 'Pennsylvania', '17022'),
 ('15', 'Franco \'Tex\' Arbore', '907-555-0176', 'Fiance', '7179 Honey Creek Avenue', 'Gwynn Oak', 'Maryland', '21207'),
 ('16', 'Harold Cowden', '602-555-0187', 'Spouse', '78 Blackburn Avenue', 'Glenside', 'Pennsylvania', '19038');
 
 -- DATABASE POPULATED