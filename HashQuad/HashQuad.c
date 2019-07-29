/*
 * @Author: AGOGIN 
 * @Date: 2019-07-29 11:04:21 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-07-29 17:50:51
 */
#include "HashQuad.h"
#include <stdio.h>
#include <stdlib.h>

Position Hash(ElementType Key, int TableSize) {
          return Key % TableSize;
}

static int NextPrime(int N) {
          if (N % 2 == 0) {
                    N++;
          }
          int i;
          for (; ; N += 2) {
                    for (i = 3; i*i < N; i += 2) {
                              if (N % i == 0) {
                                        goto ContOuter;
                              }
                              return N;
                    }
                    ContOuter:;
          }
}

HashTable InitializeTable(int TableSize) {
          HashTable H;
          int i;

          H = malloc(sizeof(struct HashTbl));
          if (H == NULL) {
                    printf("Table size is too small!!!\n");
          }
          H->TableSize = NextPrime(TableSize);
          H->TheCells = malloc(sizeof(Cell) * H->TableSize);
          if (H->TheCells == NULL) {
                    printf("Out of space!!!\n");
          }
          for (i = 0; i < H->TableSize; i++) {
                    H->TheCells[i].Info = Empty;
          }
          return H;
}

Position Find(ElementType Key, HashTable H) {
          Position CurrentPos;
          int CollisionNum;

          CollisionNum = 0;
          CurrentPos = Hash(Key, H->TableSize);
          while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key) {
                    CurrentPos += 2* ++CollisionNum - 1;
                    if (CurrentPos >= H->TableSize) {
                              CurrentPos -= H->TableSize;
                    }
          } 
          return CurrentPos;
}

void Insert(ElementType Key, HashTable H) {
          Position Pos;

          Pos = Find(Key, H);
          if (H->TheCells[Pos].Info != Legitimate) {
                    H->TheCells[Pos].Info = Legitimate;
                    H->TheCells[Pos].Element = Key;
          }
}

HashTable ReHash(HashTable H) {
          int i, OldSize;
          Cell* OldCells;

          OldCells = H->TheCells;
          OldSize = H->TableSize;
          H = InitializeTable(2 * OldSize);

          for (i = 0; i < OldSize; i++) {
                    if (OldCells[i].Info == Legitimate) {
                              Insert(OldCells[i].Element, H);
                    }
          }
          free(OldCells);
          return H;
}

void DestroyTable(HashTable H) {
          for (int i = 0; i < H->TableSize; i++) {
                    if (H->TheCells[i].Info == Legitimate) {
                              H->TheCells[i].Info = Deleted;
                    }
          }
}

ElementType Retrieve(Position P, HashTable H) {
          if (H->TheCells[P].Info == Legitimate) {
                    return H->TheCells[P].Element;
          } else {
                    return NULL;
          }
}