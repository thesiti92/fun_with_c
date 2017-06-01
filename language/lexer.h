
typedef enum Type{
	ADD, SUB, MUL, DIV, INT, LPAREN, RPAREN, EOS
} Type;

typedef struct Token {
	int value;
  Type type;
} Token;

Token next_token();
int integer();
void advance();
