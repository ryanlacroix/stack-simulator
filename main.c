#include <stdio.h>
#include <stdlib.h>

#include "a3StackDefs.h"

int main()
{
  int intArray[MAX_ARR_SIZE];

  int numElm = 0;
  int result = 0;
  int choice, rc;

  StackType *stk;
  stk = malloc(MAX_FRAMES * sizeof(FrameType));
  st_init(stk);

  
  rc = getArrayData(intArray, &numElm);
  if (rc < 0)
    exit(1);

  printf("\nHow would like to sum the elements?\n");
  printf("  (1)  iteratively\n");
  printf("  (2)  recursively\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      sumIterative(stk, numElm, intArray, &result);
      printf("Sum is %d\n", result);
      break;
    case 2:
      sumRecursive(stk, numElm, intArray, &result);
      printf("Sum is %d\n", result);
  }
  free(stk);
  return 0;
}

int getArrayData(int *arr, int *num)
{
  int currCount = 0;

  printf("\nEnter the number of elements:  ");
  scanf("%d", num);

  if (*num >= MAX_ARR_SIZE) {
    printf("Too many elements\n");
    return C_NOK;
  }

  while (currCount < *num) {
    printf("Enter the next number:  ");
    scanf("%d", arr+currCount);
    ++currCount;
  }
  return C_OK;
}

