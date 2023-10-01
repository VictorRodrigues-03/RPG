#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rpgInfo.h"

Criatura *criarC(int i, char *n, int v){
    Criatura *C = (Criatura *) malloc(sizeof(Criatura));
    C->iniciativa = i;
    strcpy(C->nome,n);
    C->vida = v;
}

void MostrarC(Criatura E){
    printf("Nome: %s\n", E.nome);
    printf("Iniciativa: %d\n", E.iniciativa);
    printf("Vida: %d\n", E.vida);
    return ;
}
