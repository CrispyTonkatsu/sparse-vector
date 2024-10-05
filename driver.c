#include <stdio.h> /* printf, NULL   */
#include <stdlib.h>
#include <string.h>
#include "spvector.h"

void test0(void);
void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);
void test6(void);
void test7(void);
void test8(void);
void test9(void);
void test10(void);
void test11(void);
void test12(void);

void test0(void) {
  ElementNode_handle pE1 = 0;
  int i;
  printf("\n====== INSERTS BACK =============================\n");
  for (i = 0; i < 20; ++i) insert_element(&pE1, 3 * i, i * i);
  printf("vector 1 formatted:\n");
  printf_elements(pE1, "%4d", 80);
  printf("\n");
  printf("vector 1 raw:\n");
  print_elements(pE1);
  printf("\n");

  free_elements(pE1);
}

void test1(void) {
  ElementNode_handle pE2 = 0;
  int i;
  printf("\n====== INSERTS BACK =============================\n");

  for (i = 0; i < 20; ++i) insert_element(&pE2, 20 - i, i);
  printf("vector 2 formatted:\n");
  printf_elements(pE2, "%4d", 20);
  printf("\n");
  printf("vector 2 raw:\n");
  print_elements(pE2);
  printf("\n");

  free_elements(pE2);
}

void test2(void) {
  ElementNode_handle pE3 = 0;
  int i;
  printf("\n====== INSERTS MIDDLE =============================\n");

  for (i = 0; i < 20; ++i) {
    if (i % 2)
      insert_element(&pE3, i, i);
    else
      insert_element(&pE3, 20 - i, -i);
  }
  printf("vector 3 formatted:\n");
  printf_elements(pE3, "%4d", 20);
  printf("\n");
  printf("vector 3 raw:\n");
  print_elements(pE3);
  printf("\n");

  free_elements(pE3);
}

void test3(void) {
  ElementNode_handle pE2 = 0;
  int i;
  printf("\n====== DELETE FRONT ====================\n");
  for (i = 0; i < 5; ++i) insert_element(&pE2, i, i + 1); /*no 0s in the list*/
  printf("vector 2 formatted:\n");
  printf_elements(pE2, "%4d", 5);
  printf("\n");
  printf("vector 2 raw:\n");
  print_elements(pE2);
  printf("\n");

  delete_element(&pE2, 0);
  printf("vector 2 formatted:\n");
  printf_elements(pE2, "%4d", 5);
  printf("\n");
  printf("vector 2 raw:\n");
  print_elements(pE2);
  printf("\n");

  free_elements(pE2);
}

void test4(void) {
  ElementNode_handle pE2 = 0;
  int i;
  printf("\n====== DELETE BACK ====================\n");
  for (i = 0; i < 5; ++i) insert_element(&pE2, i, i + 1); /*no 0s in the list*/
  printf("vector 2 formatted:\n");
  printf_elements(pE2, "%4d", 5);
  printf("\n");
  printf("vector 2 raw:\n");
  print_elements(pE2);
  printf("\n");

  delete_element(&pE2, 4);
  printf("vector 2 formatted:\n");
  printf_elements(pE2, "%4d", 5);
  printf("\n");
  printf("vector 2 raw:\n");
  print_elements(pE2);
  printf("\n");

  free_elements(pE2);
}

void test5(void) {
  ElementNode_handle pE2 = 0;
  int i;
  printf("\n====== DELETE MIDDLE ====================\n");
  for (i = 0; i < 5; ++i) insert_element(&pE2, i, i + 1); /*no 0s in the list*/
  printf("vector 2 formatted:\n");
  printf_elements(pE2, "%4d", 5);
  printf("\n");
  printf("vector 2 raw:\n");
  print_elements(pE2);
  printf("\n");

  delete_element(&pE2, 2);
  printf("vector 2 formatted:\n");
  printf_elements(pE2, "%4d", 5);
  printf("\n");
  printf("vector 2 raw:\n");
  print_elements(pE2);
  printf("\n");

  free_elements(pE2);
}

void test6(void) {
  ElementNode_handle pE1 = 0, pE2 = 0, pE3 = 0;
  int i;
  printf("\n==== SCALAR MULTIPLICATION =================\n");
  for (i = 0; i < 20; ++i) insert_element(&pE1, i, i * i);
  printf("vector pE1 formatted:\n");
  printf_elements(pE1, "%4d", 20);
  printf("\n");

  for (i = 0; i < 20; ++i) insert_element(&pE2, 40 - 2 * i, i);
  printf("vector pE2 formatted:\n");
  printf_elements(pE2, "%4d", 40);
  printf("\n");

  for (i = 0; i < 20; ++i) {
    if (i % 2)
      insert_element(&pE3, 2 * i, i);
    else
      insert_element(&pE3, 41 - 2 * i, -i);
  }
  printf("vector pE3 formatted:\n");
  printf_elements(pE3, "%4d", 40);
  printf("\n");
  printf("scalar product pE1 and pE2 = %i\n", scalar_product(pE1, pE2));
  printf("scalar product pE2 and pE3 = %i\n", scalar_product(pE2, pE3));
  printf("scalar product pE3 and pE1 = %i\n", scalar_product(pE3, pE1));
  printf("scalar product pE1 and pE1 = %i\n", scalar_product(pE1, pE1));

  free_elements(pE1);
  free_elements(pE2);
  free_elements(pE3);
}

