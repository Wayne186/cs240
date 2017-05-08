
#include <stdio.h>

#include "array.h"

// Return sum of the array
double sumArray(int n, double * array) {
  double sum = 0;
  
  double * p = array;
  double * pend = p+n;

  while (p < pend) {
    sum += *p;
    p++;
  }

  return sum;
}

// Return maximum element of array
double maxArray(int n, double * array) {
	double i = *array;
	double * p = array;
	double * pend = p+n;

	while (p < pend) {
		if(i < *p)
			i = *p;
		p++;
	}
	return i;
}

// Return minimum element of array
double minArray(int n, double * array) {
	double i = *array;
	double * p = array;
	double * pend = p+n;

	while (p < pend) {
		if(i > *p)
			i = *p;
		p++;
	}
	return i;
}

// Find the position int he array of the first element x 
// such that min<=x<=max or -1 if no element was found
int findArray(int n, double * array, double min, double max) {
	int i = 0;
	double * p = array;
	double * pend = p+n;

	while (p < pend) {
		if (*p <= max && *p >= min)
			break;
		i++;
		p++;
	}

	return i;
}

// Sort array without using [] operator. Use pointers 
// Hint: Use a pointer to the current and another to the next element
int sortArray(int n, double * array) {
	double temp;

	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(*(array + j) > *(array + j + 1)) {
				temp = *(array + j);
				*(array+j) = *(array+j+1);
				*(array+j+1) = temp;
			}
		}
	}
	
	return 1;
}

// Print array
void printArray(int n, double * array) {
	int i = 0;
	double * p = array;
	double * pend = p+n;
	
	while(p < pend) printf("%d:%f\n", i++, *p++);
	
}

