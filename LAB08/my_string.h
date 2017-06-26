#include <stdio.h>
#include "generic.h"
#include "status.h"

typedef void* MY_STRING;

MY_STRING my_string_init_default(void);

void my_string_destroy(Item* phMy_string);

MY_STRING my_string_init_c_string(const char* c_string);

int my_string_get_capacity(MY_STRING hMy_string);

int my_string_get_size(MY_STRING hMy_string);

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

Status my_string_insertion(MY_STRING hMy_string, FILE* fp);

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend);

Status my_string_pop_back(MY_STRING hMy_string);

Status my_string_push_back(MY_STRING hMy_string, char item);

char* my_string_at(MY_STRING hMy_string, int index);

char* my_string_c_str(MY_STRING hMy_string);

Boolean my_string_empty(MY_STRING hMy_string);

//Precondition: pLeft is the address of a MY_STRING handle 
//   containing a valid MY_STRING object address OR NULL.
//   The value of Right must be the handle of a valid MY_STRING object
//Postcondition:  On Success pLeft will contain the address ofa handle
//   to a valid MY_STRING object that is a deep copy of the object indicated
//   by Right.  If the value of the handle at the address indicated by
//   pLeft is originally NULL then the function will attempt to initialize
//   a new object that is a deep copy of the object indicated by Right, 
//   otherwise the object indicated by the handle at the address pLeft will
//   attempt to resize to hold the data in Right.  On failure pLeft will be
//   left as NULL and any memory that may have been used by a potential
//   object indicated by pLeft will be returned to the freestore.
Status my_string_assignment(Item* pLeft, Item Right);

//Precondition:current_word_family, new_key and word are all handles to valid
//   MY_STRING opaque objects.  guess is an alphabetical character that can be either
//   upper or lower case.
//Postcondition:  Returns SUCCESS after replacing the string in new_key with the key
//   value formed by considering the current word family, the word and theguess.
//   Returns failure in the case of a resizing problem with the new_key string.
Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess);
