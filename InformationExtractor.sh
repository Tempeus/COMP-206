#!/bin/bash

#This script will be used to automate the process of earching and filtering information then logging it to a log file

# $1 is the directory's name

#Clearing the screen
clear

#change directory to home directory
cd $Home

#verifies whether a subdirectory called #1 exists, if it does not exist it will create the directory
File=$1

if [$File]
then 
	echo "File $File exists."
else
	mkdir $1
fi

#Moving into $1
cd $1

#Verifies if extractor.log exists, if not ,it wil lcreate a log file
if [extractor.log]
then
	echo "extractor.log exists"
else
	touch extractor.log
fi

#verify if file called information exists, it not, it will create the file
if [Information]
then
	echo "Information file already exists"
else
	touch Information
	echo "Information file is created"
fi

#Changing the security of the Information file
chmod 640 Information

#Writting into the log
echo "Access right changed for Information file" >> extractor.log

#Appending users into Information file
Users= who -q | grep "[a-d]"
Num= who | grep -c "[a-d]"

#Notifying the change log
echo "List of user names has been added to the Information file" >> extractor.log

#Notifying number of found users into log file
echo "The number of found users is: $Num" >> extractor.log

#Termination of script
echo "Execution of InformationExtractor script has ended successfully!"

