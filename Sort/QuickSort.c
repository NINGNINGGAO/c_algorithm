#include <stdio.h>

int partition(int* nums, int p, int r) {
          int x = nums[r];
          int i = p - 1;
          int temp;
          for (int j = p; j < r; j++) {
                    if (nums[j] <= x) {
                              i = i + 1;
                              temp = nums[i];
                              nums[i] = nums[j];
                              nums[j] = temp;
                    }
          }
          nums[r] = nums[i + 1];
          nums[i + 1] = x;
          return i + 1;
}

void Quick(int* nums, int p, int r) {
          if (p < r) {
                    int q = partition(nums, p, r);
                    Quick(nums, p, q - 1);
                    Quick(nums, q, r);
          }
}

void QuickSort(int* nums, int numsSize) {
          int p = 0, r = numsSize - 1;
          Quick(nums, p, r);
}

main() {
          int nums[] = {7,8,9,4,5,6,1,2,3,0,17,18,19,14,15,16,11,12,13,10};
          int numsSize = sizeof(nums) / sizeof(int);
          QuickSort(nums, numsSize);
          for (int i = 0; i < numsSize; i++) {
                    printf("%d\n", nums[i]);
          }
}