/*
 * @Author: AGOGIN
 * @Date: 2019-09-19 11:13:08
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-09-19 16:04:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int f[m + 1];
    memset(f, 0, sizeof(f));
    int v, w, s;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &v, &w, &s);
    }



    return 0;
}