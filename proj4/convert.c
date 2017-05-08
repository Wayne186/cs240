

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int toInt(char* str) {
	//A helper function that convert a string to a integer
	int i, len, dec = 0;
	len = strlen(str);
	for( i = 0; i < len; i++) dec = dec * 10 + (str[i] - '0');
	return dec;
}

int power(int x, int y) {
	//A helper function the do the power calculation
	if(y == 0) return 1;
	int i = 0;
	int z = 1;
	while(i < y) { 
		z = z * x; 
		i++;
	}
	return z;
}

char * conv(int base, int to, char* in) {
	//the function that convert number between decimal and other base number
	char *store = (char *)malloc(50);;
	char *out = (char *)malloc(50);;
	int j;
	if(base == 10) {
		//Handle the numbers with base as 10
		int i = 0;
		int num = toInt(in);
		store[0] = '\0';
		while (num / to != 0) {
			j = num % to;
			if(j < 11) store[i++] = j + '0';
			else store[i++] = j - 10 + 'A';
			num = num / to;
		}
		j = num % to;
		if(j < 10) store[i++] = j + '0';
		else store[i++] = j - 10 + 'A';
		store[i] = '\0';
	}
	else {
		//handel other cases
		int len = strlen(in) - 1;
		int x = 0;
		int number = 0;
		int digit;

		//The while loop that convert the string to decimal integer
		while(in[x] != '\0'){
			if(in[x] >= '0' && in[x] <= '9') {
				digit = in[x] - '0';
				if(digit > base) {
					printf("Wrong digit in number.\n");
					exit(0);
				}
				number = number + digit * power(base, len--);
			}
			else {
				digit = in[x] - 'A' + 10;
				if(digit > base) {
					printf("Wrong digit in number.\n");
					exit(0);
				}
				number = number + digit * power(base, len--);
			}
			x++;
		}
		int k = 0;
		int dec = 0, temp1 = number, temp2;
		//see how many digit the number has
		while (temp1 / 10 != 0) { 
			temp1 = temp1 / 10;
			dec++;
		}
		//convert the number and store it in store
		while (number / 10 != 0) {
			temp2 = number / power(10, dec);
			store[k++] = temp2 + '0';
			number = number - temp2 * power(10, dec--);
		}
		temp2 = number / power(10, dec);
		store[k++] = temp2 + '0';
		number = number - temp2 * power(10, dec--);
		store[k] = '\0';
		return store;
	}
	int m = strlen(store)-1, n = 0;
	while(m > -1) out[n++] = store[m--];
	return out;
}

void main(int argc, char *argv[]) {
	
	if(argc != 4) { 
		printf("Usage:  convert <basefrom> <baseto> <number>\n");
		exit(0);
	}

	int base = toInt(argv[1]);
	int to = toInt(argv[2]);
	char *num = argv[3];

	printf("Number read in base %d: %s\n", base, num);

	char * toTen = conv(base, 10, num);
	char * result = conv(10, to, toTen);
	printf("Converted to base 10: %s\n", toTen);
	printf("Converted to base %d: %s\n", to, result);
	
	
	
	exit(1);

}














