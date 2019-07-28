/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:12 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:12 
 */
#include <stdio.h>
#include "Tree.h"

main() {
          SearchTree T = malloc(sizeof(struct TreeNode));
          T->Left = NULL;
          T->Right = NULL;
          T->Element = 10;
          for (int i = 0; i < 10; i++) {
                    T = Insert(i, T);
          }
          for (int i = 11; i < 25; i++) {
                    T = Insert(i, T);
          }
          SearchTree P = Find(5, T);
          printf("%d\n", Retrieve(P));
          P = FindMin(T);
          printf("%d\n", Retrieve(P));
          P = FindMax(T);
          printf("%d\n", Retrieve(P));
          for (int i = 0; i < 10; i++) {
                    T = Delete(i, T);
          }
          P = FindMin(T);
          printf("%d\n", Retrieve(P));
          P = FindMax(T);
          printf("%d\n", Retrieve(P));
          for (int i = 11; i < 25; i++) {
                    T = Delete(i, T);
          }    
          P = FindMin(T);
          printf("%d\n", Retrieve(P));
          P = FindMax(T);
          printf("%d\n", Retrieve(P));      
          for (int i = 0; i < 10; i++) {
                    T = Insert(i, T);
          }
          for (int i = 11; i < 25; i++) {
                    T = Insert(i, T);
          }
          T = MakeEmpty(T);
}