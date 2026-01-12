#include <stdio.h>

#include "../../include/shell/prompt.h"

static char *prompt = "ash.v0 $ ";

void print_prompt(void)
{
	printf("%s", prompt);
}
