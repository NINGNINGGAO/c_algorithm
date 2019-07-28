/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:35 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:35 
 */
#include <stdio.h>

typedef struct LINK {
    float val;
    struct LINK* prev;
    struct LINK* next;
} Node;

void BucketSort(float* nums, int numsSize) {
          Node B[numsSize], temp[numsSize];
          for (int i = 0; i < numsSize; i++) {
              B[i] = (Node){0, NULL, NULL};
              temp[i] = (Node){nums[i], NULL, NULL};
          }
          Node* mid;
          for (int i = 0; i < numsSize; i++) {
              mid = &B[(int)(numsSize * nums[i])];
              while (mid->next != NULL && temp[i].val >= mid->next->val) {
                  mid = mid->next;
              } 
              temp[i].prev = mid;
              temp[i].next = mid->next;
              if (mid->next != NULL) {
                  mid->next->prev = &temp[i];
              }
              mid->next = &temp[i];
          }
          int j = 0;
          Node* h;
          for (int i = 0; i < numsSize; i++) {
              h = B[i].next;
              while (h != NULL) {
                  nums[j++] = h->val;
                  h = h->next;
              }
          }
}

main() {
    float nums[] = {0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68,0.01,0.05,0.56,0.60,0.88,0.66,0.99};
    int numsSize = sizeof(nums) / sizeof(int);
    BucketSort(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%f\n", nums[i]);
    }
}