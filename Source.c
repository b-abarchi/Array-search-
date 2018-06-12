//------------------------------------------
//BELLO ABARCHI
//4/18/2017
// LINEAR AND BINARY SEARCH
//============================================
//============================================
//============================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50000
#define PAUSE getchar()
//============================================
// ProtoType Functions Here
int getRandom();
void binarySearch(int array1[], int count);
void displayArray(int a[], int c);
void loadArray(int a[], int c);
void searchArray(int array1[]);
void sortTheArray(int array1[], int count);
char switchValues(int array1[], int i);
//============================================
main() {
	int array1[SIZE] = { 0 };  // the array of random numbers
	int count = SIZE;  // the effective size of the array
	srand((unsigned)time(NULL)); // seed the rand function
	loadArray(array1, count);
//	displayArray(array1, count);
	printf("\n\t===========\n\n");
	printf("\tLINEAR SEARCH\n\n");
	printf("\n\t===========\n\n");
	searchArray(array1);
	printf("SORTING...THIS WILL TAKE A MINUTE\n");
	sortTheArray(array1, count);//THE SORTING FUNCTION WILL TAKE A MINUTE BECAUSE OF SIZE OF THE ARRAY444
	printf("\n\t===========\n\n");
	printf("\tSORTED ARRAY\n\n");
	printf("\n\t===========\n\n");
	displayArray(array1, count);
	printf("\n\t===========\n\n");
	printf("\tBINARY SEARCH\n\n");
	printf("\n\t===========\n\n");
	binarySearch(array1, count);
	PAUSE; PAUSE;
}//end of main
void binarySearch(int array[], int count) {
	int	first = 0;
	int last = 0;
	int	middle = 0;
	int search = 0;
	printf("Enter value to find\n");
	scanf("%d", &search);
	first = 0;
	last = count - 1;
	int countL = 0;
	while (first <= last) {
		countL++;
		middle = (first + last) / 2;
		if (array[middle] > search)
			first = middle + 1;
		else if (array[middle] == search) {
			printf("%d found at location %d.\n", search, middle + 1);
			break;
		}
		else
			last = middle - 1;

		middle = (first + last) / 2;
	}
	printf("Search took %i looks", countL);
	if (first >= last)
		printf("Not found! %d is not present in the list.\n", search);
	return 0;
}//end of binarySearch
int getRandom() {
	int result;
	result = rand();
	return result;
} // end getRandom

void displayArray(int a[], int c) {
	int i;
	printf("\n\t=================================\n\n");
	printf("\tHERE IS THE CONTENTS OF THE ARRAY\n\n");
	printf("\n\t=================================\n\n");
	for (i = 0; i < SIZE; i++)
		printf("%i. contains %i\n", i + 1, a[i]);
} // end display Array
void loadArray(int array[], int c) {
	int i = 0;
	for (i = 0; i < SIZE; i++)
		array[i] = getRandom();
} // end load array
void searchArray(int array[]) {
	int search = 0;
	int i = 0;
	int countT = 0;
	printf("Enter the number to search\n");
	scanf("%i", &search);
	for (i = 0; i < SIZE; i++)
		//countT++;
		if (array[i] == search)
		{
			printf("%i is present at location %i. \n", search, i + 1);
			//printf("Search took %i looks", countT);

		}
}//end of searchArray
char switchValues(int array1[], int i) {
	int temp;
	temp = array1[i];
	array1[i] = array1[i + 1];
	array1[i + 1] = temp;
	return 'Y';
}//end switchValues
void sortTheArray(int array1[], int count) {
	char switchMade = 'N';
	int bottom = count - 1;
	int i;
	do {
		switchMade = 'N';
		for (i = 0; i < bottom; i++) 
			if (array1[i] < array1[i + 1]) {
				switchMade = switchValues(array1, i);
			}
		bottom--;
	} while (switchMade == 'Y');
}//end of sortArray