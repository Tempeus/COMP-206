#!/bin/bash

#This script will be used to automate the process of testing the anagram.c executable.

clear

gcc -o anagram anagram.c

./anagram listen silent
if [ $? = 0 ]
then
	echo "Test succeeded."
else
	echo "Test failed."
fi



./anagram listen silence
if [ $? = 1 ]
then
	echo "Test succeeded."
else
	echo "Test failed."
fi



echo "Execution of anagram program has ended successfully!"
