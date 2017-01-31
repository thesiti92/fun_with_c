#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void append(Node *head, int data) {
  if (head->next == NULL) {
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = data;
    head->next->next = NULL;
  }
  else {
    append(head->next, data);
  }
}

void print_list(Node *head) {
  printf("%d", head->data);
  while (head->next != NULL) {
    head = head->next;
    printf(", %d", head->data);
  }
  printf("\n");
}

// Find an email in the linked list and return it
// If not found, return NULL
Node* find(Node *head, int data) {
  while(head!=NULL){
    if(head->data==data){
      return head;
    }
    head = head->next;
  }
  return NULL;
}

// Remove a specified elment if in the list and return it
// if not found, return -1
int deleteElement(Node **head, int data) {
  if((*head)->data == data){
    Node *todelete = *head;
    *head = (*head)->next;
    free(todelete);
    return 1;
  }
  while((*head)->next != NULL){
    if((*head)->next->data == data){
      Node *todelete = (*head)->next;
      (*head)->next = (*head)->next->next;
      free(todelete);
      return 1;
    }
    *head = (*head)->next;
  }
  return -1;
}

// Remove last element from the list and return it
Node* pop(Node *head) {
  while(head->next->next != NULL){
    head = head->next;
  }
  Node *toreturn = head->next;
  head->next = NULL;
  return toreturn;
}
//
// // Add element to end of list
// // yes this is the same as append...
void push(Node *head, int data) {
  append(head, data);
}
//
// // delete the whole linked list
// // be careful!
void deleteList(Node *head) {
  Node *next;
  while(head->next!=NULL){
    next = head->next;
    free(head);
    head = next;
  }
  free(head);
}


int main(){
  Node *head = malloc(sizeof(Node));
  head->data = 1;
  append(head, 2);
  append(head, 3);
  printf("%d\n", find(head, 3)->data);
  // delete(&head);
  print_list(head);
  // head = NULL;
  return 0;
}
