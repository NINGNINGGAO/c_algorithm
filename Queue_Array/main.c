#include <stdio.h>
#include "Queue.h"

main() {
          int MaxElements = 20;
          Queue Q = CreatQueue(MaxElements);
          printf("%d\n\n", IsEmpty(Q));
          printf("%d\n\n", IsFull(Q));
          for (int i = 0; i < 20; i++) {
                    Enqueue(i*i, Q);
                    printf("%d\n", Front(Q));
          }
          printf("%d\n\n", IsEmpty(Q));
          printf("%d\n\n", IsFull(Q));
          for (int i = 0; i < 20; i++) {
                    Dequeue(Q);
                    printf("%d\n", Front(Q));
          }
          printf("%d\n\n", IsEmpty(Q));
          printf("%d\n\n", IsFull(Q));
          for (int i = 0; i < 20; i++) {
                    Enqueue(i+5, Q);
                    printf("%d\n", Front(Q));
          }
          printf("%d\n\n", IsEmpty(Q));
          printf("%d\n\n", IsFull(Q));
          for (int i = 0; i < 20; i++) {
                    Enqueue(i+5, Q);
                    printf("%d\n", FrontAndDequeue(Q));
          }
          for (int i = 0; i < 20; i++) {
                    Enqueue(i*2, Q);
                    printf("%d\n", Front(Q));
          }
          printf("%d\n\n", IsEmpty(Q));
          printf("%d\n\n", IsFull(Q));
          MakeEmpty(Q);
          for (int i = 0; i < 20; i++) {
                    Enqueue(i*3, Q);
                    printf("%d\n", Front(Q));
          }
          DisposeQueue(Q);
}