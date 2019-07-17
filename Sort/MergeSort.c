#include <stdio.h>

void Merging(int* nums, int left, int right) {
          int temp;
          int mid = (left + right) >> 1;
          int i = left, j = mid + 1;
          while (i <= mid && j <= right) {
                    if (nums[i] <= nums[j]) {
                              i++;
                    } else {
                              temp = nums[j];
                              for (int cen = j - 1; cen >= i; cen--) {
                                        nums[cen + 1] = nums[cen];
                              }
                              nums[i] = temp;
                              i++;
                              mid++;
                              j++;
                    }
          }
}

void Merge(int* nums, int left, int right) {
          if (left < right) {
                    int mid = (left + right) >> 1;
                    Merge(nums, left, mid);
                    Merge(nums, mid + 1, right);
                    Merging(nums, left, right);
          }
}

void MergeSort(int* nums, int numsSize) {
          int left, right;
          left = 0;
          right = numsSize - 1;
          Merge(nums, left, right);
}

main() {
          int nums[] = {7,8,9,4,5,6,1,2,3,0,19,18,17,14,15,16,12,11,12};
          int numsSize = sizeof(nums) / sizeof(int);
          MergeSort(nums, numsSize);
          for (int i = 0; i < numsSize; i++) {
                    printf("%d\n", nums[i]);
          }
}

