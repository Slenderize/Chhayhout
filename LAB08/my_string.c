#include <stdio.h>
#include "my_string.h"
#include <stdlib.h>


struct my_string 
{
    int capacity;
    int size;
    char* data;
};
typedef struct my_string My_String;


Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	My_String* pMy_string = (My_String*)hMy_string;
	char c;
	int i;
	char* pData;
	pMy_string->size = 0;  //replace data in string if needed
	c = fgetc(fp);
	while (c == EOF || c == ' ' || c== '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r'){  // keep reading whitespace until non-whitespace is read
		if (c == EOF) {  // failure if only EOF is in file
			return FAILURE;
	    }
	    c = fgetc(fp);
	}
	while (c != ' ' && c != EOF && c!= '\n' && c != '\t' && c != '\v' && c != '\f' && c != '\r') {
		if (pMy_string->size == (pMy_string->capacity - 1)) {
			// reallocate space to fit new character
			pData = (char*) malloc((pMy_string->capacity + 1) * sizeof(char));
			if (pData == NULL) {
          	return FAILURE;
          }
          for (i = 0; i <= pMy_string->size; ++i) {
          	pData[i] = pMy_string->data[i];
          }
        // replace old data array with new one
          free(pMy_string->data);
          pMy_string->data = pData;
          pMy_string->capacity += 1;
        }
        pMy_string->data[pMy_string->size] = c;
        pMy_string->size += 1;
        c = fgetc(fp);
    }
	    if (c != EOF) {
	    	ungetc(c, fp); //puts back whitespace char
    }
  return SUCCESS;
}



Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	My_String* pMy_string = hMy_string;
	int i = 0;

	if(fp == NULL){
		printf("Failed to open the file!\n");
		return FAILURE;
	}
	while(pMy_string->data[i]  != '\0'){
		fputc(pMy_string->data[i], fp);
		i++;
	}
		return SUCCESS;

}


MY_STRING my_string_init_default(void) 

{
    My_String *pMy_string;
    pMy_string = (My_String*)malloc(sizeof(My_String));
    
	if (pMy_string !=  NULL)
    {	
	pMy_string->size = 0;
        pMy_string->capacity = 7;
        pMy_string->data = (char*)malloc(sizeof(char)*pMy_string->capacity); 
    }
        else if (pMy_string->data == NULL)
        {
            free(pMy_string->data);
            free(pMy_string);
            pMy_string = NULL;
	    printf("empty string, unable to allocate memory.");

        }

   
    return pMy_string;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
	My_String *pMy_string;
	pMy_string = (My_String*)malloc(sizeof(My_String));
	int i=0;
	while(c_string[i] != '\0')
	{
		i++;
	}
	if(pMy_string != NULL)
	{
		pMy_string->size = i;
		pMy_string->capacity = i+1;
		pMy_string->data = malloc(sizeof(char)*pMy_string->capacity);
		i=0;
		while(c_string[i] != '\0')
		{
			pMy_string->data[i] = c_string[i];
			i++;
		}
		if(pMy_string->data == NULL)
		{
			printf("Object half created");
			free(pMy_string);
			pMy_string = NULL;
			return NULL;
		}
		
	}	

	return pMy_string;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
	My_String *pLeft_string = hLeft_string;
	My_String *pRight_string = hRight_string;
	int i;
	if(pLeft_string->size > pRight_string->size)
	{
		for(i=0;i<=pLeft_string->size; i++)
		{
			if(pLeft_string->data[i] < pRight_string->data[i])
			{
				return -1;
			}
			else if(pLeft_string->data[i] > pRight_string->data[i])
			{
				return 1;
			}
		}
		return 0;
	}
	else
	{
		for(i=0;i<=pLeft_string->size; i++)
		{
			if(pLeft_string->data[i] < pRight_string->data[i])
			{
				return -1;
			}
			else if(pLeft_string->data[i] > pRight_string->data[i])
			{
				return 1;
			}
		}
		return 0;
	}
}


int my_string_get_size(MY_STRING hMy_string)
{
    My_String *pMy_string = (My_String*)hMy_string;
    return pMy_string->size;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
    
    My_String *pMy_string = (My_String*)hMy_string;
    
    return pMy_string->capacity;
}

void my_string_destroy(Item* phMy_string)
{
	My_String* pMy_string = (My_String*)*phMy_string;
	free(pMy_string->data);
	free(pMy_string);
	*phMy_string = NULL;
}

//---------------------------------------------------------------
Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
	int i;
	My_String* pResult = (My_String*)hResult;
	My_String* pAppend = (My_String*)hAppend;
	for(i = 0; i <= pAppend->size-1;i++){
		my_string_push_back(pResult, pAppend->data[i]);
	}
	return SUCCESS;
}


