#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringsort(char*);

int main( int argc, char *argv[]){
	if (argc == 3){ //Verifying if the user gave two arguments
		
		//Finding the length of the arguments	
		int len1 = strlen(argv[1]);
		int len2 = strlen(argv[2]);
		
		//If the length of the arguments aren't the same, then they can't be anagrams
		if(len1 != len2){
			printf("These are not anagrams\n");
			return 1;
		}
		
		//Sorting the array of characters by their ASCII code number
		stringsort(argv[1]);
		stringsort(argv[2]);
		
		//Converting those arrays of characters into strings
		char *str1 = argv[1];
		char *str2 = argv[2];

		//Comparing the strings to see if they are equivalent
		if(strcmp(str1,str2) != 0){
			printf("These are not anagrams\n");
			return 1;
		}

		//If the arguments passed the previous tests, they are anagrams.
		printf("These are anagrams\n");
		return 0;
	}
	
	//If more than 2 arguments were given, the program will not execute
	else if (argc > 3){ 
		printf("Too many arguments\n");
		return 1;
	}

	//If no arguments were given, the program will not execute
	else{
		printf("Expected 2 arguments\n");
		return 1;
	}
}

//C Function that sorts the command line arguments in alphabetical order by using their ASCII code.
void stringsort(char *s){
	int c;
	int d = 0;
	int len;

	char *p;
	char *r;
	char ch;

	len = strlen(s);

	r = (char*)malloc(len+1);

	p = s;

	for(ch = 'a'; ch <= 'z'; ch++){
		for( c = 0; c < len; c++){
			if(*p == ch){
				*(r+d) = *p;
				d++;
			}
			p++;
		}
		p = s;
	}
	*(r+d) = '\0';
	strcpy(s,r);
	free(r);
}
