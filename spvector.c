/**
 * Name: Edgar Jose Donoso Mansilla (e.donosomansilla)
 * Course: CS225
 * Assignment: Sparse Vector
 * Date 05-10-2024
 */

#include "spvector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* definition of Node is hidden from the client (driver) so that client CANNOT
 * use INTERNALS of the Node.  this is poor-man encapsulations - hiding
 * implementation details.  The main reason for encapsulations -- if I ever
 * decide to change Node struct no client code will break. Example: I decide to
 * change "left" to "Left", all I do is change map.h and map.c, no client code
 * is effected, since clients were FORCED to use getleft(...) function, rather
 * than field name "left".  Also see typedef in map.h
 */
struct ElementNode {
  int data;
  int pos;
  struct ElementNode *next;
};

typedef struct ElementNode ElementNode;
typedef struct RowNode RowNode;

/*print functions*/
void printf_elements(ConstElementNode_handle p_e, char const *fmt, int dim) {
  int i, last_pos = -1;
  while (p_e) {
    for (i = last_pos + 1; i < p_e->pos; ++i) {
      printf(fmt, 0);
    }
    printf(fmt, p_e->data);
    last_pos = p_e->pos;
    p_e = p_e->next;
  }
  for (i = last_pos + 1; i < dim; ++i) {
    printf(fmt, 0);
  }
}

void print_elements(ConstElementNode_handle p_e) {
  while (p_e) {
    printf("%i at pos %i, ", p_e->data, p_e->pos);
    p_e = p_e->next;
  }
}

/**
 * @brief Allocates and initializes an ElementNode
 *
 * @param position The node's position in the vector
 * @param value The value the node holds
 * @param next Pointer to the next non-zero index in the vector
 *
 * @return Pointer to the created node
 */
ElementNode *make_node(int position, int value, ElementNode *next) {
  ElementNode *to_add = (ElementNode *) calloc(1, sizeof(ElementNode));
  if (to_add == NULL) return NULL;

  to_add->data = value;
  to_add->pos = position;
  to_add->next = next;

  return to_add;
}

/* insert an element into a list
 * list is ordered using pos
 * if position pos is already occupied, the value of the node
 * should be updated with val
 * if val=0, then the element should be deleted
 * return 0 if operation is succesfull
 *        1 if malloc failed */
int insert_element(ElementNode_handle *head, int position, int value) {
  if (*head == NULL) {
    if (value == 0) return 0;

    ElementNode *to_add = make_node(position, value, NULL);
    if (to_add == NULL) return 1;

    *head = to_add;
    return 0;
  }

  ElementNode *previous = NULL;
  ElementNode *current = NULL;

  for (current = *head; current != NULL; current = current->next) {
    if (current->pos > position) {
      if (value == 0) return 0;
      ElementNode *to_add = make_node(position, value, NULL);
      if (to_add == NULL) return 1;

      if (previous == NULL) {
        to_add->next = current;
        *head = to_add;

      } else {
        to_add->next = previous->next;
        previous->next = to_add;
      }

      return 0;
    } else if (current->pos == position) {
      if (value == 0) {
        delete_element(head, position);
      } else {
        current->data = value;
      }
      return 0;
    }

    previous = current;
  }

  if (value == 0) return 0;

  ElementNode *to_add = make_node(position, value, NULL);
  if (to_add == NULL) return 1;

  previous->next = to_add;
  return 0;
}

/*
 * delete an element at position pos if it exists */
void delete_element(ElementNode_handle *head, int position) {
  ElementNode *previous = NULL;
  ElementNode *current = NULL;

  for (current = *head; current != NULL; current = current->next) {
    if (current->pos == position) {
      if (previous != NULL)
        previous->next = current->next;
      else
        *head = current->next;
      free(current);
      return;
    }
    previous = current;
  }
}

/*
 * get the value at the given position,
 * p_e is the head pointer
 */
int get(ConstElementNode_handle head, int position) {
  for (const ElementNode *current = head; current != NULL; current = current->next) {
    if (current->pos == position) {
      return current->data;
    }
  }

  return 0;
}

/*
 * scalar product of 2 lists. */
int scalar_product(ConstElementNode_handle head_a, ConstElementNode_handle head_b) {
  int result = 0;
  const ElementNode *current_a = head_a;
  const ElementNode *current_b = head_b;

  while (current_a && current_b) {
    if (current_a->pos == current_b->pos) {
      result += current_a->data * current_b->data;

      current_a = current_a->next;
      current_b = current_b->next;

    } else if (current_a->pos > current_b->pos) {
      current_b = current_b->next;

    } else if (current_b->pos > current_a->pos) {
      current_a = current_a->next;
    }
  }

  return result;
}

/*
 * adds 2 lists as vectors, returns a new list */
ElementNode_handle add(ConstElementNode_handle head_a, ConstElementNode_handle head_b) {
  ElementNode *new_list = NULL;
  const ElementNode *current_a = head_a;
  const ElementNode *current_b = head_b;

  int position = 0;
  while (current_a || current_b) {
    int value_to_add = 0;

    if (current_a && current_a->pos == position) {
      value_to_add += current_a->data;
      current_a = current_a->next;
    }

    if (current_b && current_b->pos == position) {
      value_to_add += current_b->data;
      current_b = current_b->next;
    }

    if (value_to_add != 0) {
      insert_element(&new_list, position, value_to_add);
    }

    position++;
  }

  return new_list;
}

/*
 * deallocate a list */
void free_elements(ElementNode_handle head) {
  while (head != NULL) {
    ElementNode *to_delete = head;
    head = to_delete->next;
    free(to_delete);
  }
}
