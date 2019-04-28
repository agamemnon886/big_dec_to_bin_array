#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
	int i = 0;
	char *hex = argv[1];
	unsigned char *saved_result = NULL;

	unsigned char *result = calloc(strlen(hex) * 4, sizeof(unsigned char));
	if(result == NULL) {
		perror("calloc");
		return 1;
	}

	while(*hex) {
		int c = toupper(*hex);
		switch (c) {
			case '0':
				result[i] = 0;
				result[i+1] = 0;
				result[i+2] = 0;
				result[i+3] = 0;
				break;

			case '1':
				result[i] = 0;
				result[i+1] = 0;
				result[i+2] = 0;
				result[i+3] = 1;
				break;

			case '2':
				result[i] = 0;
				result[i+1] = 0;
				result[i+2] = 1;
				result[i+3] = 0;
				break;

			case '3':
				result[i] = 0;
				result[i+1] = 0;
				result[i+2] = 1;
				result[i+3] = 1;
				break;

			case '4':
				result[i] = 0;
				result[i+1] = 1;
				result[i+2] = 0;
				result[i+3] = 0;
				break;

			case '5':
				result[i] = 0;
				result[i+1] = 1;
				result[i+2] = 0;
				result[i+3] = 1;
				break;

			case '6':
				result[i] = 0;
				result[i+1] = 1;
				result[i+2] = 1;
				result[i+3] = 0;
				break;

			case '7':
				result[i] = 0;
				result[i+1] = 1;
				result[i+2] = 1;
				result[i+3] = 1;
				break;

			case '8':
				result[i] = 1;
				result[i+1] = 0;
				result[i+2] = 0;
				result[i+3] = 0;
				break;

			case '9':
				result[i] = 1;
				result[i+1] = 0;
				result[i+2] = 0;
				result[i+3] = 1;
				break;

			case 'A':
				result[i] = 1;
				result[i+1] = 0;
				result[i+2] = 1;
				result[i+3] = 0;
				break;

			case 'B':
				result[i] = 1;
				result[i+1] = 0;
				result[i+2] = 1;
				result[i+3] = 1;
				break;

			case 'C':
				result[i] = 1;
				result[i+1] = 1;
				result[i+2] = 0;
				result[i+3] = 0;
				break;

			case 'D':
				result[i] = 1;
				result[i+1] = 1;
				result[i+2] = 0;
				result[i+3] = 1;
				break;

			case 'E':
				result[i] = 1;
				result[i+1] = 1;
				result[i+2] = 1;
				result[i+3] = 0;
				break;

			case 'F':
				result[i] = 1;
				result[i+1] = 1;
				result[i+2] = 1;
				result[i+3] = 1;
				break;

			default:
				printf("Invalid hex\n");
		}

		i += 4;
		hex++;
	}

	saved_result = result;

	while(result) {
		if(*result != 0) {
			break;
		}

		i--;
		result++;
	}

	for(int j = 0; j < i; j++) {
		printf("%hhd", result[j]);
	}
	printf("\n");

	if(saved_result != NULL) {
		free(saved_result);
	}

	return 0;
}
