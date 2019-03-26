#include <stdio.h>
#include <stdlib.h>

/*Function will read a CSV File and print its concent to the screen line by line*/
void read_csv(const char* csv_filename){

	printf("\nReading CSV file...\n");
	//Opening a CSV file
	FILE* f1 = fopen(csv_filename, "rt");
	
	//If failed, exit
	if(f1 == NULL){
		printf("Failed to execute\n");
		return;
	}

	printf("\nPrinting record...\n");
	char c = fgetc(f1);
	while(c != EOF){
		printf("%c", c);
		c = fgetc(f1);
	}
	printf("\nPrinting was successful\n");
	fclose(f1);
}
