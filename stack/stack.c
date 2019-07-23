#include "stack.h"
#include <stdlib.h>

int IsEmpty(Stack S) {
          return S->Next == NULL;
}

Stack CreateStack(void) {
          Stack S;
          S = malloc(sizeof(struct Node));
          S->Next = NULL;
          MakeEmpty(S);
          return S;
}

void MakeEmpty(Stack S) {
          while (!IsEmpty(S)) {
                    pop(S);
          }
}

void push(ElementType X, Stack S) {
          PtrToNode TmpCell;

          TmpCell = malloc(sizeof(struct Node));
          TmpCell->ELement = X;
          TmpCell->Next = S->Next;
          S->Next = TmpCell;
}

ElementType Top(Stack S) {
          if (!IsEmpty(S)){
                    return S->Next->ELement;
          }
          exit(0);
}

void pop(Stack S) {
          PtrToNode TmpCell;
          if (!IsEmpty(S)) {
                    TmpCell = S->Next;
                    S->Next = S->Next->Next;
                    free(TmpCell);
          }
}