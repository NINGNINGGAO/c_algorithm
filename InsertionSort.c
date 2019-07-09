int* InsertionSort(int* nums, int numsSIze) {
    int i, j, temp;
    for (i = 0; i < numsSize; i++) {
        temp = nums[i];
        for (j = i - 1; j >= 0 && nums[j] > temp; j--) {
            nums [j + 1] = nums[j];
        }
        nums[j+1] = temp;
    }
    return nums;
}