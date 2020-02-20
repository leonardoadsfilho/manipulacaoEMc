#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Lista.h"
#include "Operacoes.h"
#include "Pessoas.h"
#include "Menu.h"
#include "Arquivo.h"

int main(int *argc, char **argv){

    ponteiro_Lista lista_de_pessoas = CriaLista();

    for(;;){

        switch (Menu()){

            case 1:
                InserirNaLista(lista_de_pessoas, InserirPessoa(*lista_de_pessoas));
                fflush(stdin);
                getchar();
                break;

            case 2:
                RemoverDaLista(lista_de_pessoas, Confirmar(*lista_de_pessoas, 0));
                fflush(stdin);
                getchar();
                break;

            case 3:
                MudarRegistro(lista_de_pessoas, Confirmar(*lista_de_pessoas, 1));
                fflush(stdin);
                getchar();
                break;

            case 4:
                Listar(*lista_de_pessoas);
                fflush(stdin);
                getchar();
                break;

            case 5:
                ImprimirPessoa(BuscarNaLista(*lista_de_pessoas, Confirmar(*lista_de_pessoas, 3)));
                fflush(stdin);
                getchar();
                break;

            case 6:
                OperacoesArquivo(*lista_de_pessoas, 0);
                fflush(stdin);
                getchar();
                break;

            case 7:
                OperacoesArquivo(*lista_de_pessoas, 1);
                fflush(stdin);
                getchar();
                break;

            case 0:
                exit(1);
                break;
        }

        system("cls");
    }

    return(0);
}
