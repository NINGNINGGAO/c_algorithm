/*
 * @Author: AGOGIN
 * @Date: 2019-09-14 21:03:47
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-14 22:56:18
 */
/*
给定一段长度为n英寸的钢条和一个价格表pi(i=1,2,...,n), 求切割钢条方案，使得销售收益rn最大。
注意，如果长度为n英寸的钢条的价格pn足够大，最优解可能就是完全不需要切割。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

void intcat(int* s, int* ct, int num) {
    for (int i = 1; i <= ct[0]; i++) {
        s[num + i] = ct[i];
    }
}

void solution(int num, int* lens, int* prices, int n, int* max, int** ret) {
    int arr[n + 1];
    memset(arr, 0, sizeof(arr));
    arr[1] = prices[0];
    ret[0] = malloc(sizeof(int));
    ret[0][0] = 0;
    ret[1] = malloc(sizeof(int) * 2);
    ret[1][0] = 1;
    ret[1][1] = 1;
    int temp, tmp;
    int flag;
    for (int i = 2; i < n + 1; i++) {
        flag = 0;
        if (i <= num) {
            tmp = prices[i - 1];
        } else {
            tmp = 0;
        }
        for (int j = 1; j <= i; j++) {
            if (tmp < arr[j] + arr[i - j]) {
                flag = 1;
                tmp = arr[j] + arr[i - j];
                temp = j;
            }
        }
        arr[i] = tmp;
        if (flag == 1) {
            ret[i] = malloc(sizeof(int) * (ret[temp][0] + ret[i - temp][0] + 1));
            memset(ret[i], 0, sizeof(ret[i]));
            ret[i][0] = ret[temp][0] + ret[i - temp][0];
            intcat(ret[i], ret[temp], 0);
            intcat(ret[i], ret[i - temp], ret[temp][0]);
        } else {
            ret[i] = malloc(sizeof(int) * 2);
            ret[i][0] = 1;
            ret[i][1] = i;
        }
    }
    *max = arr[n];
}


int main() {
    int n = 15;
    int num = 10;
    int lens[10] = {1,2,3,4,5,6,7,8,9,10};
    int prices[10] = {1,5,8,9,10,17,17,20,24,30};
    /*int n, num;
    scanf("%d %d", &n, &num);
    int lens[num], prices[num];
    for (int i = 0; i < num; i++) {
        scanf("%d %d", &(lens[i]), &(prices[i]));
    }*/
    int max;
    int* ret[n];
    solution(num, lens, prices, n, &max, ret);
    printf("%d\n", max);
    for (int i = 1; i <= ret[n][0]; i++) {
        printf("%d\n", ret[n][i]);
    }
    return 0;
}