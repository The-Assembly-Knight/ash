#pragma once

#include "../structs/token.h"
#include "../../../libs/tiltyard/include/tiltyard_API.h"

struct token *tokenize_buffer(Arena *arena, char *buffer);
