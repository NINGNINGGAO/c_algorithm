/*
 * @Author: AGOGIN 
 * @Date: 2019-08-24 17:33:38 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-08-24 18:29:46
 */
#ifndef _Queue_Link
#define _Queue_Link

typedef int ElementType;

struct QueueRecord;
typedef struct QueueRecord *Position;
typedef struct Queue_Node *Queue;

Queue CreatQueue();
int IsEmpty(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif

struct QueueRecord {
    ElementType Element;
    Position Next;
};

struct Queue_Node {
    int Size;
    Position Front;
    Position Rear;
};