#include <stdio.h>
#include <stdlib.h>  //exit
#include <string.h>  //strcmp

int main(int argc, char *argv[]) {

//	FILE *fp = NULL;
	char *line = NULL;
	size_t len = 0;	

	if (argc < 2) {
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	}	
	
	if (argc == 2) {
		FILE *fp = stdin;
		
		while (getline(&line, &len, fp) > 0) {
			if (strstr(line, argv[1])) {
			printf("%s", line);
			}

			free(line);
			fclose(fp);
		}
	} else {
			int i;
			for (i=2; i<argc; i++) {

					FILE *fp = fopen(argv[i], "r");
					if (fp == NULL) {
						perror("wgrep: cannot open file\n");
						exit(0);
					}
					
					while (getline(&line, &len, fp) > 0) {
						if (strstr(line, argv[1])) {
						printf("%s", line);
						}
					}

					free(line);
					fclose(fp);
			}
	}

	return 0;
}
