/*
 * @Author: AGOGIN 
 * @Date: 2019-08-24 17:33:36 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-08-24 18:29:50
 */
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue CreatQueue() {
    Queue Q = malloc(sizeof(struct Queue_Node));
    Q->Size = 0;
}

int IsEmpty(Queue Q) {
    return Q->Size == 0;
};

void MakeEmpty(Queue Q) {
    if (Q->Size != 0) {
        Position temp = malloc(sizeof(struct QueueRecord));
        while (Q->Size != 1) {
            temp = Q->Front;
            Q->Front = Q->Front->Next;
            free(temp);
            Q->Size--;
        }
        temp = Q->Front;
        Q->Front = NULL;
        Q->Rear = NULL;
        Q->Size--;
    }
}

ElementType Front(Queue Q) {
    if (Q->Size != 0) {
        return Q->Front->Element;
    } else {
        return NULL;
    }
}

void Enqueue(ElementType X, Queue Q) {
    Position temp = malloc(sizeof(struct QueueRecord));
    temp->Element = X;
    temp->Next = NULL;
    if (Q->Size == 0) {
        Q->Front = temp;
        Q->Rear = temp;
        Q->Size++;        
    } else {
        Q->Rear->Next = temp;
        Q->Rear = temp;
        Q->Size++;
    }
}

void Dequeue(Queue Q) {
    Position temp = malloc(sizeof(struct QueueRecord));
    if (Q->Size == 1) {
        Q->Size = 0;
        temp = Q->Front;
        Q->Front = NULL;
        Q->Rear = NULL;
        free(temp);
    } else if (Q->Size != 0) {
        temp = Q->Front;
        Q->Front = Q->Front->Next;
        free(temp);
        Q->Size--;
    }
}

ElementType FrontAndDequeue(Queue Q) {
    Position temp = malloc(sizeof(struct QueueRecord));
    if (Q->Size == 1) {
        Q->Size = 0;
        temp = Q->Front;
        Q->Front = NULL;
        Q->Rear = NULL;
        return temp->Element;
    } else if (Q->Size != 0) {
        temp = Q->Front;
        Q->Front = Q->Front->Next;
        Q->Size--;
        return temp->Element;
    }
    free(temp);
}

main() {
    Queue Q = CreatQueue();
    printf("%d\n\n", IsEmpty(Q));
    for (int i = 1; i < 10; i++) {
        Enqueue(i, Q);
    }
    printf("\n");
    printf("%d\n\n", Front(Q));
    for (int i = 1; i < 9; i++) {
        printf("%d\n\n", FrontAndDequeue(Q));
    }
    printf("\n");
    printf("%d\n", IsEmpty(Q));
    MakeEmpty(Q);
    printf("%d\n", IsEmpty(Q));
}