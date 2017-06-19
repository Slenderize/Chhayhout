#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[]) {
  int i;
  //an array of MY_STRING handles with 100 elements.  each element of the array to NULL
  MY_STRING hMy_String_Array[100] = {NULL};
  // init_c_string function to initialize the first element of the array to the string “COPY ME!”
  hMy_String_Array[0] = my_string_init_c_string("COPY ME!");
  //for loop that uses your assignment function to copy the first string into every other element of the array.
  for (i = 1; i < 100; ++i) {
    my_string_assignment(&hMy_String_Array[i], hMy_String_Array[0]);
  }
  //Destroy every element of the array with a for loop calling destroy on each element but use 
 //string_insertion to print each element to the screen just before deleting it

  for (i = 0; i < 100; ++i) {

  	my_string_insertion(hMy_String_Array[i], stdout);
    printf("\n");
    my_string_destroy(&hMy_String_Array[i]);
  }
  
  return 0;
}