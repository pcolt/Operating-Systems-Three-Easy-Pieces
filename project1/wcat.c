#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	//if (argc < 2) {
	//	printf("Error: at least one argument needed\n");
	//	exit(1);
	//}	

	int i;
	for (i=1; i<argc; i++) {

			FILE *fp = fopen(argv[i], "r");
			if (fp == NULL) {
				perror("wcat: cannot open file\n");
				exit(0);
			}
			
			char str[32];
			while (fgets(str,60,fp) != NULL) {
				printf("%s", str);
			}
			
			fclose(fp);
	}

	return 0;
}
