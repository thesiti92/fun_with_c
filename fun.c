#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d, ", arr[i]);
  }
  printf("\n");
}
int fib(int num){
  if (num==1||num==0){
    return 1;
  }
  return fib(num-1) + fib(num-2);
}

int main() {


  int arr[] = {1,2,3,4,5,6,3};
  // printArr(arr, 7);
  printf("%d\n", fib(5));
  return 0;
}

//TODO: linked list(struct),
