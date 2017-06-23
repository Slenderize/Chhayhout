#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"
#include "status.h"
#include "my_string.h"
int main(int argc, char* argv[])
{
// 	MY_STRING hMy_string = NULL;
// 	FILE* fp;
// 	MY_STRING hMy_string_second = NULL;
// 	int i;
// 	hMy_string = my_string_init_default();
// 	fp = fopen("dictionary.txt", "r");


// 	fclose(fp);
// 	return 0;
 
 G_VECTOR hVector[30] = { NULL };
 MY_STRING test1 = NULL;

 FILE* fp = NULL;
 int i;
 test1=my_string_init_default();// initializing a test string
 if (test1 == NULL)
  {
    printf("String not saved in memory\n");
    exit(1);
  }
  // creating generic vector of 30 arrays
  for (i = 0; i < 30; i++) 
  {
    hVector[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
    if (hVector[i] == NULL) 
	{
      printf("Vector not created\n");
      exit(1);
    }
  }
  // reading open the  dictionary file
  fp = fopen("dictionary.txt", "r");
  if (fp == NULL) 
  {
    printf("Did not open file\n");
    exit(1);
  }

// to extract the data into the generic vector
  while(my_string_extraction(test1, fp) == SUCCESS) 
  {
    if (my_string_get_size(test1) < 30) {
      generic_vector_push_back(hVector[my_string_get_size(test1)], test1);
    }
  }
  // printing out the number of each of the words with the same number of letters
  for (i = 0; i < 30; i++) 
  {
    printf("The number of words in the dictionary with %d characters is: %d\n", i, generic_vector_get_size(hVector[i]));
  }

  // destroying the vector
  for (i = 0; i < 30; i++) 
  {
    generic_vector_destroy(&(hVector[i]));
  }
  fclose(fp);// closing file
  my_string_destroy(&test1);// elemination of test1 



  return 0;
} 
