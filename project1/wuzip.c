#include <stdio.h>
#include <stdlib.h>  //exit
#include <string.h> //strcpy, strcmp

int main(int argc, char *argv[]) {
	FILE *fp;
	char buff[5];

	if (argc <= 1) {
		printf("wuzip: file1 [file2 ...]\n");
		exit(1);
	}
		
	for (int i=1; i<argc; i++) {
		if ((fp = fopen(argv[i], "r")) == NULL) {
			printf("wuzip: cannot open file\n");
			exit(1);
		}
	
		int count = 0;
		while (fread(&count, 4, 1, fp)) {
			memset(buff, 0, strlen(buff));
			fread(buff, 1, 1, fp);
			for (int i=0; i<count; i++) {
				printf("%s", buff);
			}		
		}
		fclose(fp);
	}

	return 0;
}
