#pragma once

#include <stddef.h>

struct input_buffer {
	size_t length;
	size_t index;
	char *buffer;
};
