#ifndef RPGINFO_H_INCLUDED
#define RPGINFO_H_INCLUDED

struct criatura{
    char nome[25];
    int iniciativa;
    int vida;
};

typedef struct criatura Criatura;

Criatura *criarC(int i, char *n, int v);
void MostrarC(Criatura E);

#endif // RPGINFO_H_INCLUDED
