#!/bin/bash

#This script will be used to automate the process of earching and filtering information then logging it to a log file

# $1 is the directory's name

#Clearing the screen
clear

#Change directory to home directory
cd $Home

#Verifies whether a subdirectory called #1 exists, if it does not exist it will create the directory

if [ ! -d ./$1 ]
then
	mkdir $1
fi

#Moving into $1
cd $1

#Verifies if extractor.log exists, if not ,it will create a log file
if [ ! -f extractor.log ]
then
	touch extractor.log
fi

#verify if file called information exists, it not, it will create the file
if [ -f Information ]
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
who | grep [a-d] | awk '{print $1}' >> Information

#Notifying the change log
echo "List of user names has been added to the Information file" >> extractor.log

#Notifying number of found users into log file
echo "The number of found users is: $(who | grep -c [a-d])" >> extractor.log

#Termination of script
echo "Execution of InformationExtractor script has ended successfully!"

