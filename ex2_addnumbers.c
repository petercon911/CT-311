#include <stdio.h>

// prototype with two args and int data type
int add(int a, int b);

//defining the function
int add(int a, int b){
  return a+b;
}

int main(int arg, char* argv[]){
  printf("Let's add some numbers...\n");
  int first = 8;
  int second = 4;
  printf("The first number is %d\n", first);
  printf("The second number is %d\n", second);

  int result = add(first, second);
  printf("When we add them together we get: %d\n", result);

  return 0;
}
