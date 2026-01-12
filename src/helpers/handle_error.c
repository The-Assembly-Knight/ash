#include <stdio.h>
#include <stdlib.h>

#include "../../include/helpers/handle_error.h"

void fatal_error(const char *msg)
{
	fprintf(stderr, "FATAL ERROR: %s\n", msg);
	abort();
}

void warning(const char *msg)
{
	fprintf(stderr, "WARNING: %s\n", msg);
}
