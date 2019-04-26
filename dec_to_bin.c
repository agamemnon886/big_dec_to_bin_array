#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>


int main()
{
	char decimal[] = "8498193041717982719402398252390853829057214352898763248";

	unsigned char *bin = NULL;
	char *divisible = NULL;
	char *p_decimal = NULL;
	char *p_divisible = NULL;
	int done = 0;
	int len = 0;
	int j = 0;
	int i = 0;

	p_decimal = decimal;
	len = strlen(decimal);

	// Allocate memory for divisible
	divisible = (char *)calloc((len + 1), sizeof(char));

	// Allocate memory for binary array
	bin = (unsigned char *)calloc(len*4, sizeof(unsigned char));

	// Save pointer to divisible
	p_divisible = divisible;

	while(done != 1) {
		int quotient = 0;
		unsigned char remainder = 0;
		int division_result = 0;

		// Divide decimal string by 2
		for(i = 0; i < len; i++) {
			division_result = (quotient + p_decimal[i] - '0')/2;
			remainder = (p_decimal[i] - '0')%2;
			p_divisible[i] = division_result + '0';
			quotient = remainder * 10;
		}

		// End of string
		p_divisible[len] = '\0';

		// Remove leading zero after division if exists
		if(p_divisible[0] == '0') {
			p_divisible++;
		}

		// Compute length of string (result of division by 2)
		len = strlen(p_divisible);

		// If string if empty then break the loop
		if(len == 0) {
			done = 1;
		}

		// Store remainder into binary array
		bin[j] = remainder;

		// Increment index of binary array
		j++;

		// Set divisible to result of division
		p_decimal = p_divisible;
	}

	// Set real binary array length
	len = j;

	// Reverse binary array
	i = j - 1;
	j = 0;

	while(i > j) {
		unsigned char temp = bin[i];
		bin[i] = bin[j];
		bin[j] = temp;
		i--;
		j++;
	}


	printf("decimal = %s\n", decimal);

	printf("\nbin = ");
	for(i = 0; i < len; i++) {
		printf("%hhd", bin[i]);
	}
	printf("\n");

	free(bin);
	free(divisible);

	return 0;
}
