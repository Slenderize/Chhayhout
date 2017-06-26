#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"
#include "status.h"
#include "my_string.h"
int main(int argc, char* argv[])
{
  /*G_VECTOR hVector[30] = { NULL };
  MY_STRING hMy_string = NULL;
  FILE* fp = NULL;
  int i;
  


  hMy_string = my_string_init_default();// initializing a test string
  if (hMy_string == NULL){
    printf("Fail to allocate in memory\n");
    exit(1);
  }


    // open the  dictionary file
  fp = fopen("dictionary.txt", "r");
  if (fp == NULL) {
    printf("Did not open file\n");
    exit(1);
  }

  
  //generic vector of 30 arrays
  for (i = 0; i < 30; i++) {
    hVector[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
    if (hVector[i] == NULL) {
      printf("Vector not created\n");
      exit(1);
    }
  }


 // extract the data into the generic vector
  while(my_string_extraction(hMy_string, fp) == SUCCESS) {
    if (my_string_get_size(hMy_string) < 30) {
      generic_vector_push_back(hVector[my_string_get_size(hMy_string)], hMy_string);
    }
  }
  // printing out 
  for (i = 0; i < 30; i++) {
    printf("The number of words in the dictionary with %d characters is: %d\n", i, generic_vector_get_size(hVector[i]));
  }

  // destroying the vector
  for (i = 0; i < 30; i++) {
    generic_vector_destroy(&(hVector[i]));
  }
  

  fclose(fp);// closing file
  my_string_destroy(&hMy_string);// elemination of hMy_string */

  MY_STRING string1 = my_string_init_c_string("The");
  MY_STRING oldKey1 = my_string_init_c_string("---");
  MY_STRING newKey1 = my_string_init_default();

  MY_STRING string2 = my_string_init_c_string("Truck");
  MY_STRING oldKey2 = my_string_init_c_string("-----");
  MY_STRING newKey2 = my_string_init_default();

  MY_STRING string3 = my_string_init_c_string("happy");
  MY_STRING oldKey3 = my_string_init_c_string("--ppy");
  MY_STRING newKey3 = my_string_init_default();

  MY_STRING string4 = my_string_init_c_string("awesome");
  MY_STRING oldKey4 = my_string_init_c_string("--e---e");
  MY_STRING newKey4 = my_string_init_default();

  get_word_key_value(oldKey1, newKey1, string1, 'T');
  get_word_key_value(oldKey2, newKey2, string2, 'r');
  get_word_key_value(oldKey3, newKey3, string3, 'h');
  get_word_key_value(oldKey4, newKey4, string4, 'z');


  printf("%s\n", my_string_c_str(newKey1));
  printf("%s\n", my_string_c_str(newKey2));
  printf("%s\n", my_string_c_str(newKey3));
  printf("%s\n", my_string_c_str(newKey4));

  my_string_destroy(&string1);
  my_string_destroy(&string2);
  my_string_destroy(&string3);
  my_string_destroy(&string4);
  my_string_destroy(&oldKey1);
  my_string_destroy(&oldKey2);
  my_string_destroy(&oldKey3);
  my_string_destroy(&oldKey4);
  my_string_destroy(&newKey1);
  my_string_destroy(&newKey2);
  my_string_destroy(&newKey3);
  my_string_destroy(&newKey4);


  return 0;
} 
