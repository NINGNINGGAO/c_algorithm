/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:35 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:35 
 */
#include <stdio.h>

typedef double ElementType;
typedef struct LINK {
    ElementType val;
    struct LINK* next;
} Node;

void BucketSort(ElementType* nums, int p, int q) {
    int Bucketnum = 10;
    Node B[Bucketnum];
    for (int i = 1; i < Bucketnum; i++) {
        B[i] = (Node){0, NULL};
    }
    Node* mid, *temp, *tmp;
    for (int i = p; i <= q; i++) {
        mid = malloc(sizeof(Node));
        *mid = (Node){nums[i], NULL};
        temp = &B[((int)(nums[i] * Bucketnum))];
        while (temp->next != NULL && temp->next->val < mid->val) {
            temp = temp->next;
        }
        tmp = temp->next;
        temp->next = mid;
        mid->next = tmp;
    }
    int j = p;
    for (int i = 0; i < Bucketnum; i++) {
        mid = B[i].next;
        while (mid != NULL) {
            nums[j++] = mid->val;
            mid = mid->next;
        }
    }
}


main() {
    ElementType nums[] = {0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68,0.01,0.05,0.56,0.60,0.88,0.66,0.99};
    int numsSize = sizeof(nums) / sizeof(ElementType);
    BucketSort(nums, 1, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("%f\n", nums[i]);
    }
}