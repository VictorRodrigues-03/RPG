#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED
#include "rpgInfo.h"

struct no{
    struct criatura Player;
    struct no *prox;
};

struct lista{
    struct no *inicio;
};

typedef struct lista Lista;
typedef struct no No;

Lista* CriarLista();
void LiberaLista(Lista *li);
int TamanhoL(Lista* li);
void MostrarL(Lista *li);
int InserirInicioL(Lista *li,Criatura it);
int IserirFinalL(Lista *li, Criatura it);
int RemoverInicioL(Lista *li);
int RemoverFinalL(Lista *li);
int RemoverPosicaoL(Lista *li, int P);
No* BuscarPosicaoL(Lista *li, int P);
No* BuscarItemL(Lista *li, int iniciativ);
int procuraMaior(int maior, int *valor, int *p, Lista *lC);

#endif // LISTAENCADEADA_H_INCLUDED
