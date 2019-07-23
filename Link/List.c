#include <stdio.h>
#include <stdlib.h>
#include "List.h"

List MakeEmpty(List L) {
          Position P, TmpCell;
          P = L;
          if (!IsLast(P, L)) {
                    TmpCell = P->Next;
                    P->Next = TmpCell->Next;
                    free(TmpCell);
          }
          return L;
}

int IsEmpty(List L) {
          return L-> Next == NULL;
}

int IsLast(Position P, List L) {
          return P->Next == NULL;
}

Position Find(ElementType X, List L) {
          Position P;
          P = L->Next;
          while (P != NULL && P->Element != X) {
                    P = P->Next;
          }
          return P;
}

Position FindKth(int Key, List L) {
          if (Key < 0) return NULL;
          if (Key == 0) return L;
          Position P = L;
          while (Key && P != NULL) {
                    P = P->Next;
                    Key--;
          }
          return P;
}

Position FindPrevious(ElementType X, List L) {
          Position P;
          P = L;
          while (P->Next != NULL && P->Next->Element != X) {
                    P = P->Next;
          }
          return P;
}

void Delete(ElementType X, List L) {
          Position P, TmpCell;

          P = FindPrevious(X, L);

          if (!IsLast(P, L)) {
                    TmpCell = P->Next;
                    P->Next = TmpCell->Next;
                    free(TmpCell);
          }
}
int DeleteKth(int Key, List L) {
          Position P, TmpCell;
          P = L;
          while ((Key - 1) && P != NULL) {
                    P = P->Next;
                    Key--;
          }
          if (P != NULL) {
                    TmpCell = P->Next;
                    P->Next = TmpCell->Next;
                    free(TmpCell);
                    return 1;
          } else return -1;
}

void Insert(ElementType X, List L, Position P) {
          Position TmpCell;

          TmpCell = malloc(sizeof(struct Node));
          TmpCell->Element = X;
          TmpCell->Next = P->Next;
          P->Next = TmpCell;         
}

int InsertKth(ElementType X, List L, int Key) {
          Position P,TmpCell;
          P = L;
          while ((Key - 1) && P != NULL) {
                    P = P->Next;
                    Key--;
          }
          if (P != NULL) {
                    TmpCell = malloc(sizeof(struct Node));
                    TmpCell->Element = X;
                    TmpCell->Next = P->Next;
                    P->Next = TmpCell;
                    return 1;
          } else return -1;
}

void DeleteList(List L) {
          Position P, Tmp;
          P = L->Next;
          L->Next = NULL;
          while (P != NULL) {
                    Tmp = P->Next;
                    free(P);
                    P = Tmp;
          }
}

Position Header(List L) {
          return L;
}

Position First(List L) {
          return L->Next;
}


ElementType Retrieve(Position P) {
          return P->Element;
}