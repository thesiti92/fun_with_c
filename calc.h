#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct Token {
	int value;
  char type[20];
} Token;

Token next_token();
int integer();
void advance();
void consume(char type[]);
int expr();
int factor();
int string_in(char *my_str, char *string_list[], size_t num_strings);
int term();
int group();
