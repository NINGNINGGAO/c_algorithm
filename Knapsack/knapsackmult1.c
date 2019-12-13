/*
 * @Author: AGOGIN
 * @Date: 2019-09-16 18:03:40
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-17 15:42:54
 */
#include <stdio.h>
#include <string.h>

#define Max(a, b) ((a) > (b) ? (a) : (b))


int main() {
    /*int n, m;
    scanf("%d %d", &n, &m);
    int f[m + 1];
    memset(f, 0, sizeof(f));
    int v, w, s;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &v, &w, &s);
        for (int j = m; j >= v; j--) {
            for (int k = 1; k <= s && k * v <= j; k++) {
                f[j] = Max(f[j], f[j - k * v] + k * w);
            }
        }
    }
    printf("%d\n", f[m]);*/

    int n, m;
    scanf("%d %d", &n, &m);
    int f[n + 1][m + 1];
    memset(f, 0, sizeof(f));
    int v, w, s;
    int temp;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &v, &w, &s);
        for (int j = 1; j <= m; j++) {
            if (j < v) {
                f[i][j] = f[i - 1][j];
            } else {
                temp = f[i - 1][j];
                for (int k = 1; k <= s && k * v <= j; k++) {
                    temp = Max(temp, f[i - 1][j - k * v] + k * w);
                }
                f[i][j] = temp;
            }
        }
    }
    printf("%d\n", f[n][m]);
    return 0;
}