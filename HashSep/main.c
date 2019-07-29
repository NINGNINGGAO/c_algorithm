/*
 * @Author: AGOGIN 
 * @Date: 2019-07-29 10:30:17 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-29 10:30:17 
 */
#include "HashSep.h"
#include <stdio.h>

main() {
          HashTable H = InitializeTable(22);
          for (int i = 0; i <= 27; i++) {
                    Insert(i, H);
          }
          for (int i = 0; i <= 28; i++) {
                    Position P = Find(i, H);
                    printf("%d\n", Retrieve(P));
          }
          DestroyTable(H);
          for (int i = 0; i <= 28; i++) {
                    Position P = Find(i, H);
                    printf("%d\n", Retrieve(P));
          }          
}