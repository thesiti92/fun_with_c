#include "interpreter.h"
extern char input[50];
extern char current_char;
extern int length_of_input;
extern Token current_token;


int main(int argc, char *argv[])
{
  strncpy(input, argv[1], 50);
  length_of_input = sizeof(input)/sizeof(input[0]);
	current_char = input[0];
  current_token = next_token();
	expr();
	return 0;
}
