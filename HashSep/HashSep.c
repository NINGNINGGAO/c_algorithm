/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 17:46:53 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-07-29 10:30:33
 */
#include "HashSep.h"
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Index;

/*Index Hash(const char* Key, int TableSize) {
          unsigned int HashVal = 0;

          while (*Key != '\0') {
                    HashVal = (HashVal << 5) + *Key++;
          }
          return HashVal % TableSize;
}*/

Index Hash(ElementType Key, int TableSize) {
          return Key % TableSize;
}

static int NextPrime (int N) {
    if (N % 2 == 0)
        ++N;
    int i;
    for (; ; N += 2){
        for (i = 3; i*i <= N; i+=2)
            if (N % i == 0)
                goto ContOuter;
            return N;
        ContOuter:;
    }
}

HashTable InitializeTable(int TableSize) {
          HashTable H;
          int i;
          
          H = malloc(sizeof(struct HashTbl));
          if (H == NULL) {
                    printf("Out of space!!!\n");
          }

          H->TableSize = NextPrime(TableSize);

          H->TheLists = malloc(sizeof(List) * H->TableSize);
          if (H->TheLists == NULL) {
                    printf("Out of space!!!\n");
          }

          for (i = 0; i < H->TableSize; i++) {
                    H->TheLists[i] = malloc(sizeof(struct ListNode));
                    if (H->TheLists[i] == NULL) {
                              printf("Out of space!!!\n");
                    } else {
                              H->TheLists[i]->Next = NULL;
                    }
          }
          return H;
}

Position Find(ElementType Key, HashTable H) {
          Position P;
          List L;

          L = H->TheLists[Hash(Key, H->TableSize)];
          P = L->Next;
          while (P != NULL && P->Element != Key) {
                    P = P->Next;
          }
          return P;
}

void Insert(ElementType Key, HashTable H) {
          Position Pos, NewCell;
          List L;

          Pos = Find(Key, H);
          if (Pos == NULL) {
                    NewCell = malloc(sizeof(struct ListNode));
                    if (NewCell == NULL) {
                              printf("Out of space!!!\n");
                    } else {
                              L = H->TheLists[Hash(Key, H->TableSize)];
                              NewCell->Next = L->Next;
                              NewCell->Element = Key;
                              L->Next = NewCell;
                    }
          }
}

ElementType Retrieve(Position P) {
          if (P == NULL) {
                    return NULL;
          } else {
                    return P->Element;
          }
}

void DestroyTable(HashTable H) {
          Position Temp, TmpCell;
          for (int i = 0; i < H->TableSize; i++) {
                    Temp = H->TheLists[i]->Next;
                    H->TheLists[i]->Next = NULL;
                    while (Temp == NULL) {
                              TmpCell = Temp->Next;
                              free(Temp);
                              Temp = TmpCell;
                    }
          }
}