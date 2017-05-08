
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mymemdump(FILE * fd, char * p , int len) {
    // Add your code here.
    // You may see p as an array.
    // p[0] will return the element 0 
    // p[1] will return the element 1 and so on
    
    int i;
    //fprintf(fd, "0x%016lX: ", (unsigned long) p); // Print address of the beginning of p. You need to print it every 16 bytes
	int store[16];
	int c = 0;
	int a = 0;
	int b = 0, z = len;
	for (i=0; i < len; i++) {
        c = p[i]&0xFF; // Get value at [p]. The &0xFF is to make sure you truncate to 8bits or one byte.
		store[a++] = c;
        // Print first byte as hexadecimal
		
		// Print first byte as character. Only print characters >= 32 that are the printable characters.

		if ( a == 16 ) {
			//store[a] = '\0';
			fprintf(fd, "0x%016lX: ", (unsigned long) p + b*16);
			for(int j = 0; j < a; j++)
       			fprintf(fd, "%02X ", store[j]);
			fprintf(fd, " ");
			for(int j = 0; j < a; j++)
				fprintf(fd, "%c", (store[j]>=32 && store[j]<=127)?store[j]:'.');
        	fprintf(fd,"\n");
			a = 0;
			b++;
			//p = p + 16;
        }
		
		
    }	

	if(len - b*16 != 0 && len -b*16 < 16) {
		fprintf(fd, "0x%016lX: ", (unsigned long) p + b*16);
		for(int j = 0; j < a; j++)
       		fprintf(fd, "%02X ", store[j]);
		fprintf(fd, " ");
		while(z - 16*b < 16) {
			fprintf(fd, "%s", "   ");
			z++;
		}
		for(int j = 0; j < a; j++)
			fprintf(fd, "%c", (store[j]>=32 && store[j] <= 127)?store[j]:'.');
		fprintf(fd, "\n");
	}

}






	/*for (i=0; i < len; i++) {
        int c = p[i]&0xFF; // Get value at [p]. The &0xFF is to make sure you truncate to 8bits or one byte.

        // Print first byte as hexadecimal
        fprintf(fd, "%02X ", c);

		// Print first byte as character. Only print characters >= 32 that are the printable characters.
        fprintf(fd, "%c", (c>=32)?c:'.');

		if (i % 16 == 0 ) {
        	fprintf(fd,"\n");
        }

    }*/
