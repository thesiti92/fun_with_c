#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


typedef struct Token {
	int value;
  char type[10];
} Token;

int current_pos = 0;
char current_char;
Token current_token;
int length_of_input;

Token next_token(){
  while (current_char != NULL) {
    if(input[i] == ' '){
      continue;
    }
    if(isdigit(current_char)){
      printf("%s\n", "INTEGER");
      Token *current = malloc(sizeof(Token));
      strncpy(current->type, "INTEGER", sizeof("INTEGER"));
      current->value = current_char - '0';
      return current;
    }
    if(current_char == '+'){
      printf("%s\n", "PLUS");
      Token *current = malloc(sizeof(Token));
      strncpy(current->type, "PLUS", sizeof("PLUS"));
      return current;
    }
    if(current_char == '-'){
      printf("%s\n", "MINUS");
      Token *current = malloc(sizeof(Token));
      strncpy(current->type, "MINUS", sizeof("MINUS"));
      return current;
    }
  }
}
void consume(char type[]){
  if(strcmp(current_token.type, type)==0){
    current_token = next_token();
  }
  else{
    printf("Wrong Token Type Expected\n");
  }
}
void advance(char input[]){
  current_pos++;
  if(current_pos>length_of_input){
    printf("End of Sequence\n");
    return;
  }
  current_char = input[current_pos];
}

int main(int argc, char *argv[])
{
  char input[10];
  strncpy(input, argv[1], sizeof(argv[1]));
  length_of_input = sizeof(input)/sizeof(input[0]);
}
