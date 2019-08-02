/*
 * @Author: AGOGIN 
 * @Date: 2019-08-02 10:34:20 
 * @Last Modified by: AGOGIN
 * @Last Modified time: 2019-08-02 16:52:10
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void Compute_Prefix(char* nums, int numslen, int Next[]) {
          Next[0] = -1;
          int k = -1;
          for (int q = 1; q < numslen; q++) {
                    while (k >= 0 && nums[q] != nums[k + 1]) {
                              k = Next[k];
                    }
                    if (nums[q] == nums[k + 1]) {
                              k++;
                    }
                    Next[q] = k;
          }
}

int KMP(char* T, int numsTlen, char* P, int numsPlen) {
          int Next[numsPlen];
          Compute_Prefix(P, numsPlen, Next);
          int q = -1;
          int i;
          for (i = 0; i < numsTlen; i++) {
                    while (q >=0 && P[q + 1] != T[i]) {
                              q = Next[q];
                    }
                    if (P[q + 1] == T[i]) {
                              q = q + 1;
                    }
                    if (q == numsPlen - 1) {
                              return i - q;
                    }
          }
          return -1;
}

main() {
          char T[] = "cdabababaca";
          char P[] = "ababaca";
          int numsTlen = strlen(T);
          int numsPlen = strlen(P);
          int ret = KMP(T, numsTlen, P, numsPlen);
          printf("%d\n", ret);
}