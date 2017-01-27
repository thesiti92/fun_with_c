typedef struct{
  int data;
  struct Node *next;
} Node;
void append(Node *head, int data){
  if(head->next == NULL){
    head->next = (Node*)malloc(sizeof(Node));
    head->next->val = data;
    head->next->next = NULL;
  }
  append((head->next), data);
}
  Node head = {1, NULL};
  append(&head, 1);
}
