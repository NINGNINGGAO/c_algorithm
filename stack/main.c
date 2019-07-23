#include <stdio.h>
#include "stack.h"

main() {
          Stack S = CreateStack();
          //printf("%d\n", IsEmpty(S));
          push(5, S);
          //printf("%d\n", Top(S));
          push(100, S);
          //printf("%d\n", Top(S));
          pop(S);
          //printf("%d\n", Top(S));
          MakeEmpty(S);
          printf("%d\n", Top(S));
}