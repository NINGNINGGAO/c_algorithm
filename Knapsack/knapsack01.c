/*
 * @Author: AGOGIN
 * @Date: 2019-09-16 09:51:39
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-18 11:03:45
 */

#include <stdio.h>
#include <string.h>

#define Max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int V[n], W[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &(V[i]), &(W[i]));
    }
    int f[m + 1];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= V[i]; j--) {
            f[j] = Max(f[j], f[j - V[i]] + W[i]);
        }
    }
    printf("%d\n", f[m]);

    /*int f[n + 1][m + 1];
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= V[i - 1]) {
                f[i][j] = Max(f[i][j], f[i - 1][j - V[i - 1]] + W[i - 1]);
            }
        }
    }
    printf("%d\n", f[n][m]);*/
}