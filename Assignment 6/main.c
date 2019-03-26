#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert_to_csv.h"
#include "read_csv.h"

//Prototyping:

/* Function will check whether a name exists in the csv file.
 * If it exists, print records to screen.
 * If the names were repeated multiple times, print all to the screen
 * If doesn't exist, print name not found */
void find_name(const char* csv_filename, const char* name);

/* Function will add a new record to the end of the CSV file. */
void add_record(const char* csv_filename, const char* name, const int age, const char* city);

/* Function will delete a record from the CSV file*/
void delete_record(const char* csv_filename, const char* name);

int main(){
	/* Question 1 */
	load_and_convert("INFO.txt");
	
	/* Question 2 */
	read_csv("output.csv");

	/* Question 3.1 */
	find_name("output.csv", "Maria");

	find_name("output.csv", "Jason"); //Jason doesn't exist

	
	/* Quesiton 3.2 */
	add_record("output.csv", "Jason", 36, "Skookumchuk");
	read_csv("output.csv");

	/* Question 3.3 */
	//delete_record("output.csv", "Maria");
	//read_csv("output.csv"); //To print to the screen


	return 0;
}

void find_name(const char* csv_filename, const char* name){
	
	//Opening the file with the names
	FILE* f = fopen(csv_filename, "rt");
	
	if(f == NULL){
		printf("File not found\n");
		return;
	}

	char line[101];
	fgets(line, sizeof(line),f);
	
	//See if we had matches
	int match = 0;

	char string[101];
	
	printf("\nSearching for matches...\n");
	while(fgets(line,101,f) != NULL){
		strcpy(string, line);
		if (strcmp(strtok(line, ", "), name) == 0){
			printf("%s", string);
			match = 1;
		}
	}

	if(!match){
		printf("Name not found\n");
	}

	fclose(f);
}

void add_record(const char* csv_filename, const char* name, const int age, const char* city){
	FILE* f = fopen(csv_filename, "at");
	if (f == NULL){
		printf("File not found\n");
		return;
	}
	
	printf("\nAdding information to record...\n");
	fprintf(f, "%s, %d, %s\n",name, age,city);
	fclose(f);
}

void delete_record(const char* csv_filename, const char* name){

}
