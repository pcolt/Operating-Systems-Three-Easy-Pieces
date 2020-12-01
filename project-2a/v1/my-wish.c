#include <stdio.h>		//printf, scanf
#include <string.h> 	//strcmp
#include <unistd.h>		//exec

int main() {
	char command[16];
	
	while(1) {
		printf("wish> ");
		scanf("%s", command);
		// check for built-in commands
		if (strcmp(command, "exit") == 0) {
			return 0;
		}
		// run not built-in commands
		printf("running %s\n", command);
		// execute command from Path
		char pathCommand[32] = "/bin/";
		strcat(pathCommand, command);
		char *args[] = {pathCommand, NULL};
		execvp(args[0],args);
	}
}
