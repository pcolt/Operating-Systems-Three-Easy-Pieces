#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char*argv[]) {
	printf("Before fork() (pid:%d)\n",(int) getpid());

	int ParentPid = getpid();

	int rc = fork();

	int k = kill(ParentPid, SIGCONT);
	if (k != 0) {
		printf("kill failed\n");
		exit(1);
	}

	if (rc <0) {
		// fork failed
		printf("fork failed\n");
		exit(1);
	} else if (rc == 0) {
		//child 
		printf("Child (pid:%d), hello!\n",(int) getpid());
	} else {
		// parent
		printf("Parent (pid:%d) still alive, goodbye!\n",(int) getpid());
	} 

	printf("After fork() (pid:%d), goodbye!\n",(int) getpid());
	return 0;
}
