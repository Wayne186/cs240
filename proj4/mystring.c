
#include <stdlib.h>
#include "mystring.h"

int mystrlen(char * s) {
	int i = 0;	
	while(*s++ != '\0')
		i++;
	return i;
}

char * mystrcpy(char * dest, char * src) {
	char * temp = dest;	
	while(*src != '\0') { 
		*temp++ = *src++;
	}
	*temp = '\0';
	return dest;
}

char * mystrcat(char * dest, char * src) {
	char* temp = dest;
	int i = mystrlen(dest);
	while( i-- > 0) temp++; 
	while(*src != '\0') *temp++ = *src++;
	*temp = '\0';
	return dest;
}

int mystrcmp(char * s1, char * s2) {
	int i = mystrlen(s1);
	int k = mystrlen(s2);
	if (i < k) {
		return -1;
	}
	else if (i == k) {
		return 0;
	}
	else {
		return 1;
	}
}

char * mystrstr(char * hay, char * needle) {
	char * tempHay = hay;
	char * tempN = needle;

	while(*tempHay != '\0') {
		hay = tempHay;
		needle = tempN;
		while(*needle != '\0' && *needle == *hay) {
			needle++;
			hay++;
		}
		if(*needle == '\0')
			return tempHay;
		tempHay++;
	}
}

char * mystrdup(char * s) {
	if ( s == NULL ) {
		return NULL;
	}
	char * out = malloc(mystrlen(s) + 1);
	mystrcpy(out,s);
	return out;
}

char * mymemcpy(char * dest, char * src, int n)
{
	if(n){
		n++;
		while(--n > 0)	*dest++ = *src++;
	}
	return dest;
}

