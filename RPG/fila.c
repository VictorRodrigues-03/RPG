#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaencadeada.h"
#include "fila.h"
#include "rpgInfo.h"

struct fila *CriarFila(){
    Fila *li = (Fila*) malloc(sizeof(Fila));
    if(li != NULL){
        li->inicio = NULL;
    }
    return li;
}

void LiberaFila(Fila *li){
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

int TamanhoF(Fila* li){
    if(li != NULL){
        No *aux = li->inicio;
        int cont = 1;
        while(aux->prox != NULL){
            cont++;
            aux = aux->prox;
        }
        return cont;
    }
    return 0;
}

void MostrarF(Fila *li){
    if(li->inicio != NULL){
        int d;
        int cont = 1;
        No *aux = li->inicio;
        while(aux != NULL){
            printf("O %d a realizar as acoes eh: \n",cont);
            printf("Nome : %s\n", aux->Player.nome);
            printf("Iniciativa : %d\n", aux->Player.iniciativa);
            printf("Vida : %d\n", aux->Player.vida);
            printf("Digite qualquer coisa para continuar:  ");
            scanf(" %d", &d);
            aux = aux->prox;
            cont++;
        }
    }
}

int FilaVazia(Fila *li){
    if(li == NULL) return -1;
    if(li->inicio == NULL)
        return 0;
    else
        return 1;
}


int InserirFinalF(Fila *li, Criatura it){
    if(FilaVazia(li) == 0){
        No *novo = (No*) malloc(sizeof(No));
        novo->Player = it;
        novo->prox = NULL;
        li->inicio = novo;
        return 0;
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


int RemoverInicioF(Fila *li){
    if(li == NULL) return 2;
    if(FilaVazia(li) == 0) return 1;
    No *aux = li->inicio;
    li->inicio = aux->prox;
    free(aux);
    return 0;
}


int RemoverPosicaoF(Fila *li, int P){
    if(li->inicio == NULL) return 2;
    if(P == 0) RemoverInicioF(li);
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

No* BuscarPosicaoF(Fila *li, int P){
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


