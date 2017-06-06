#ifndef PARSER_H
#define PARSER_H

#define FOREACH_KEYWORD(KEYWORD) \
        KEYWORD(BEGIN)   \
        KEYWORD(END)  \

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

static const inline char *KEYWORD_STRING[] = {
    FOREACH_KEYWORD(GENERATE_STRING)
};

typedef enum Class{
	CONSTANT, BINOP, UNOP
} Class;
typedef struct Node {
	Class class;
	Token token;
	union {
		int value;
		struct {
			struct Node* left;
			struct Node* right;
		} op;
		struct Node* expr;
	};
} Node;


void consume(Type type);
Node* expr();
Node* factor();
Node* term();
Node* Num(Token token);
Node* BinOp(Token token, Node* left, Node* right);
Node* UnOp(Token op, Node* expr);

#endif
