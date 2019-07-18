#include <stdio.h>

typedef struct {
          int val;
          int* next;
} Node;

void BucketSort(int* nums, int numsSize) {
          Node** B = (Node**)malloc(sizeof(Node*) * numsSize);
          for (int i = 0; i < numsSize; i++) {
                    (*B)[i] -> next = NULL;
          }
          for (int i = 0; i < numsSize; i++) {
                    Node* temp;
                    temp -> val = nums[i];
                    temp -> next = (*B)[(int)(numsSize * nums[i])];
                    (*B)[(int)(numsSize * nums[i])] = temp;
          }
          for (int i = 0; i < numsSize; i++) {

          }
}