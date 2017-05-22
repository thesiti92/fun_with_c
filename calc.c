#include "calc.h"

int current_pos = 0;
char current_char;
Token current_token;
int length_of_input;
char input[10];
int num_ops = 4;
char *ops[4] = {"PLUS", "MINUS", "TIMES", "DIV"};


Token next_token(){

  if(isdigit(current_char)){
    printf("%s\n", "INTEGER");
    Token current;
    strncpy(current.type, "INTEGER", sizeof("INTEGER"));
    current.value = integer();
    return current;
  }
  else if(current_char == '+'){
		advance();
    Token current;
    strncpy(current.type, "PLUS", sizeof("PLUS"));
    return current;
  }
  else if(current_char == '-'){
		advance();
    Token current;
    strncpy(current.type, "MINUS", sizeof("MINUS"));
    return current;
  }
	else if(current_char == '*'){
		advance();
		Token current;
		strncpy(current.type, "TIMES", sizeof("TIMES"));
		return current;
	}
	else if(current_char == '/'){
		advance();
		Token current;
		strncpy(current.type, "DIV", sizeof("DIV"));
		return current;
	}

}
int integer(){
	char result[10] = "";
	while(isdigit(current_char)){
		strncat(result, &current_char,1);
		advance();
	}
	return atoi(result);
}
void consume(char type[]){
  if(strcmp(current_token.type, type)==0){
		printf("%s\n", current_token.type);
    current_token = next_token();
  }
  else{
    printf("Wrong Token Type Expected\n");
  }
}
void advance(){
  current_pos++;
  if(current_pos>length_of_input){
    printf("End of Sequence\n");
    return;
  }
  current_char = input[current_pos];
}
int factor(){
	Token current = current_token;
	consume("INTEGER");
	return current.value;
}
int term(){
	int result=factor();
	while(strcmp(current_token.type, "TIMES")==0 ||strcmp(current_token.type, "DIV")==0){
		Token op = current_token;
		if(strcmp(op.type, "TIMES")==0) {
			consume("TIMES");
			result = result * factor();
		}
		else if (strcmp(op.type, "DIV")==0) {
			consume("DIV");
			result = result / factor();
		}
	}
	return result;
}
int expr(){
	current_token = next_token();
	int result = term();
	while(string_in(current_token.type, ops, num_ops)==0){
		Token op = current_token;
		if (strcmp(op.type, "PLUS")==0) {
			consume("PLUS");
			result = result + term();
		}
		else if (strcmp(op.type, "MINUS")==0) {
			consume("MINUS");
			result = result - term();
		}
	}
	return result;
}
int string_in(char *my_str, char *string_list[], size_t num_strings){
  for (int i = 0; i < num_strings; i++)
    if (strcmp(my_str, string_list[i]) == 0 )
        return 0;
  return -1;
}
int main(int argc, char *argv[])
{
  strncpy(input, argv[1], sizeof(argv[1]));
  length_of_input = sizeof(input)/sizeof(input[0]);
	current_char = input[current_pos];
	printf("%d\n", expr());
	return 0;
}
