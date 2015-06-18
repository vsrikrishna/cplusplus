/*
* This file has 2 methods aligned_malloc and aligned_free
* aligned_malloc ensures the starting address of the memory 
* is a multiple of alignment value
* aligned_free frees the aligned memory
* Conditions: 1) can use malloc and free
* 2) No static memory usage: the malloc and free use heap area and 
*    no static data used in the code
*/
#include <stdafx>
#include <stdlib>

void *aligned_malloc(size_t bytes, size_t alignment) 
{
  /*
   *offset holds the location returned from malloc
   *padding used for calculating new_offset and book-keeping
   *new_offset holds the aligned address
   */
  int *offset,*padding, *new_offset;
  
  /*
   *number of Bytes requested is inclusive of
   *byte to be stored
   *alignment number of bytes added, since the boundary would be within max of alignment byte
   */
  offset=(int *)malloc(bytes + alignment + sizeof(int));
 
  /*return if the requested memory is not available*/
  if(offset==NULL) 
	  return(NULL);

  /*
  *modulo method used to reach the alignment boundary
  *alignment boundary is crossed and this excess value is captured by modulo
  */
  padding = offset + alignment + sizeof(int);
  new_offset = padding - ((size_t)padding % alignment);
 
  /*
  *padding used to store first_offset location
  *this address is stored before the aligned address(new_offset)
  *the value stored is memory location value
  */
  padding = new_offset - sizeof(int);
  *padding = (int) offset;
  
  /*aligned address returned*/
  return(new_offset);
}

void aligned_free(void *p) 
{
   /*
   * memory location to be freed is stored before the aligned memory location
   *the memory location is retrieved and deleted
   **/
   p= (void*) *( (size_t*)p - sizeof(int));
   free(p);  
}

int main( void )
{
    int* data = 0;
    data = (int *)aligned_malloc( 1000, 128 ); 

	/**
	* Required Computation with allocated memory before the memory is freed
	*/
    aligned_free( data );

	return 0;
}


