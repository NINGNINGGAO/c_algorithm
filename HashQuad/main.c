/*
 * @Author: AGOGIN 
 * @Date: 2019-07-29 11:04:15 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-07-29 17:49:26
 */
#include "HashQuad.h"
#include <stdio.h>

main() {
          HashTable H = InitializeTable(6);
          H->TableSize = 7;
          int a[5] = {13, 15, 6, 24, 24};
          for (int i = 0; i < 5; i++) {
                    Insert(a[i], H);
          }
          for (int i = 0; i < 5; i++) {
                    Position P = Find(a[i], H);
                    printf("%d\n", P);
          }
          H = ReHash(H);
          printf("%d\n\n", H->TableSize);
          for (int i = 0; i < 5; i++) {
                    Position P = Find(a[i], H);
                    printf("%d\n", P);
          }
          DestroyTable(H);
          for (int i = 0; i < 5; i++) {
                    Position P = Find(a[i], H);
                    printf("%d\n", Retrieve(P, H));
          }
}