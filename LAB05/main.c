#include <stdlib.h>
#include <stdio.h>
#include "my_string.h"
//Simple.txt file includes the following sentence:
//The quick brown fox jumped over the lazy dogs.
//No spaces or newlines after that period

int main(int argc, char* argv[])
{
MY_STRING hString = NULL;
MY_STRING result = NULL;
MY_STRING read = NULL;
FILE* fp;
/**************************************************/
/***** Testing string_at and string_empty**********/
 printf("\n");
hString = string_init_c_string("Hello World!");
 printf("\n");
string_insertion(stdout,hString);
printf("String size: %d\n", string_get_size(hString));
printf("String inside hString: %s\n", string_c_str(hString));
printf("The string has letter: %c at index: 10\n", *string_at(hString,6));
printf("is the string empty:%d\n ", string_empty(hString));
printf("\n");
/**************************************************/
/****Testing string_extraction ,string_insertion***/
/*********Testing string_concat********************/
result = string_init_default();
read = string_init_default();
//printf("==========\n");
fp = fopen("simple.txt", "r");
while(string_extraction(fp,read))
{
string_concat(result,read);
string_insertion(stdout,result);
printf("\n");
}
printf("\n");
/****************************************************/
/*********Testing empty and pop_back*****************/
while(string_empty(result) == FALSE)
{
string_pop_back(result);
}
printf("The string after popping all characters:\n");
string_insertion(stdout,result);
printf("The string size: %d\n", string_get_size(result));
printf("is the string empty: %d\n", string_empty(result));
string_destroy(&result);
string_destroy(&read);
string_destroy(&hString);
return 0;
}

