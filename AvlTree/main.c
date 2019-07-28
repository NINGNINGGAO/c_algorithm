/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:07:25 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:07:25 
 */
#include <stdio.h>
#include "AvlTree.h"

main() {
          AvlTree T;
          Position P;
          T = malloc(sizeof(struct AvlNode));
          T->Element = 7;
          T->Parents = NULL;
          T->Left = NULL;
          T->Right = NULL;
          for (int i = 1; i < 7; i++) {
                    if (i == 10) {
                              continue;
                    }
                    T = Insert(i, T);
          }
          for (int i = 1; i < 8; i++) {
                    T = Delete(i, T);
          }
          printf("%d\n", Retrieve(FindMax(T)));
          printf("%d\n", Retrieve(FindMin(T)));
          T = MakeEmpty(T);
          printf("%d\n", Retrieve(FindMax(T)));
          printf("%d\n", Retrieve(FindMin(T)));
}
