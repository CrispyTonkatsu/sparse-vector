#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H
#include <stdio.h> /* printf */

/* opaque pointer since definition of Node is hidden from the client we need to
 * provide some way to use Node struct, and here it is -- typedef.  At this
 * point Node is NOT KNOWN to the compiler (which makes Node an INCOMPLETE
 * TYPE, but declaring a pointer to an incomplete type is allowed by C (and
 * C++).
 *
 * see http://en.wikipedia.org/wiki/Opaque_pointer
 *
 * we also need a special type ConstElementNode_handle:
 * notice that:
 * even though "ElementNode*" is same as "ElementNode_handle"
 * "const ElementNode*" and "const ElementNode_handle"
 * are DIFFERENT:
 * const ElementNode* p; is modifiable pointer to constant data
 * while 
 * const ElementNode_handle p; is constant pointer to modifiable data
 */
typedef struct ElementNode *       ElementNode_handle;
typedef struct ElementNode const * ConstElementNode_handle;

/*===================*
 * element functions *
 *===================*/

/* print elements as a vector, adding 0's for non-existing positions
 * assume the length of the vector = dim
 * doesn't check if the list contains positions beyond dim */
void printf_elements( ConstElementNode_handle, char const *, int); 

/* 
 * print all elements in the list with positions */
void print_elements(ConstElementNode_handle); /* no zeros */

/* insert an element into a list 
 * list is ordered using pos
 * if position pos is already occupied, the value of the node
 * should be updated with val
 * if val=0, then the element should be deleted
 * return 0 if operation is succesfull 
 *        1 if malloc failed */
int insert_element(ElementNode_handle *,int,int);

/* 
 * delete an element at position pos if it exists */
void delete_element( ElementNode_handle *,int );

/*
 * get the value at the given position,
 * p_e is the head pointer 
 */
int  get( ConstElementNode_handle, int );

/* 
 * scalar product of 2 lists.
 * */
int scalar_product( ConstElementNode_handle, ConstElementNode_handle );

/* 
 * adds 2 lists as vectors, returns a new list */
ElementNode_handle add( ConstElementNode_handle,ConstElementNode_handle );

/* 
 * deallocate a list */
void free_elements( ElementNode_handle );

#endif
