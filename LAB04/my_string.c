#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	My_String* pMy_string = (My_String*)hMy_string;
	

	char c;
	int i = 0;
	char* pTemp;
	pMy_string->size = 0;
	

	while(fscanf(fp, "%c", &c) != EOF){
		if (i == pMy_string->capacity){
		pTemp = (char*)malloc(sizeof(char)*2*pMy_string->capacity); 
		pMy_string->capacity = pMy_string->capacity * 2;
			if (pTemp == NULL){
				printf("Failed to allocate memory to increase the capacity!");
				return FAILURE; 
			}
			else{
					for (i = 0; i < pMy_string->size; i++){  	
						pTemp[i] = pMy_string->data[i]; 
					}
				free(pMy_string->data); 
		        pMy_string->capacity = pMy_string->capacity*2;
				pMy_string->data = (char*)malloc(sizeof(char)*pMy_string->capacity); 
					
					for(i = 0; i < pMy_string->size; i++)
					{
						pMy_string->data[i] = pTemp[i];
					} 
					free(pTemp);
				}	
		}

		if((c == ' ' || c == '\n') && i != 0)
		{
			ungetc(c,fp);
			break;
		}

		if(c != ' ' && c != '\n')
		{
			pMy_string->data[i] = c;
			i++;
			pMy_string->size = i;	
		}
				
	}
		if (i == 0){
			pMy_string->size = 0;
				//printf("Failed!");
			return SUCCESS;
		}	
		pMy_string->data[i] = '\0';
		return FAILURE;
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
        pMy_string->capacity = 1;
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

void my_string_destroy(MY_STRING* phMy_string)
{
	My_String* pMy_string = (My_String*)*phMy_string;
	free(pMy_string->data);
	free(pMy_string);
	*phMy_string = NULL;
	return;
}
//---------------------------------------------------------------
Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
	int i;
	My_String* pResult = (My_String*)hResult;
	My_String* pAppend = (My_String*)hAppend;
	
	if(pResult->data == NULL || pAppend->data == NULL)
		return FAILURE;
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


Status my_string_push_back(MY_STRING hMy_string, char item)
{
	My_String* pMy_string = (My_String*)hMy_string;
  char* pTemp;
  int i;
  //If the array is filled with elements
  if(pMy_string->size >= pMy_string->capacity)
    {
      //doubling the capacity
      int double_capacity = pMy_string->capacity * 2;
      pTemp = malloc(sizeof(int)*double_capacity);
      if(pTemp == NULL)
	{
	  return FAILURE;
	}
      else
	{
	  //Copying the data from the old array to the new array
	  for(i = 0 ; i < pMy_string->size; i++)
	    {
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
  pMy_string->size++;
  //Successfully added the item and return
  return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
	My_String* pMy_string = (My_String*)hMy_string;
  if(index>pMy_string->size||index<0)
    return NULL;
  else
    {
      return &(pMy_string->data[index]);
    }
}

char* my_string_c_str(MY_STRING hMy_string)
{
	My_String* pMy_string = (My_String*)hMy_string;
  if(pMy_string->data==NULL)
    return NULL;
  else 
    return pMy_string->data;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
	My_String* pMy_string = (My_String*)hMy_string;
  if(pMy_string->size > 0)
    {
      return FALSE;
    }
  return TRUE;
}

