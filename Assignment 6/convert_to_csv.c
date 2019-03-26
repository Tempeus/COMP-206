#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert_to_csv.h"

/*Function takes a file and converts it into a new csv file called output.csv*/
void load_and_convert(const char* filename){
	printf("\nConverting file to CSV file...\n");

	//Opening the file as read
	FILE* f1 = fopen(filename,"rt");
	

	//Creating a file called output.csv
	FILE* f2 = fopen("output.csv", "wt");

	//If failed to open file name, exit
	if (f1 == NULL){
		printf("Failed to execute action\n");
		return;
	}

	char line1[100];
	fgets(line1,100, f1);

	char line2[100];
	fgets(line2,100, f1);

	char line3[100];
	fgets(line3,100, f1);

	char* name = strtok(line1, "\n");
	char* age = strtok(line2, "\n");
	char* location = strtok(line3, "\n");
	char* sName;
	char* sAge;
	char* sLocation;

	while (sName = strtok_r(name, " ", &name)){
		sAge = strtok_r(age, " ", &age);
		sLocation = strtok_r(location, " ", &location);
		fprintf(f2,"%s, %s, %s\n",sName, sAge, sLocation);
	}
	printf("\nConversion was successful\n");
	fclose(f1);
	fclose(f2);
}

