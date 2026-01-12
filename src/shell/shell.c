#include <stdio.h>
#include <stdbool.h>

#include "../../include/shell/prompt.h"
#include "../../include/shell/shell.h"
#include "../../include/tokenizer/headers/tokenizer.h"

void start_shell(void)
{
	Arena *arena = tiltyard_create(100);

	while (1) {
		char buffer[128];
		print_prompt();
		 fgets(buffer, sizeof(buffer), stdin);

		tokenize_buffer(arena, buffer);
	}
}
