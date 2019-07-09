int* SelectionSort(int* nums, int numsSize) {
    int i, j, k, temp;
    for (i = 0; i < numsSize - 1; i++) {
        k = i;
        for (j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
    return nums;
}