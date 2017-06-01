#include "interpreter.h"
extern char input[50];
extern char current_char;
extern int length_of_input;
extern Token current_token;

int visitNum(Node *node){
  // printf("%d\n", node->value);
  return node->value;
}

int visitBinOp(Node *node){
  switch(node->token.type){
    case ADD:
      return visit(node->op.left) + visit(node->op.right);
    case SUB:
      return visit(node->op.left) - visit(node->op.right);
    case MUL:
      return visit(node->op.left) * visit(node->op.right);
    case DIV:
      return visit(node->op.left) / visit(node->op.right);
  }
}
int visit(Node *node){

  switch(node->class){
    case BINOP:
      return visitBinOp(node);
    case CONSTANT:
      return visitNum(node);
  }
}

int main(int argc, char *argv[])
{
  strncpy(input, argv[1], 50);
  length_of_input = sizeof(input)/sizeof(input[0]);
	current_char = input[0];
  current_token = next_token();
  Node head = expr();
  printf("left: %d\n", head.op.left->value);
  printf("right: %d\n", head.op.right->value);

	printf("%d\n", visit(&head));
	return 0;
}
