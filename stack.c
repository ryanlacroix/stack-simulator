#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "a3StackDefs.h"

/*     Function: st_init                                 */
/*           in: Location of stack                       */
/*          out: Initialized stack                       */
/*      Purpose: Initializes number of stack frames to 0 */
void st_init(StackType *stk)
{
  stk->numFrames = 0;
}

void st_dump(StackType *stk)
{
  int i, j, k;

  printf("     -- STACK --\n");

  for (i=0; i<stk->numFrames; ++i) {
    printf("     ---- FRAME #%d:  %s \n", i, 
             stk->frames[i].funcName);

    for (j=0; j<stk->frames[i].numParams; j++) {
      printf("      %s: %4d \n", (stk->frames[i].params[j]->name), *(stk->frames[i].params[j]->value));
    }
  }
  printf("     -- END OF STACK --\n\n");
}

/*     Function: st_push                          */
/*           in: Location of stack                */ 
/*           in: Name of function                 */                   
/*           in: Number of parameters             */
/*           in: Array of parameters              */
/*          out: Modified stack                   */
/*      Purpose: Adds new frame to top of stack   */
void st_push(StackType *stk, char *fname, int numP, ParamType **paramArr)
{
  int currFrame;
  int i;
  currFrame = stk->numFrames;
  // Check if number of frames is valid
  if (currFrame>MAX_FRAMES)
  {
    printf("Error: Stack is full");
    return;
  }
  // Store information in the new frame
  strcpy(stk->frames[currFrame].funcName, fname);
  stk->frames[currFrame].numParams = numP;
  for (i=0; i<numP; i++)
    stk->frames[currFrame].params[i] = paramArr[i];// maybe

  // Update number of frames present
  stk->numFrames += 1;
  
  // Print contents of stack
  st_dump(stk);
}

/*     Function: st_pop                           */
/*           in: Location of stack                */                    
/*           in: Number of parameters             */
/*           in: Array of parameters              */
/*          out: Modified stack                   */
/*      Purpose: Remove frame from top of stack   */
void st_pop(StackType *stk)
{
  int currFrame;
  int i;
  // Set current frame to last used frame
  currFrame = (stk->numFrames)-1;
  // Check if stack is empty
  if (currFrame == -1)
  {
    printf("Error: Stack is empty");
    return;
  }

  st_dump(stk);// stops after this
    
  // Free up memory used by the frame
  for (i=0; i<stk->frames[currFrame].numParams; i++)
  {
    free((stk->frames[currFrame].params[i]));
  }
  // Update number of frames present
  stk->numFrames -= 1;
}

/*     Function: st_createParam                      */
/*           in: Name string                         */              
/*           in: Address of value                    */
/*           in: double pointer to ParamType struct  */
/*          out: address of pointer to initialized   */
/*               ParamType struct                    */
/*      Purpose: Initialize ParamType structs        */
void st_createParam(char *name, int *valuePtr, ParamType **newParam)
{
  *newParam = malloc(sizeof(ParamType));
  strcpy((*newParam)->name, name);
  (*newParam)->value = valuePtr;
}
