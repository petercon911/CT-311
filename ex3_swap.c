#include <stdio.h>
#include <string.h>

void swap(int* x, int* y);
void generic_swap(void* x, void* y, int size);

void swap(int* x, int* y){  //accepts the pointer to x and the pointer to y
                            //"turn pointer into value with *p"
  int temp = *x;            //therefore temp is the value at x
  *x = *y;                  //the value at x = the value at y
  *y = temp;                //the value at y = temp
}

void generic_swap(void* vp1, void* vp2, int size){
  //see note 1 below
  char temp_buff[size];
  memcpy(temp_buff, vp1, size);
  memcpy(vp1, vp2, size);
  memcpy(vp2, temp_buff, size);
}

int main(int arg, char* argv[]){
  int first_int = 8;
  int second_int = 4;
  printf("The first number is %d\n", first_int);
  printf("The second number is %d\n", second_int);
  printf("<->\n");
  swap(&first_int, &second_int);
  printf("The first number is %d\n", first_int);
  printf("The second number is %d\n", second_int);

  char first_str[10] = "Hello";     //Note, we explicitly set the length of the char array
  char second_str[10] = "world!";   //What if we used char* second_str = "world?";
                                    //second_str would be a pointer, and it's size would
                                    //not be the same as the size of the text...
                                    //see note 1 below
  printf("The first string is %s\n", first_str);
  printf("The second string is %s\n", second_str);
  printf("<->\n");
  generic_swap(&first_str, &second_str, sizeof(first_str));
  printf("The first string is %s\n", first_str);
  printf("The second string is %s\n", second_str);

  //see Note 1 below
  /*
  char* first_str1 = "world!";
  printf("%ld, %ld\n", sizeof(first_str), sizeof(first_str1));
  */

  return 0;
}

/*
Note 1:
Q: Why do we pass in the size of the string to the generic_swap function?
A: Because memcpy needs to know how many bytes to copy.

Q: Why don't we just call sizeof() from inside the generic_swap function
   and save ourselves the hassle of adding an extra argument every time?
A: Because vp1 and vp2 (void pointers) are simply pointers, with no size:
      - calling sizeof(vp1) would give us the size of the pointer, not the data.
      - sizeof(*vp1) and sizeof(*vp1) might produce different values and wont
        wont work if the string is declared without a fixed size.
        Note the difference between:

        char* first_str = "Hello";
        and
        char first_str[10] = "Hello";

        char* is a pointer to the array ['H','e','l','l','o',\0]
            size of a pointer = 8 bytes
        char x[10] is a pointer to the array ['H','e','l','l','o',\0,_,_,_,_]
            size of a char*10= 10 bytes
            where underscore is not defined, but allocated to the array.

        Try uncommenting the code block at the end of main() to see this in action.
*/
