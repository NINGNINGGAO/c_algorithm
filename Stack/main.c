/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:22 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:22 
 */
#include <stdio.h>
#include "Stack.h"

main() {
          Stack S = CreateStack();
          printf("%d\n", IsEmpty(S));
          push(5, S);
          printf("%d\n", Top(S));
          push(100, S);
          printf("%d\n", Top(S));
          pop(S);
          printf("%d\n", Top(S));
          MakeEmpty(S);
          printf("%d\n", Top(S));
}