#include <stdio.h>

typedef struct {
          int val;
          Node* prev;
          Node* next;
} Node;

void BucketSort(int* nums, int numsSize) {
          Node* B = (Node*)malloc(sizeof(Node) * numsSize);
          for (int i = 0; i < numsSize; i++) {
                    B[i] -> prev = NULL;
                    B[i] -> next = NULL;
          }
          for (int i = 0; i < numsSize; i++) {
                    Node* temp;
                    temp -> val = nums[i];
                    temp -> prev = B[(int)(numsSize * nums[i])]; 
                    temp -> next = B[(int)(numsSize * nums[i])] -> next;
                    B[(int)(numsSize * nums[i])] -> next = temp;
          }
          for (int i = 0; i < numsSize; i++) {
                    temp = B[i] -> next;
                    while (temp -> next != NULL) {
                                if ((temp ->next -> val) < (temp -> val)) {
                                            temp -> prev ->next = temp -> next; //delete temp
                                            temp -> next - prev = temp -> prev;  // delete temp
                                            temp -> prev = temp -> next; // insert temp
                                            temp -> next = temp -> next -> next; //insert temp
                                }
                    }

          }
          int j = 0;
          for (int i = 0; i < numsSize; i++) {
              temp = B[i] -> next;
              while (temp != NULL) {
                  nums[j++] = temp -> val;
              }
          }
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3};
    int numsSize = sizeof(nums) / sizeof(int);
    BuckerSort(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }
}