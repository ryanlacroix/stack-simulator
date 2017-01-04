#include <stdio.h>
#include <string.h>
#include "a3StackDefs.h"

void sumIterative(StackType *stk, int numElements, int *intArray, int *sum)
{
  ParamType *params[2];

  // Initialize parameter structs
  st_createParam("numElements", &numElements, &params[0]);
  st_createParam("sum", sum, &params[1]);

  printf("*** Sum function start ***\n");
  // Put the new frame on the stack
  st_push(stk, "sumIterative", 2, params);

  int i;
  *sum = 0;
  // Calculate sum
  for (i=0; i<numElements; ++i)
    *sum += intArray[i];
  printf("*** Sum function end ***\n");

  // Remove frame from stack
  st_pop(stk);
}


void sumRecursive(StackType *stk, int numElements, int *intArray, int *sum)
{
  ParamType *params[2];

  // Initialize parameter structs
  st_createParam("numElements", &numElements, &params[0]);
  st_createParam("sum", sum, &params[1]);

  printf("*** Sum function start ***\n");
  // Put the new frame on the stack
  st_push(stk, "sumRecursive", 2, params);

  // At deepest point in recursion:
  if (numElements == 0) {
    *sum = 0;
    printf("*** Sum function end ***\n");
    st_pop(stk);
    return;
  }

  sumRecursive(stk, numElements-1, intArray, sum);
  *sum += intArray[numElements-1];

  printf("*** Sum function end ***\n");
  // Remove frame from the stack
  st_pop(stk);
}

