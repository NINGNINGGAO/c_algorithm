/*
 * @Author: AGOGIN
 * @Date: 2019-11-27 21:58:08
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-11-27 21:58:41
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int main() {

    return 0;
}