#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "listaencadeada.h"
#include "rpgInfo.h"

struct fila{
    struct no *inicio;
    struct no *fim;
};

typedef struct fila Fila;

Fila* CriarFila();
void LiberaFila(Fila *li);
int TamanhoF(Fila* li);
void MostrarF(Fila *li);
int InserirFinalF(Fila *li, Criatura it);
int RemoverInicioF(Fila *li);
int RemoverPosicaoF(Fila *li, int P);
No* BuscarPosicaoF(Fila *li, int P);


#endif // FILA_H_INCLUDED
