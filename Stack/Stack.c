/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:25 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:25 
 */
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int IsEmpty(Stack S) {
          return S->Next == NULL;
}

Stack CreateStack(void) {
          Stack S;
          S = malloc(sizeof(struct Node));
          if (S == NULL) {
                    printf("Out of space!!!\n");
          }    
          S->Next = NULL;
          MakeEmpty(S);
          return S;
}

void MakeEmpty(Stack S) {
          if (S == NULL) {
                    printf("Must use CreateStack first!\n");
          } else {
                    while (!IsEmpty(S)) {
                              pop(S);
                    }
          }
}

void push(ElementType X, Stack S) {
          PtrToNode TmpCell;

          TmpCell = malloc(sizeof(struct Node));
          if (TmpCell == NULL) {
                    printf("Out of space!!!\n");
          } else {
                    TmpCell->ELement = X;
                    TmpCell->Next = S->Next;
                    S->Next = TmpCell;
          }
}

ElementType Top(Stack S) {
          if (!IsEmpty(S)){
                    return S->Next->ELement;
          } else {
                    printf("Empty stack,return INT_MAX\n");
                    return INT_MAX;
          }
}

void pop(Stack S) {
          PtrToNode TmpCell;
          if (!IsEmpty(S)) {
                    TmpCell = S->Next;
                    S->Next = S->Next->Next;
                    free(TmpCell);
          } else {
                    printf("Empty stack\n");
          }
}