Status my_string_pop_back(MY_STRING hMy_string)
{
	My_String* pMy_string = (My_String*)hMy_string;

  if(pMy_string == NULL)
    {
      return FAILURE;
    }
  
  if(pMy_string->size <= 0)
    {
      return FAILURE;
    }
  
  pMy_string->size--;
  return SUCCESS;
}


Status my_string_push_back(MY_STRING hMy_string, char item){
	My_String* pMy_string = (My_String*)hMy_string;
  char* pTemp;
  int i;
  //If the array is filled with elements
  if(pMy_string->size == pMy_string->capacity - 1){
      //doubling the capacity
      pTemp = (char*)malloc(sizeof(char)*pMy_string->capacity * 2);
	    if(pTemp == NULL){
		  return FAILURE;
		}
     	else{
		  //Copying the data from the old array to the new array
		  for(i = 0 ; i < pMy_string->size; i++){
		      pTemp[i] = pMy_string->data[i];
		    }
		  //Do not need the old array, free the memory
		  free(pMy_string->data);
		  pMy_string->data = pTemp;
		  //Increasing the capacity of the vector
		  pMy_string->capacity *=2;
		}
    }
  //Adding the item to the end of the data array
  pMy_string->data[pMy_string->size] = item;
  //increasing the size after adding the item
  pMy_string->size += 1;
  //Successfully added the item and return
  return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index){
	My_String* pMy_string = (My_String*)hMy_string;
	if(index>pMy_string->size||index<0)
   		return NULL;
  	else {
      return &(pMy_string->data[index]);
    }
}

char* my_string_c_str(MY_STRING hMy_string)
{
	My_String* pMy_string = (My_String*)hMy_string;
	pMy_string->data[pMy_string->size] = '\0';
	return pMy_string->data;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
	My_String* pMy_string = (My_String*)hMy_string;
	if(pMy_string->size > 0){
      return FALSE;
    }
  return TRUE;
}

Status my_string_assignment(Item* pLeft, Item Right) {
  My_String* pMy_string_left = NULL;
  My_String* pMy_string_right = Right;
  int i;
  char* pData = NULL;
  if (*pLeft == NULL) {
  	pMy_string_left = (My_String*) malloc(sizeof(My_String));
    pData = (char*) malloc((pMy_string_right->capacity) * sizeof(char));
    if (pMy_string_left != NULL && pData != NULL) {
      pMy_string_left->size = pMy_string_right->size;
      pMy_string_left->capacity = pMy_string_right->capacity;
      for (i = 0; i < pMy_string_right->size; ++i) {
        pData[i] = pMy_string_right->data[i];
      }
      pMy_string_left->data = pData;
      *pLeft = pMy_string_left;
    }
    else {
      if (pMy_string_left != NULL) {
        free(pMy_string_left);
        pLeft = NULL;
        return FAILURE;
      }
      if (pData != NULL) {
        free(pData);
        pLeft = NULL;
        return FAILURE;
      }
    }
  }
  else {
    pMy_string_left = *pLeft;
    if (pMy_string_left->capacity < pMy_string_right->size) {
      pData = (char*) malloc((pMy_string_right->capacity) * sizeof(char));
      if (pData == NULL) {
        return FAILURE;
      }
      free(&pMy_string_left->data);
      pMy_string_left->data = pData;
      pMy_string_left->capacity = pMy_string_right->capacity;
    }
    pMy_string_left->size = pMy_string_right->size;
    for (i = 0; i < pMy_string_right->size; ++i) {
      pMy_string_left->data[i] = pMy_string_right->data[i];
    }
    *pLeft = pMy_string_left;
  }
  return SUCCESS;
}


Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess){

	int i;
	MY_STRING tempKey = NULL;
	Status status;
	char familyChar;
	char wordChar;
	tempKey = my_string_init_default();
	if(tempKey == NULL){
		return FAILURE;
	}
	guess = tolower(guess);
	for(i = 0; i < my_string_get_size(word); ++i){
		familyChar = tolower(*(my_string_at(current_word_family, i)));
		wordChar = tolower(*(my_string_at(word, i)));

		if(guess == wordChar){
			if(my_string_push_back(tempKey, guess) == FAILURE) {
				return FAILURE;
			}
		} else {
			if(my_string_push_back(tempKey, familyChar) == FAILURE){
				return FAILURE;
			}
		}
	}
	
	status = my_string_assignment(&new_key, tempKey);
	
	my_string_destroy(&tempKey);
	
	return status;
}
