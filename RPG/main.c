#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaencadeada.h"
#include "fila.h"
#include "rpgInfo.h"

int main()
{
    int op;
    Lista *lC = CriarLista();
    Fila *fI = CriarFila();
    printf("Bem Vindo ao Assistente de RPG dos Barcudos\n");
    while(1){
        printf("[1] - Criar Jogadores\n[2] - Criar Monstros\n[3] - Iniciar Jogo\n[4] - Sair\n-->");
        scanf(" %d", &op);
        switch(op){
        case 1:
            addP(lC);
            break;

        case 2:
            addC(lC);
            break;

        case 3:
            IniciarJogo(lC,fI);
            break;

        case 4:
            return 0;
            break;
        }

    }


    LiberaLista(lC);
    LiberaFila(fI);
    return 0;
}


void addP(Lista *lC){
    No *aux;
    char nomeA[25];
    int Iniciativa;
    int Vida;
    printf("Digite o Nome do Personagem a ser Adicionado: ");
    fscanf(stdin,"%s",&nomeA);
    do{
        printf("Digite a Iniciativa do Personagem: ");
        scanf(" %d", &Iniciativa);
    } while(Iniciativa > 20 || Iniciativa <= 0);
    printf("Digite a Vida do Personagem: ");
    scanf(" %d", &Vida);
    Criatura * NovoP = (Criatura *) criarC(Iniciativa,&nomeA,Vida);
    InserirInicioL(lC,*NovoP);
    printf("Jogador Criado: \n");
    aux = BuscarPosicaoL(lC,0);
    MostrarC(aux->Player);
}

void addC(Lista *lC){
    No *aux;
    srand(time(NULL));
    char nomeA[25];
    int Iniciativa;
    int Vida;
    printf("Digite o Nome da Criatura a ser Adicionado: ");
    fscanf(stdin,"%s",&nomeA);
    Iniciativa = (rand() % 19) + 1;
    printf("Digite a Vida da Criatura: ");
    scanf(" %d", &Vida);
    Criatura *NovoP = criarC(Iniciativa,&nomeA,Vida);
    InserirInicioL(lC,*NovoP);
    printf("Criatura Criada: \n");
    aux = BuscarPosicaoL(lC,0);
    MostrarC(aux->Player);
}

void IniciarJogo(Lista *lJ, Fila *fI){
    //int procuraMaior(int item,int maior, int *valor, int *p, Lista *lC);
    int p = 0;
    int valor = 0;
    int maior = 5000;
    int exec = 0;
    int n = 0;
    No *aux;
    do{
        n = procuraMaior(maior,&valor,&p,lJ);
        aux = BuscarPosicaoL(lJ,p);
        InserirFinalF(fI,aux->Player);
        maior = valor;
        valor = 0;
        exec++;
    } while (exec < TamanhoL(lJ));
    MostrarF(fI);
}
