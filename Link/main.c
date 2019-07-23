#include <stdio.h>
#include "Link.h"

main() {
          List L;
          L = MakeEmpty(L);

          printf("%d\n", L->Element);
          Insert(1, L, L);
          printf("%d\n", L->Next->Element);
}