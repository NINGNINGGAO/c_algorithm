int* InsertionSort(int* nums, int numsSize) {
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

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3};
    int numsSize = sizeof(nums)/sizeof(int);
    //printf("%d\n", numsSize);
    int* p = InsertionSort(nums, numsSize);
    while (*p != '\0') {
        printf("%d\n",*p);
        p++;
    }
}