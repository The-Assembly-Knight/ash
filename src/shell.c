#include <stdio.h>

#include "../include/prompt.h"
#include "../include/shell.h"

void start_shell(void)
{
	char buffer[128];

	while (1) {
		print_prompt();
		fgets(buffer, sizeof(buffer), stdin);
		printf("%s", buffer);
	}
}
