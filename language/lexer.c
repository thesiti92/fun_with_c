#include "interpreter.h"
int current_pos = 0;
char current_char;
long length_of_input;
char * buffer;


Token next_token(){
  if(isdigit(current_char)){

    Token current;
    current.type = INT;
    current.value = integer();
    return current;
  }
  else if(current_char == '+'){
		advance();
    Token current;
    current.type = ADD;
    return current;
  }
  else if(current_char == '-'){
		advance();
    Token current;
    current.type = SUB;
    return current;
  }
	else if(current_char == '*'){
		advance();
		Token current;
    current.type = MUL;
		return current;
	}
	else if(current_char == '/'){
		advance();
		Token current;
    current.type = DIV;
		return current;
	}
  else if(current_char == '('){
    advance();
    Token current;
    current.type = LPAREN;
    return current;
  }
  else if(current_char == ')'){


    advance();
    Token current;
    current.type = RPAREN;
    return current;
  }

  Token current;
  current.type = EOS;
  return current;

}
int integer(){
	char result[10] = "";
	while(isdigit(current_char)){
		strncat(result, &current_char,1);
		advance();
	}
	return atoi(result);
}
void advance(){
  current_pos++;
  if(current_pos>length_of_input){
    printf("End of Sequence\n");
    return;
  }

  current_char = buffer[current_pos];
}
