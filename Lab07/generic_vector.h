#include "status.h"
typedef void* G_VECTOR;//generic vector
#include "generic.h"


G_VECTOR generic_vector_init_default(Status(*item_assign)(Item_ptr, Item),void(*item_destroy)(Item_ptr)); //was just void before

//add items
Status generic_vector_push_back(G_VECTOR hVector, Item item);

///G_VECTOR vector_init_size(int size);
//
//// check size and capacityStatus(
int generic_vector_get_size(G_VECTOR hVector);
int generic_vector_get_capacity(G_VECTOR hVector);
///
////delete items
Status generic_vector_pop_back(G_VECTOR hVector);
//
// see the value of a particular item in the container
//Precondition: hVector contains the handle to a valid vector object
//Postcondition: returns a copy of the adress of index 'th element and NULL otherwise
Item generic_vector_at(G_VECTOR hVector, int index);

void generic_vector_destroy(G_VECTOR* phG_Vector);
