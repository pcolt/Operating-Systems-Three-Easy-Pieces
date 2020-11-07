#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[]) {

	int file = open("./file", O_CREAT|O_RDWR|O_TRUNC, S_IRWXU);
	if (file < 0) {
		// opening failed
		printf("opening failed\n");
		exit(1);
	} 
	write(file, "Hello, world!\n", strlen("Hello, world!\n"));

	printf("Before fork() (pid:%d)\n",(int) getpid());
	int rc = fork();
	if (rc <0) {
		// fork failed
		printf("fork failed\n");
		exit(1);
	} else if (rc == 0) {
		//child 
		write(file, "child writes\n", strlen("child writes\n"));
		printf("child (pid:%d), file descriptor: %d\n",(int) getpid(), file);
	} else {
		// parent
		write(file, "parent writes\n", strlen("parent writes\n"));
		printf("parent (pid:%d), file descriptor: %d\n",(int) getpid(), file);
	} 

	FILE *fp;
	fp = fopen("./file", "r");
	int ch;
	printf("reading: \n");
	while ((ch = fgetc(fp)) != EOF)
		printf("%c", ch);
	printf("-\n");
	fclose(fp);

	close(file);

	return 0;
}
