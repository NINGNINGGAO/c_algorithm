/*
 * @Author: AGOGIN 
 * @Date: 2019-07-29 20:53:34 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-07-29 22:25:42
 */
#include "BinHeap.h"
#include <stdio.h>
#include <stdlib.h>


PriorityQueue Initialize(int MaxElements) {
          ElementType MinData = 0;
          PriorityQueue H;

          H = malloc(sizeof(struct HeapStruct));
          if (H == NULL) {
                    printf("Out of space!!!\n");
          }
          H->Elements = malloc((MaxElements + 1) * sizeof(ElementType));
          if (H->Elements == NULL) {
                    printf("Out of space!!!\n");
          }

          H->Capacity = MaxElements;
          H->Size = 0;
          H->Elements[0] = MinData;

          return H;
}

void Insert(ElementType X, PriorityQueue H) {
          int i;
          if (IsFull(H)) {
                    printf("Priority queue is full!\n");
                    return;
          }
           for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2) {
                     H->Elements[i] = H->Elements[i / 2];
           }
           H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H) {
          int i, Child;
          ElementType MinElement, LastElement;

          if (IsEmpty(H)) {
                    printf("Priority queue is empty!\n");
                    return H->Elements[0];
          }

          MinElement = H->Elements[1];
          LastElement = H->Elements[H->Size--];
          
          for (i = 1; i * 2 <= H->Size; i = Child) {
                    Child = i * 2;
                    if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child]) {
                              Child++;
                    }
                    if (LastElement > H->Elements[Child]) {
                              H->Elements[i] = H->Elements[Child];
                    } else {
                              break;
                    }
          }
          H->Elements[i] = LastElement;
          return MinElement;
}

ElementType FindMin(PriorityQueue H) {
          if (H->Size >= 1) {
                    return H->Elements[1];
          } else {
                    return NULL;
          }
}

int IsEmpty(PriorityQueue H) {
          if (H->Size == 0) {
                    return 1;
          } else {
                    return 0;
          }
}

int IsFull(PriorityQueue H) {
          if (H->Size >= H->Capacity) {
                    return 1;
          } else {
                    return 0;
          }
}

void Destroy(PriorityQueue H) {
          free(H->Elements);
          free(H);
}

void MakeEmpty(PriorityQueue H) {
          H->Size = 0;
}