#include <stdio.h>

int Parent(int i) {
          return i >> 1;
}

int Left(int i) {
          return 2 * i;
}

int Right(int i) {
          return 2 * i + 1;
}

void Max_Heapify(int* nums, int numsSize, int i) {
          int l = Left(i), r = Right(i);
          int largest = i;
          int temp;
          if (l <= numsSize && nums[l - 1] > nums[i - 1]) {     //As A[1,...,numsSize], so -1
                    largest = l;
          }
          if (r <= numsSize && nums[r - 1] > nums[largest - 1]) {
                    largest = r;
          }
          if (largest != i) {
                    temp = nums[i - 1];
                    nums[i - 1] = nums[largest - 1];
                    nums[largest - 1] = temp;
                    Max_Heapify(nums, numsSize, largest);
          }
}

void Build_Max_Heap(int* nums,int numsSize) {
          for (int i = numsSize >> 1; i >=1; i--) {
                    Max_Heapify(nums, numsSize, i);
          }
}

void HeapSort(int* nums, int numsSize) {
          Build_Max_Heap(nums, numsSize);
          int temp;
          for (int i = numsSize; i >= 2; i--) {
                    temp = nums[i - 1];
                    nums[i - 1] = nums[0];
                    nums[0] = temp;
                    numsSize--;
                    Max_Heapify(nums, numsSize, 1);
                    /*for (int i = 0; i < numsSize; i++) {
                              printf("%d\n", nums[i]);
                    }*/
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