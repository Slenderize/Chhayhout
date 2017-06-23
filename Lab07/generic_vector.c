#include <stdlib.h>
#include <stdio.h>
#include "generic_vector.h"

struct generic_vector
{
	int size;
	int capacity;
	Item_ptr data;  //array of void pointers was void** data;(I
	Status(*item_assign)(Item_ptr, Item);// (item on left, item right) assignment can fail
	void(*item_destroy)(Item_ptr);//should know how to destroy items
};

typedef struct  generic_vector G_Vector;

G_VECTOR generic_vector_init_default(
	Status (*item_assign)(Item_ptr, Item),
	void(*item_destroy)(Item_ptr))
{
	G_Vector* pVector;
	pVector = (G_Vector*)malloc(sizeof(G_Vector));
	int i;
	if (pVector != NULL)
	{
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->item_destroy = item_destroy;
		pVector->item_assign = item_assign;
		pVector->data = (void**)malloc(sizeof(void*)*pVector->capacity); //void** address
		if (pVector->data == NULL)
		{
			//object is half created
			free(pVector);
			pVector = NULL;
		}
		else
		{
			for (i = 0; i < pVector->capacity; i++)
			{
				pVector->data[i] = NULL;
			}
		}
	}
	return pVector;
}

void generic_vector_destroy(G_VECTOR* phG_Vector)
{
	G_Vector* pVector = (G_Vector*)*phG_Vector;
	int i;
	for (i = 0; i < pVector->capacity; i++)
	{
		//for every item that not NULL need call destroy()
		if (pVector->data[i] != NULL)
		{
			pVector->item_destroy(&pVector->data[i]);
		}
	}
	free(pVector->data);//array of pointers
	free(pVector);
	*phG_Vector = NULL;
}
Status generic_vector_push_back(G_VECTOR hVector, Item item)
{
	G_Vector* pVector = (G_Vector*)hVector; //cast to known type
	Item_ptr temp;  //array of void pointers
	int i;
	//is there enough room?
	//if not - make room (resize)
	if (pVector->size >= pVector->capacity) 
	{
		temp = (Item_ptr)malloc(sizeof(Item) * 2 * pVector->capacity);
		if (temp == NULL)
		{
			return FAILURE;
		}
		pVector->capacity *= 2;
		for (i = 0; i < pVector->size; i++) {
			temp[i] = pVector->data[i];  //does work coppying the existing pointers
		}
		for (i = pVector->size;i < pVector->capacity; i++)//from that point on everything is NULL
		{
			temp[i] = NULL;
		}
		free(pVector->data);
		pVector->data = temp;
	}
	//YES -put at the available index (size)
	//pVector->data[pVector->size] = item; //here is problem does not 
	////know to make a complete independent copy
	pVector->item_assign(&pVector->data[pVector->size], item);
	pVector->size++;

	return SUCCESS;
}
Status generic_vector_pop_back(G_VECTOR hVector)
{
	// leaving memory allocation for objects beyond size for clean up later
	G_Vector* pVector = (G_Vector*)hVector;
	if (pVector->size <= 0)
	{
		return FAILURE;
	}
	pVector->size--;
	return SUCCESS;
}
Item generic_vector_at(G_VECTOR hVector, int index)
{
	G_Vector* pVector = (G_Vector*)hVector;
	if (index < 0 || index >= pVector->size)
	{
		return NULL;
	}
	return pVector->data[index];//return copy of address give handle to an object
	//return pVector->data + index;

}
int generic_vector_get_size(G_VECTOR hVector)
{
	G_Vector* pVector = (G_Vector*)hVector;
	return pVector->size;
}

int generic_vector_get_capacity(G_VECTOR hVector) {
	G_Vector* pVector = (G_Vector*)hVector;
	return pVector->capacity;
}