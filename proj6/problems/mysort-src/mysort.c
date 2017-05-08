#include "mysort.h"
#include <alloca.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

//
// Sort an array of element of any type
// it uses "compFunc" to sort the elements.
// The elements are sorted such as:
//
// if ascending != 0
//   compFunc( array[ i ], array[ i+1 ] ) <= 0
// else
//   compFunc( array[ i ], array[ i+1 ] ) >= 0
//
// See test_sort to see how to use mysort.
//
typedef int (*compare_func) (void *e1, void *e2);

void mysort( int n,                      // Number of elements
	     int elementsize,            // Size of each element
	     void * array,               // Pointer to an array
	     int ascending,              // 0 -> descending; 1 -> ascending
	     CompareFunction compFunc )  // Comparison function.
{	
	// Add your code here
	void * temp = malloc(elementsize);
	int i, j;
	for(i = 0; i < n - 1; i++) {
		for(j = 0; j < n - 1 - i; j++) {
			void *e1 = (void*) ((char*)array + j * elementsize);
			void *e2 = (void*) ((char*)array + (j+1) * elementsize);
			if(ascending && ((*compFunc)(e1,e2) > 0) ) {
				memcpy(temp, e2, elementsize);
				memcpy(e2,e1,elementsize);
				memcpy(e1,temp,elementsize);
			}
			if((!ascending) && (*compFunc)(e1,e2) < 0) {
				memcpy(temp, e2, elementsize);
				memcpy(e2,e1,elementsize);
				memcpy(e1,temp,elementsize);
			}
		}
	}
	free(temp);

}


