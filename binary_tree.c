#include <stdio.h>
#include <stdlib.h>

typedef struct Leaf {
	int data;
	struct Leaf *left;
	struct Leaf *right;
} Leaf;

void insert(int data, Leaf *trunk){
  if(data>trunk->data){
    if(trunk->right==NULL){
      trunk->right = malloc(sizeof(Leaf));
      trunk->right->data = data;
      return;
    }
    insert(data, trunk->right);
  }
  else{
    if(trunk->left==NULL){
      trunk->left = malloc(sizeof(Leaf));
      trunk->left->data = data;
      return;
    }
    insert(data, trunk->left);
  }
}

int depth(Leaf *trunk){
  if(!trunk){
		// printf("end\n");
		return 1;
	}
	int left = 0;
	int right = 0;
	if(trunk->left){
		// printf("left\n");
		left = depth(trunk->left)+1;
	}
	if(trunk->right){
		// printf("right\n");
		right = depth(trunk->right)+1;
	}
	if (left>right){
		// printf("left is bigger\n");
		return left;
	}
	if(right>left){
		// printf("right is bigger\n");
		return right;
	}
}
void delete(int todelete, Leaf *trunk){
	if(todelete>trunk->data){
		printf("%s\n", "right");
		if(todelete==trunk->right->data){
			printf("%d\n", trunk->right->data);
			Leaf *toremove = trunk->right;
			// printf("%d\n", toremove->left->data);
			trunk->right = toremove->left;
			trunk->right->right = toremove->right;
			// free(toremove);

		}
		delete(todelete, trunk->right);
	}
	else if (todelete<trunk->data){
		printf("%s\n", "left");
		if(todelete==trunk->left->data){
			printf("%s\n", "deleting left");
			Leaf *toremove = trunk->left;
			// free(trunk->left);
			trunk->left = toremove->right;
			trunk->left->left = toremove->left;
			// free(toremove);
		}
		delete(todelete, trunk->left);
	}
}
int lookup(int tofind, Leaf *trunk){
	if(trunk->data > tofind){
		lookup(tofind, trunk->left);
	}
	else if(trunk->data < tofind){
		lookup(tofind, trunk->right);
	}
	else if(trunk->data == tofind){
		return 1;
	}
	else{
		return 0;
	}

}
int main(){
  Leaf *trunk = malloc(sizeof(Leaf));
  trunk->data = 10;
  insert(11, trunk);
	insert(12, trunk);
	insert(13, trunk);

  // printf("%d\n", trunk->left->left->left->data);
	printf("%d\n", depth(trunk));
	delete(12, trunk);


  return 0;
}
