#ifndef _QUEUE_H
#define _QUEUE_H

typedef int ElementType;

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreatQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif

struct QueueRecord {
          int Capacity;
          int Front;
          int Rear;
          int Size;
          ElementType* Array;
};