#include <stdio.h>
// a rudimentary calculator

int main() {
	int day, month, year;
	char monthname[20];
	char *line = NULL;
	size_t size = 0;

	while (getline(&line, &size, stdin) > 0) {
   		if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
			printf("valid: %s\n", line);  		// 30 Nov 1993 form
		else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
			printf("valid: %s\n", line);  		// mm/dd/yy form
		else
			printf("invalid: %s\n", line); 		// invalid form
	}		

	return 0;
}
