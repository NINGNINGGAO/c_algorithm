/*
 * @Author: AGOGIN
 * @Date: 2019-09-16 11:01:51
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-18 11:04:25
 */
#include <stdio.h>
#include <string.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int f[m + 1];
    memset(f, 0, sizeof(f));
    int v, w;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &v, &w);
        for (int j = v; j <= m; j++) {
            f[j] = Max(f[j], f[j - v] + w);
        }
    }
    printf("%d\n", f[m]);
    /*int f[n + 1][m + 1];
    memset(f, 0, sizeof(f));
    int v, w;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &v, &w);
        for (int j = 1; j <= m; j++) {
            if (j >= v) {
                f[i][j] = Max(f[i - 1][j], f[i][j - v] + w);
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    printf("%d\n", f[n][m]);*/
    return 0;
}