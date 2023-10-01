#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaencadeada.h"

Lista *CriarLista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
    }
    return li;
}

void LiberaLista(Lista *li){
    if(li != NULL){
        No *aux;
        No *aux2 = li->inicio;
        while(aux2 != NULL){
            aux = li->inicio;
            aux2 = aux->prox;
            free(aux);
        }
        free(li);
    }
}

int TamanhoL(Lista* li){
    if(li->inicio != NULL){
        No *aux = li->inicio;
        int cont = 1;
        while(aux->prox != NULL){
            cont++;
            aux = aux->prox;
        }
        return cont;
    }
    return -1;
}

void MostrarL(Lista *li){
    if(li->inicio != NULL){
        No *aux;
        aux = li->inicio;
        while(aux != NULL){
            printf("Nome : %s\n", aux->Player.nome);
            printf("Iniciativa : %d\n", aux->Player.iniciativa);
            printf("Vida : %d\n", aux->Player.vida);
            aux = aux->prox;
        }
    }
}

int ListaVazia(Lista *li){
    if(li == NULL) return 2;
    if(li->inicio == NULL) return 0;
    return 1;
}


int InserirInicioL(Lista *li,Criatura it){
    if(li == NULL) return 2;
    No *novo = (No*) malloc(sizeof(No));
    novo->Player = it;
    novo->prox = li->inicio;
    li->inicio = novo;
    return 0;
}

int IserirFinalL(Lista *li,Criatura it){
    if(li == NULL) return 2;
    if(ListaVazia(li) == 0){
        return InserirInicioL(li, it);
    }
    No *aux = li->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    No *novo = (No*) malloc(sizeof(No));
    novo->Player = it;
    novo->prox = NULL;
    aux->prox = novo;
    return 0;
}


int RemoverInicioL(Lista *li){
    if(li == NULL) return 2;
    if(ListaVazia(li) == 0) return 1;
    No *aux = li->inicio;
    li->inicio = aux->prox;
    free(aux);
    return 0;
}

int RemoverFinalL(Lista *li){
    if(li == NULL) return 2;
    if(ListaVazia(li) == 0) return 1;
    No *aux = li->inicio;
    while(aux->prox->prox != NULL){
        aux = aux->prox;
    }
    free(aux->prox);
    aux->prox = NULL;
    return 0;
}

int RemoverPosicaoL(Lista *li, int P){
    if(li == NULL) return 2;
    if(li->inicio == NULL) return 3;
    if(P == 0) RemoverInicioL(li);
    No *aux = li->inicio;
    int C = 0;
    while(C < P - 1){
        aux = aux->prox;
        C++;
    }
    No *aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 0;
}

No *BuscarPosicaoL(Lista *li, int P){
    if(li->inicio == NULL) return NULL;
    if(P == 0) return li->inicio;
    No *aux = li->inicio;
    int C = 0;
    while(C != P){
        aux = aux->prox;
        C++;
    }
    return aux;
}

No* BuscarItemL(Lista *li, int iniciativ){
    if(li == NULL) return -1;
    No *aux = li->inicio;
    while(aux != NULL){
        if(iniciativ == aux->Player.iniciativa){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

int procuraMaior(int maior, int *valor, int *p, Lista *lC){
    int item = 0;
    No *aux;
    while(item < TamanhoL(lC)){
        aux = BuscarPosicaoL(lC,item);
        if(aux->Player.iniciativa > *valor && aux->Player.iniciativa < maior){
            *valor = aux->Player.iniciativa;
            *p = item;
        }
        item++;
    }
    return 1;
}


