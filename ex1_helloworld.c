#include <stdio.h>                //included header file

void sayHello();                  //function prototype

void sayHello(){                  //function datatype (void), name (sayHello) and args (none)
  printf("Hello World!\n");       //calling a function with 1 arg
}

                                  //main() is the entry point to the program
int main(int arg, char* argv[]){  //function datatype (int), name (main) and args (arg and argv)
  sayHello();                     //calling a function with 0 args
  return 0;                       //returning and int
}
