#include <stdlib.h>
#include <stdio.h>
#include "my_string.h"
//Simple.txt file includes the following sentence:
//The quick brown fox jumped over the lazy dogs.
//No spaces or newlines after that period

int main(int argc, char* argv[])
{

 MY_STRING heMy_string = NULL;
 MY_STRING hrMy_string = NULL;
 MY_STRING hMy_string = NULL;

 hMy_string = my_string_init_default();
 heMy_string = my_string_init_c_string("From the window...A");

 my_string_insertion(heMy_string, stdout);
 printf("\n");

 hrMy_string = my_string_init_c_string("To the wall!");

 my_string_insertion(heMy_string, stdout);
 printf("\n");
 my_string_pop_back(heMy_string);
 printf("\n");
 my_string_concat(heMy_string,hrMy_string);
 my_string_insertion(heMy_string, stdout);
 printf("\n");

 if(my_string_empty(heMy_string)==TRUE)
 {
   printf("true");
 }
 else{
   printf("false");
 }
 printf("\n");
 if(my_string_empty(hMy_string)==TRUE)
 {
   printf("true");
 }
 else{
   printf("false ");
 }
 printf("\n");
 my_string_destroy(&hMy_string);
 my_string_destroy(&hrMy_string);
 my_string_destroy(&heMy_string);





 return 0;
}

