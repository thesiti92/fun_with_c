#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct Token {
	int value;
  char type[];
} Token;

int int_plus_int(Token *seq[], int length){
  if(length>3){
    return 0;
  }
  if(strcmp(seq[0]->type, "INTEGER")!=0){
    printf("%s\n", "error1");
    return 0;
  }
  if(strcmp(seq[1]->type, "PLUS")!=0){
    printf("%s\n", "error2");

    return 0;
  }
  if(strcmp(seq[2]->type, "INTEGER")!=0){
    printf("%s\n", "error3");

    return 0;
  }

  return 1;
}

int int_minus_int(Token *seq[], int length){
  if(length>3){
    return 0;
  }
  if(strcmp(seq[0]->type, "INTEGER")!=0){
    printf("%s\n", "error1");
    return 0;
  }
  if(strcmp(seq[1]->type, "MINUS")!=0){
    printf("%s\n", "error2");

    return 0;
  }
  if(strcmp(seq[2]->type, "INTEGER")!=0){
    printf("%s\n", "error3");

    return 0;
  }
  return 1;

}

int main(int argc, char *argv[])
{
  char input[10];
  strncpy(input, argv[1], sizeof(argv[1]));
  Token *sequence[strlen(input)];
  int seq_length = 0;
  for(int i = 0; i<strlen(input); i++){
    if(input[i] == ' '){
      continue;
    }
    if(isdigit(input[i])){
      printf("%s\n", "INTEGER");
      seq_length++;
      Token *current = malloc(sizeof(Token));
      strncpy(current->type, "INTEGER", sizeof("INTEGER"));
      current->value = input[i] - '0';
      sequence[i] = current;
    }
    if(input[i] == '+'){
      printf("%s\n", "PLUS");
      seq_length++;
      Token *current = malloc(sizeof(Token));
      strncpy(current->type, "PLUS", sizeof("PLUS"));
      sequence[i] = current;
    }
    if(input[i] == '-'){
      printf("%s\n", "MINUS");
      seq_length++;
      Token *current = malloc(sizeof(Token));
      strncpy(current->type, "MINUS", sizeof("MINUS"));
      sequence[i] = current;
    }
  }
  if(int_plus_int(sequence, seq_length)==1){
    printf("%d\n", sequence[0]->value + sequence[2]->value);
    return 0;
  }
  if(int_minus_int(sequence, seq_length)==1){
    printf("%d\n", sequence[0]->value - sequence[2]->value);
    return 0;
  }
  printf("%s\n", "error parsing input");
  return 0;
}
