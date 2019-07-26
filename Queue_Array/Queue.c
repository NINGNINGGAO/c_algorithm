#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

Queue CreatQueue(int MaxElements) {
          Queue Q;
          Q = (struct QueueRecord*)malloc(sizeof(struct QueueRecord));
          Q->Capacity = MaxElements;
          Q->Array = malloc(sizeof(int) * MaxElements);
          return Q;
}

int IsFull(Queue Q) {
          return Q->Size == Q->Capacity;
}

int IsEmpty(Queue Q) {
          return Q->Size == 0;
}

void DisposeQueue(Queue Q) {
          free(Q);
}

void MakeEmpty(Queue Q) {
          Q->Size = 0;
          Q->Front = 1;
          Q->Rear = 0;
}
static int Succ(int Value, Queue Q) {
          if (++Value == Q->Capacity) {
                    Value = 0;
          }
          return Value;
}

void Enqueue(ElementType X, Queue Q) {
          if (IsFull(Q)) {
                    printf("Full queue");
          } else {
                    Q->Size++;
                    Q->Rear = Succ(Q->Rear, Q);
                    Q->Array[Q->Rear] = X;
          }
}

ElementType Front(Queue Q) {
          return Q->Array[Q->Front];
}

void Dequeue(Queue Q) {
          if (IsEmpty(Q)) {
                    printf("Empty queue");
          } else {
                    Q->Size--;
                    Q->Front = Succ(Q->Front, Q);
          }
}

ElementType FrontAndDequeue(Queue Q) {
          if (IsEmpty(Q)) {
                    printf("Empty queue");
          } else {
                    ElementType temp = Q->Array[Q->Front];
                    Q->Size--;
                    Q->Front = Succ(Q->Front, Q);
                    return temp;
          }
}