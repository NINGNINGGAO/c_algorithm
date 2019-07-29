/*
 * @Author: AGOGIN 
 * @Date: 2019-07-29 20:53:37 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-07-29 21:11:25
 */

#ifndef _BinHeap_H
#define _BinHeap_H

typedef int ElementType;

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif

struct HeapStruct {
          int Capacity;
          int Size;
          ElementType *Elements;
};