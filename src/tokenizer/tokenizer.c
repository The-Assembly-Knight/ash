#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../../include/tokenizer/headers/tokenizer.h"
#include "../../include/tokenizer/structs/input_buffer.h"
#include "../../include/tokenizer/headers/byte_type.h"
#include "../../include/helpers/handle_error.h"

static void increase_buffer_index(struct input_buffer *input_buffer)
{
	if (input_buffer->index >= input_buffer->length)
		warning("index of input_buffer surpassed buffer length");
	input_buffer->index++;
}

static void handle_regular_byte(struct input_buffer *input_buffer, struct token *token)
{
	if (token->length == 0)
		token->start = input_buffer->index;

	token->length++;
	increase_buffer_index(input_buffer);
}

static void handle_delimiter_byte(struct input_buffer *input_buffer, struct token *token,
				  bool *token_ended)
{
	if (token->length == 0)
		*token_ended = true;
	else
		*token_ended = true;

	increase_buffer_index(input_buffer);
}

static void handle_byte(struct input_buffer *input_buffer, struct token *token,
		enum byte_type byte_type, bool *token_ended)
{
	switch (byte_type) {
	case BYTE_REGULAR:
		handle_regular_byte(input_buffer, token);
		return;
	case BYTE_DELIMITER:
		handle_delimiter_byte(input_buffer, token, token_ended);
		return;
	case BYTE__UNKNOWN:
	case BYTE__INVALID:
		fatal_error("byte passed to handle_byte is UNKNOWN/INVALID");
	}
}

static struct token get_next_token(struct input_buffer *input_buffer)
{
	struct token token = {0};

	bool token_ended = false;
	while (!token_ended) {
		char byte = input_buffer->buffer[input_buffer->index];
		enum byte_type byte_type = get_byte_type(byte);
			
		handle_byte(input_buffer, &token, byte_type, &token_ended);
		printf("current byte: %c\n", byte);
	}
	
	return token;
}

struct token *tokenize_buffer(Arena *arena, char *buffer)
{
	if (!arena)
		fatal_error("arena pointer passed to tokenize_buffer is NULL");
	
	struct input_buffer input_buffer = {
		.length = strlen(buffer),
		.index = 0,
		.buffer = buffer,
	};

	struct token first_argument = get_next_token(&input_buffer);

	printf("first arg length: %zu\n", first_argument.length);
	printf("first arg start: %zu\n" , first_argument.start);
	return NULL;
}
