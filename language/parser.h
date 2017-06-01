

typedef enum Class{
	CONSTANT, BINOP
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
	};
} Node;


void consume(Type type);
Node expr();
Node factor();
Node term();
Node Num(Token token);
Node BinOp(Token token, Node left, Node right);