void test7(void) {
  ElementNode_handle pE1 = 0, pE2 = 0;
  int i;
  printf("\n==== SCALAR MULTIPLICATION 2 =================\n");
  for (i = 0; i < 20; ++i) insert_element(&pE1, 1000 * i, i * i);

  for (i = 0; i < 20; ++i) insert_element(&pE2, 500 * i, i);

  printf("scalar product pE1 and pE2 = %i\n", scalar_product(pE1, pE2));
  printf("scalar product pE2 and pE1 = %i\n", scalar_product(pE2, pE1));
  printf("scalar product pE1 and pE1 = %i\n", scalar_product(pE1, pE1));

  free_elements(pE1);
  free_elements(pE2);
}

void test8(void) {
  ElementNode_handle pE1 = 0, pE2 = 0, pE3 = 0, pRes;
  int i;
  printf("\n==== VECTOR ADDITION =================\n");
  for (i = 0; i < 20; ++i) insert_element(&pE1, i, i * i);
  printf("vector pE1 formatted:\n");
  printf_elements(pE1, "%4d", 20);
  printf("\n");

  for (i = 0; i < 10; ++i) insert_element(&pE2, 20 - 2 * i, i);
  printf("vector pE2 formatted:\n");
  printf_elements(pE2, "%4d", 20);
  printf("\n");

  for (i = 0; i < 5; ++i) {
    if (i % 2)
      insert_element(&pE3, 4 * i, i);
    else
      insert_element(&pE3, 21 - 4 * i, -i);
  }
  printf("vector pE3 formatted:\n");
  printf_elements(pE3, "%4d", 20);
  printf("\n");

  pRes = add(pE1, pE2);
  printf("pE1 + pE2 = \n");
  printf_elements(pRes, "%4d", 20);
  printf("\n");
  /* printf("raw:\n"); print_elements(pRes); printf("\n"); */
  free_elements(pRes);

  free_elements(pE1);
  free_elements(pE2);
  free_elements(pE3);
}

void test9(void) {
  ElementNode_handle pE1 = 0, pE2 = 0, pRes;
  int i;
  printf("\n==== VECTOR ADDITION 2 =================\n");
  for (i = 0; i < 5; ++i) insert_element(&pE1, 2000 * i, i);

  for (i = 0; i < 10; ++i) insert_element(&pE2, 1000 * i, i);

  pRes = add(pE1, pE2);
  printf("pE1 + pE2 = \n");
  printf("raw:\n");
  print_elements(pRes);
  printf("\n");
  free_elements(pRes);

  pRes = add(pE2, pE1);
  printf("pE2 + pE1 = \n");
  printf("raw:\n");
  print_elements(pRes);
  printf("\n");
  free_elements(pRes);

  pRes = add(pE1, pE1);
  printf("pE1 + pE1 = \n");
  printf("raw:\n");
  print_elements(pRes);
  printf("\n");
  free_elements(pRes);

  free_elements(pE1);
  free_elements(pE2);
}

void test10(void) {
  ElementNode_handle pE1 = 0, pE2 = 0, pRes;
  int i;
  printf("\n==== VECTOR ADDITION (ZEROES) ========\n");
  for (i = 0; i < 20; ++i) insert_element(&pE1, i, i * i);
  printf("vector pE1 formatted:\n");
  printf_elements(pE1, "%4d", 20);
  printf("\n");

  for (i = 0; i < 20; ++i) insert_element(&pE2, i, -i * i);
  printf("vector pE2 formatted:\n");
  printf_elements(pE2, "%4d", 20);
  printf("\n");

  pRes = add(pE1, pE2);
  printf("pE1 + pE2 = \n");
  printf_elements(pRes, "%4d", 20);
  printf("\n");
  printf("raw:\n");
  print_elements(pRes);
  printf("\n");
  free_elements(pRes);
  pRes = add(pE2, pE1);
  printf("pE2 + pE1 = \n");
  printf_elements(pRes, "%4d", 20);
  printf("\n");
  printf("raw:\n");
  print_elements(pRes);
  printf("\n");
  free_elements(pRes);
  free_elements(pE1);
  free_elements(pE2);
}

void test11(void) {
  ElementNode_handle pE1 = 0;
  int i;
  printf("\n==== TESTING FIND ========\n");
  for (i = 0; i < 20; i += 2) insert_element(&pE1, i, i * i);
  printf_elements(pE1, "%4d", 20);
  printf("\n");
  printf("print vector using get - very inefficient!!!\n");
  for (i = 0; i < 20; ++i) printf("index %i, value %i\n", i, get(pE1, i));
  free_elements(pE1);
}

void test12(void) {
  ElementNode_handle pE1 = 0;
  int pos = 10000;
  printf("\n==== TESTING FIND 2 ========\n");
  insert_element(&pE1, pos, 5);
  print_elements(pE1);
  printf("\n");

  printf("value %i at position %i\n", get(pE1, pos), pos);
  free_elements(pE1);
}

void (*pTests[])(void) = {
    test0,
    test1,
    test2,
    test3,
    test4,
    test5,
    test6,
    test7,
    test8,
    test9,
    test10,
    test11,
    test12,
};

int main(int argc, char *argv[]) {
  if (argc > 1) {
    int test = 0;
    sscanf(argv[1], "%i", &test);
    pTests[test]();
  }
  return 0;
}
