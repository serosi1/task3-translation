#include <stdio.h>
#include "stdlib.h"
#include <string.h>

int main(int argc, char **argv) {
	FILE *file;
	char arr[50]; 
	char *set1 = argv[1];
	char *set2 = argv[2];
	int i = 0;
	if (argc == 4) file = fopen(argv[3], "r");
	else {
		char *txt;
		scanf("%s", txt); 
		file = fopen(txt, "r");
	}
	while ((arr[i] = getc(file)) != EOF) {
		for (int j = 0; set1[j] != '\0'; j++) {
			if (arr[i] == set1[j]) arr[i] = set2[j];
		}
		if (arr[i] == '\n') {
			arr[i] = '\0';
			printf("%s\n", arr);
			i = 0;
		} 
		else i++;
	}
	arr[i] = '\0';
	printf("%s", arr);
	fclose(file);

	return 0;
}
