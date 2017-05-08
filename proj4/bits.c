

// It prints the bits in bitmap as 0s and 1s.
void printBits(unsigned int bitmap)
{
	int i = 32;
	while(i--) {
		if(bitmap & 1 << i) 
			printf("%d",1);
		else 
			printf("%d", 0);
	}
	printf("\n10987654321098765432109876543210\n");
	// Add your code here
}


// Sets the ith bit in *bitmap with the value in bitValue (0 or 1)
void setBitAt( unsigned int *bitmap, int i, int bitValue ) {
	unsigned int temp = 1 << i;
	if (bitValue)
		*bitmap = (*bitmap=((*bitmap)|temp));
	else
		*bitmap=((*bitmap)&(~temp));
	// Add your code here
}

// It returns the bit value (0 or 1) at bit i
int getBitAt( unsigned int bitmap, unsigned int i) {
	unsigned int temp= 1 << i;
	if(temp&bitmap)
		return 1;
	else 
		return 0;
	// Add your code here
}

// It returns the number of bits with a value "bitValue".
// if bitValue is 0, it returns the number of 0s. If bitValue is 1, it returns the number of 1s.
int countBits( unsigned int bitmap, unsigned int bitValue) {
	int i =0;
	unsigned int temp = 1 << i;
	int count0 = 0, count1 = 0;
	while (i++ < 32 && temp) {
		if(bitmap & temp)
			count1++;
		else
			count0++;
		temp = 1 << i;
	}
	if (bitValue)
		return count1;
	else 
		return count0;
	// Add your code here

}

// It returns the number of largest consecutive 1s in "bitmap".
// Set "*position" to the beginning bit index of the sequence.
int maxContinuousOnes(unsigned int bitmap, int * position) {
	unsigned int pattern = 5;
	int max = 0, pos = 0, temp = 0;
	while (pos++ < 32) {
		if(bitmap & 1 << pos) 
			temp++;
		else {
			if(temp > max) {
				max = temp;
				*position = pos - max;
			}
			temp = 0;
		}
	}
	// Add your code here
	return max;
}











