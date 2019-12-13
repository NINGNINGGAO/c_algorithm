/*
 * @Author: AGOGIN
 * @Date: 2019-09-14 15:43:12
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-14 20:09:55
 */
/*
Input
    N: clothes nums
    B: money
    S: the max of num of buy the clothes
    P: the price of every clothes
    V: the love of every clothes

output
    Max of total love
    Total price of clothes
    Total num of clothes
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

int solution(int N, int B, int S, int* P, int* V) {
    int arr[B + 1][N + 1];
    int num[B + 1][N + 1];
    int flag[B + 1][N + 1];
    memset(num, 0, sizeof(num));
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < B; i++) {
            arr[i][0] = 0;
    }
    for (int i = 1; i < N; i++) {
        arr[0][i] = 0;
    }
    int temp;
    for (int i = 1; i <= B; i++) {
        for (int j = 1; j <= N; j++) {
            if (P[j - 1] <= i) {
                if (arr[i - P[j - 1]][j - 1] + V[j - 1] >= arr[i][j - 1]) {
                    if (num[i - P[j - 1]][j - 1] < S) {
                        arr[i][j] = arr[i - P[j - 1]][j - 1] + V[j - 1];
                        num[i][j] = num[i - P[j - 1]][j - 1] + 1;
                        flag[i][j] = flag[i - P[j - 1]][j - 1] + P[j - 1];
                    } else {
                        temp = 0;
                        for (int k = 1; k < j; k++) {
                            if (num[i - P[j - 1]][k] < S) {
                                if (arr[i - P[j - 1]][k] > arr[i - P[j - 1]][temp]) {
                                    temp = k;
                                }
                            }
                        }
                        arr[i][j] = arr[i - P[j - 1]][temp] + V[j - 1];
                        num[i][j] = num[i - P[j - 1]][temp] + 1;
                        flag[i][j] = flag[i - P[j - 1]][temp] + P[j - 1];
                    }
                } else {
                    arr[i][j] = arr[i][j - 1];
                    num[i][j] = num[i][j - 1];
                    flag[i][j] = flag[i][j - 1];
                }
            } else {
                temp = 0;
                for (int k = 1; k < j; k++) {
                    if (arr[i][k] > arr[i][temp]) {
                        temp = k;
                    }
                    arr[i][j] = arr[i][temp];
                    num[i][j] = num[i][temp];
                    flag[i][j] = flag[i][temp];
                }
            }
        }
    }
    int* ret = malloc(sizeof(int) * 3);
    ret[0] = arr[B][N];
    ret[1] = num[B][N];
    ret[2] = flag[B][N];
    return ret;
}



int main() {
    int N = 3, B = 6, S = 3;
    scanf("%d %d %d", &N, &B, &S);
    int P[N], V[N];
    //int P[3] = {1,5,6}, V[3] = {100,200,300};
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &(P[i]), &(V[i]));
    }
    int *ret = solution(N, B, S, P, V);
    printf("%d %d %d\n", ret[0], ret[1], ret[2]);
    return 0;
}