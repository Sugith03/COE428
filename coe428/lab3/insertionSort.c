#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last)
    {
	int a,b,temp_variable; //Variables
	temp_variable = last - first;	
	
	for (a = 0; a <= temp_variable; a++) { //Goes from the first array and sorts through til the last array
	b = a;

	while (b > 0 && myCompare(array[first + b],array[first + b - 1]) < 0) { //When the b is greater than equal 0 and comparing the array, tep variable is greater than 0
	mySwap(&array[first + b - 1], &array[first + b]);
	b--;
	}
    }
}
