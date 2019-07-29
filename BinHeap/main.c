/*
 * @Author: AGOGIN 
 * @Date: 2019-07-29 20:53:41 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-07-29 22:24:36
 */
#include "BinHeap.h"
#include <stdio.h>

main() {
          PriorityQueue H = Initialize(10);
          printf("%d\n", IsEmpty(H));
          printf("%d\n\n", IsFull(H));
          int a[10] = {68,35,26,32,13, 21,16,24,31,19};
          for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
                    Insert(a[i], H);
          }
          printf("%d\n", IsEmpty(H));
          printf("%d\n\n", IsFull(H));
          for (int i = 1; i <= sizeof(a) / sizeof(int); i++) {
                    printf("%d\n", H->Elements[i]);
          }
          printf("%d\n\n", FindMin(H));
          for (int i = 1; i < sizeof(a) / sizeof(int) - 2; i++) {
                    printf("%d\n", DeleteMin(H));
          } 
          MakeEmpty(H);
          printf("%d\n", IsEmpty(H));
          printf("%d\n", IsFull(H));
          Destroy(H);
          printf("%d\n", IsEmpty(H));
          printf("%d\n", IsFull(H));

}