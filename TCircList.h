#ifndef TCIRCULAR_LIST_H
#define TCIRCULAR_LIST_H
#include <stdbool.h>

typedef struct list_ TCircList;

TCircList *TCircList_create();

bool TCircList_insert_end(TCircList *, int);

_Bool TCircList_delete_the(TCircList* , int);

_Bool TCircList_delete_Ed(TCircList* , int);

void TCircList_print(TCircList *);
#endif