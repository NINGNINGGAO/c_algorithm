/*
 * @Author: AGOGIN
 * @Date: 2019-09-17 15:43:10
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-19 11:13:23
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    /*int n, m;
    scanf("%d %d", &n, &m);
    int f[m + 1];
    memset(f, 0, sizeof(f));
    int v, w, s;
    int mid = 0;
    int value[13 * n], weight[13 * n];
    memset(value, 0, sizeof(value));
    memset(weight, 0, sizeof(weight));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &v, &w, &s);
        for (int k = 1; k <= s; k <<= 1) {
            s -= k;
            value[mid] = k * v;
            weight[mid++] = k * w;
        }
        if (s > 0) {
            value[mid] = s * v;
            weight[mid++] = s * w;
        }
    }
    for (int i = 0; i < mid; i++) {
        for (int j = m; j >= value[i]; j--) {
            f[j] = Max(f[j], f[j - value[i]] + weight[i]);
        }
    }
    printf("%d\n", f[m]);*/
    int n, m;
    scanf("%d %d", &n, &m);
    int mid = 1;
    int v, w, s;
    int value[13 * n], weight[13 * n];
    memset(value, 0, sizeof(value));
    memset(weight, 0, sizeof(weight));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &v, &w, &s);
        for (int k = 1; k <= s; k <<= 1) {
            s -= k;
            value[mid] = k * v;
            weight[mid++] = k * w;
        }
        if (s > 0) {
            value[mid] = s * v;
            weight[mid++] = s * w;
        }
    }
    int f[mid][m + 1];
    memset(f, 0, sizeof(f));
    for (int i = 1; i < mid; i++) {
        for (int j = m; j >= 0; j--) {
            f[i][j] = f[i - 1][j];
            if (j >= value[i]) {
                f[i][j] = Max(f[i][j], f[i - 1][j - value[i]] + weight[i]);
            }
        }
    }
    printf("%d\n", f[mid - 1][m]);
    return 0;
}