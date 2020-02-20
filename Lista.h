#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Pessoa* ponteiro_Pessoa;
typedef struct Pessoa
{
    int codigo;
    char nome[100];
    char email[100];
}Pessoa;

typedef struct Celula* ponteiro_Celula;
typedef struct Celula
{
    ponteiro_Pessoa pessoa;
    ponteiro_Celula proximo;
}Celula;

typedef struct Lista* ponteiro_Lista;
typedef struct Lista
{
    ponteiro_Celula primeiro, ultimo;
}Lista;

ponteiro_Pessoa CriaPessoa(int codigo, char nome[], char email[]){

    ponteiro_Pessoa pessoa = (ponteiro_Pessoa)malloc(sizeof(Pessoa));

    pessoa->codigo = codigo;
    strcpy(pessoa->nome, nome);
    strcpy(pessoa->email, email);

    return (pessoa);
}

ponteiro_Celula CriaCelula(ponteiro_Pessoa pessoa){

    ponteiro_Celula celula = (ponteiro_Celula)malloc(sizeof(Celula));

    celula->pessoa = pessoa;
    celula->proximo = NULL;

    return (celula);
}

ponteiro_Lista CriaLista(){

    ponteiro_Lista lista = (ponteiro_Lista)malloc(sizeof(Lista));

    lista->primeiro = CriaCelula(CriaPessoa(0, " ", " "));
    lista->ultimo = lista->primeiro;

    return (lista);
}

#endif // LISTA_H_INCLUDED
