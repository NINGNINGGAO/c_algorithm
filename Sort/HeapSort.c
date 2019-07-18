#include <stdio.h>

void Max_Heapify(int* nums, int numsSize, int i) {
          int l = 2 * i + 1, r = 2 * i + 2;
          int largest = i;
          int temp;
          if (l < numsSize && nums[l] > nums[largest]) {
                    largest = l;
          }
          if (r < numsSize && nums[r] > nums[largest]) {
                    largest = r;
          }
          if (largest != i) {
                    temp = nums[i];
                    nums[i] = nums[largest];
                    nums[largest] = temp;
                    Max_Heapify(nums, numsSize, largest);
          }
}

void Build_Max_Heap(int* nums,int numsSize) {
          for (int i = (numsSize >> 1) - 1; i >= 0; i--) { //Introduction to algorithms p85 6.1-7
                    Max_Heapify(nums, numsSize, i);
          }
}

void HeapSort(int* nums, int numsSize) {
          Build_Max_Heap(nums, numsSize);
          int temp;
          for (int i = numsSize - 1; i >= 1; i--) {
                    temp = nums[i];
                    nums[i] = nums[0];
                    nums[0] = temp;
                    numsSize--;
                    Max_Heapify(nums, numsSize, 0);
          }
}

main() {
          int nums[] ={7,8,9,4,5,6,1,2,3,0};
          int numsSize = sizeof(nums) / sizeof(int);
          HeapSort(nums, numsSize);
          for (int i = 0; i < numsSize; i++) {
                    printf("%d\n", nums[i]);
          }
}