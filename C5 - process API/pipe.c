#include <stdio.h>
#include <stdlib.h> //exit
#include <string.h> //strlen
#include <sys/wait.h> //waitpid
#include <unistd.h> //fork, pipe, close, write

int main() {
	printf("Before fork() (pid:%d)\n",(int) getpid());

	int fd[2];
	char buf;
	if (pipe(fd) == -1) {
		perror("pipe");
		exit(1);
	}
	
	pid_t rc[2];
	rc[0] = fork();

	if (rc[0] <0) {
		// fork failed
		printf("fork failed\n");
		exit(1);
	} else if (rc[0] == 0) {
		close(fd[0]); //close unused read end
		char str[] = "I am the first child";
		write(fd[1], str, strlen(str));
		close(fd[1]);  //send EOF
		waitpid(rc[1], NULL, 0);  //wait for sencond child
	} else {
		rc[1] = fork();
		if (rc[1] < 0) {
			//fork failed
			printf("fork failed\n");
			exit(1);
		} else if (rc[1] == 0) {
			close(fd[1]);  //close unsed write end
			//reads a byte at a time and echoes on standard output
			while (read(fd[0], &buf, 1) > 0) {
				write(STDOUT_FILENO, &buf, 1);
			}
			write(STDOUT_FILENO, "\n", 1);
			close(fd[0]);
		}
	} 

	printf("After fork() (pid:%d)\n",(int) getpid());
	return 0;
}
