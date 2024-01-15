#include "mySort.h"
#include "metrics.h"
#include <stdio.h>
#include <stdlib.h>
 
void merge(int arr[], int l, int m, int r) {
    int a, b, c;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
  
    for (a = 0; a < n1; a++)
        myCopy(&arr[l+a], &L[a]);
        
    for (b = 0; b < n2; b++)
        myCopy(&arr[m+1+b], &R[b]);

    a = 0; // First subarray
    b = 0; // Second subarray
    c = l; // Merged subarray

    while (a < n1 && b < n2) {
	if (myCompare(L[a], R[b]) <= 0) {
	   arr[c] = L[a];
           myCopy(&L[a], &arr[c]);
           a++;

    	} else {
           myCopy(&R[b], &arr[c]);
           b++;
       }
       c++;
   }

   while (a < n1) {
       myCopy(&L[a], &arr[c]);
       a++;
       c++;
   }

   while (b < n2) {
       myCopy(&R[b], &arr[c]);
       b++;
       c++;
    }
}

void mySort(int array[],unsigned int first, unsigned int last) {
    if (first < last) {
      int m = first + (last - first) / 2;
      mySort(array, first, m);
      mySort(array, m + 1, last);
      merge(array, first, m, last);
    }
}
