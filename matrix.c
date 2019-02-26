#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define rows 5
#define cols 5


//This function is used to fill a 5x5 matrix with randomly generated numbers in the range of between 1 to 100.
void fillMatrix(int matrix[rows][cols]);

//This function takes a 5x5 matrix as parameter and print each row of the matrix to the screen line by line.
void printmatrix(int matrix[rows][cols]);

//This function takes a x5 matrix as parameter and transpose it
void transposematrix(int matrix[rows][cols]);

//This function takes 3 matrices as parameters and will calculate the product of the first two matrices and place the result into the third one.
void multiplyMatrix(int m1[2][cols], int m2[rows][cols], int resultMatrix[rows][cols]);

int main(){
	//Initializing the matrix
	int matrix[rows][cols];

	//fill the matrix with random numbers
	fillMatrix(matrix);
	
	//print the matrix to the screen
	printMatrix(matrix);

	//transpose the matrix
	transposeMatrix(matrix);

	//print the new matrix to the screen
	printMatrix(matrix);

	//create a new matrix with only two rows
	int matrix2[2][cols] = {0,1,2,3,4,5,6,7,8,9};

	//create a matrix that will contain the results
	int resultMatrix[rows][cols];

	//multiply matrix and matrix2  and append the result into matrixResult
	multiplymatrix(matrix2, matrix, resultMatrix);

	//print matrixResult to the screen
	printMatrix(resultMatrix);

	return 0;
}

void fillMatrix(int matrix[rows][cols]){
	time_t t;
	
	//in order to make it entire random, we must give it a seed that changes constantly, which is why we give a time parameter
	srand((unsigned) time(&t));

	for (int i = 0; i < rows; i ++){
		for (int k = 0; k < cols; k ++){
			matrix[i][k] = rand() %100 + 1; //+1 to include 100 in the range
		}
	}

}

void printMatrix(int matrix[rows][cols]){
	for (int i = 0; i < rows; i++){
		printf(" [");
		for (int k = 0; k < cols; k++){
			printf("%d    ", matrix[i][k]);
		}
		printf("]\n");
	}
}

void transposeMatrix(int matrix[rows][cols]){
	int temp[rows][cols];

	//make a temporary copy of the matrix in order to tranpose the original one
	for(int i = 0; i < rows; i++){
		for(int k = 0; k < cols; k++){
			temp[i][k] = matrix[i][k];
		}
	}

	//Tranpose the matrix
	
	for(int i = 0; i < rows; i++){
		for(int k = 0; k < cols; k++){
			matrix[i][k] = temp[k][i];
		}
	}
}

void multiplyMatrix(int m1[2][cols], int m2[rows][cols], int resultMatrix[rows][cols]){
	//the sums from the multiplication
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < rows; i++){
		sum1 = 0;
		sum2 = 0;
		for(int k = 0; k < cols; k++){
			sum1 += (m1[0][k] * m2[k][i]);
			sum2 += (m1[1][k] * m2[k][i]);
		}
		resultMatrix[0][i] = sum1;
		resultMatrix[1][i] = sum2;
	}
}

