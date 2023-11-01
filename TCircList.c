#include "TCircList.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: Implementar os métodos da TCircList.h

typedef struct no{
    int info;
    struct no* prox;
}TNo;

struct list_{
    TNo* inicio;
};

TNo* TNo_createNFill(int);

TCircList *TCircList_create(){
  TCircList* nova = malloc(sizeof(TCircList));
  if(nova!=NULL){
      nova->inicio = NULL;
  } return nova;
}

bool TCircList_insert_end(TCircList *lista, int info){
  TNo* novo = TNo_createNFill(info);
  if(novo==NULL) return false;

  if(lista->inicio == NULL){
    lista->inicio = novo; 
  }
  else{
      //Procurar o elemento do fim
      TNo* aux = lista->inicio;
          while(aux->prox != lista->inicio)
            aux = aux->prox;
      aux->prox = novo;
  }
  novo->prox = lista->inicio;
  return true;
}

_Bool TCircList_delete_Ed(TCircList* lista, int M){
    if(lista->inicio == NULL)
        return false;
    else{
          while(lista->inicio->prox != lista->inicio){
            TNo* aux = lista->inicio;
            for(int i = 0 ; i < M ; i++)
              aux = aux->prox;
              TNo* temp = aux->prox;

            TNo* aux2 = lista->inicio;
            if(aux2->info==aux->info){
              TCircList_delete_the(lista, aux2->info);
            }
            else{
                while(aux2->info != aux->info)
                    aux2 = aux2->prox;
                    TCircList_delete_the(lista, aux2->info);
            }
            //printf("removi o %d", aux2->info);
            lista->inicio = temp;
          }
        }   
    return true;
}

_Bool TCircList_delete_the(TCircList* lista, int num){
    if(lista->inicio == NULL)
        return false;
    else{
        TNo* aux = lista->inicio;
        if(aux->info==num){
            lista->inicio = lista->inicio->prox;
            while(aux->prox->prox != lista->inicio)
              aux = aux->prox;
              aux->prox = lista->inicio;
        }
            
        else{
            while(aux->prox->info != num)
                aux = aux->prox;
                aux->prox = aux->prox->prox;
        }
    }   
    return true;
}

void TCircList_print(TCircList *lista){
  if (lista == NULL || lista->inicio == NULL)
    return;
  
  TNo* aux = lista->inicio;
  do{
      printf("%d", aux->info);
      aux = aux->prox;
  }while(aux!=lista->inicio);
  putchar('\n');
}

TNo* TNo_createNFill(int info){
    TNo* novo = malloc(sizeof(TNo));
    novo->info = info;
    novo->prox = NULL;
    return novo;
}