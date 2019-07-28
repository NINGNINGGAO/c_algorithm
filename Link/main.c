/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:07:43 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:07:43 
 */
#include <stdio.h>
#include "Link.h"

main() {
          List L;
          L = MakeEmpty(L);

          printf("%d\n", L->Element);
          Insert(1, L, L);
          printf("%d\n", L->Next->Element);
}