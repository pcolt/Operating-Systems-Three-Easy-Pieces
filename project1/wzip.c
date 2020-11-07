#include <stdio.h>
#include <stdlib.h>  //exit
#include <string.h> //strcpy, strcmp

int main(int argc, char *argv[]) {
	FILE *fp;
	char buff[2], oldBuff[2];
	int count;

	if (argc <= 1) {
		printf("wzip: file1 [file2 ...]\n");
		exit(1);
	}
		
	for (int i=1; i<argc; i++) {
		if ((fp = fopen(argv[i], "r")) == NULL) {
			printf("Wzip: cannot open file\n");
			exit(1);
		}
	
		while (fread(buff, 1, 1, fp)) {
			if (strcmp(buff, oldBuff) == 0) {
				count++;	
			} else {
				if (oldBuff[0] != '\0') {
					fwrite(&count, 4, 1, stdout);
					fwrite(&oldBuff, 1, 1, stdout);
				}	
				count = 1;
				strcpy(oldBuff, buff);
			}
		}
		fclose(fp);
	}
	fwrite(&count, 4, 1, stdout);
	fwrite(&oldBuff, 1, 1, stdout);

	return 0;
}
