#include <stdio.h>		//printf, scanf
#include <string.h> 	//strcmp
#include <unistd.h>		//exec, chdir
#include <sys/wait.h>	//waitpid

int main() {
	char command[16];
	char path[32] = "/bin/";
	
	while(1) {
		printf("wish> ");
		scanf("%s", command);

		// check for built-in commands
		// exit
		if (strcmp(command, "exit") == 0) {
			return 0;
		}
		// cd
		else if (strcmp(command, "cd") == 0 ){
			printf("running cd\n");
			if (chdir("..") == -1)
				printf("directory not found");
		}

		// not built-in commands
		else {
				printf("running %s\n", command);
				// fork a child process
				int pid = fork();
				if (pid == -1) {
					printf("fork failed");
				} else if (pid == 0) {
					// execute command from Path
					// copy current path
					char pathCommand[32];
					strcpy(pathCommand, path);
					// concatenate path + command
					strcat(pathCommand, command);
					// execute command
					char *args[] = {pathCommand, NULL};
					if (execvp(args[0],args) == -1) {
						printf("Execution of %s failed\n", command);
						return(0);
					};
				} else {
					// parent process waits for child process to end
					waitpid(pid, NULL, 0);
				}
		}
	}	//end of while
}	
