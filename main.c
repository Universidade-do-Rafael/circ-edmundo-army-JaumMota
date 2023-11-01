#include "TCircList.h"
#include <stdio.h>

int main(void) {
  TCircList *clist = TCircList_create();

  int N, M;
  scanf("%d %d", &N, &M);
  for(int i = 1 ;i <= N; i++){
    TCircList_insert_end(clist, i);
  }

  TCircList_delete_Ed(clist ,M);
  
  TCircList_print(clist);
  
  return 0;
}