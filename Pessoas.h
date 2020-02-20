#ifndef PESSOAS_H_INCLUDED
#define PESSOAS_H_INCLUDED

ponteiro_Celula InserirPessoa(Lista lista){

    int codigo = 0;
    char nome[100], email[100];

    printf("\nDigite o codigo de pessoa: ");
    scanf("%d", &codigo);

    while(BuscarNaLista(lista, codigo) || codigo <= 0){
        if(codigo > 0){

            printf("\nCodigo ja cadastrado, insira outro:");
        }else{

            printf("\nCodigo invalido, insira outro maior que zero:");
        }

        scanf("%d", &codigo);
    }

    printf("\nDigite o nome da pessoa: ");
    scanf("%s", nome);

    printf("\nDigite o email do(a) %s :", nome);
    scanf("%s", email);

    return (CriaCelula(CriaPessoa(codigo, nome, email)));
}

int Confirmar(Lista lista, int opcao){

    int confirmar = 1;

    if(opcao == 0){

        printf("\nDeseja realmente remover alguem (0 = nao): ");
        scanf("%d", &confirmar);
    }else if(opcao == 1){

        printf("\nDeseja realmente alterar algum dado (0 = nao): ");
        scanf("%d", &confirmar);
    }

    if(confirmar != 0){

        printf("\nDigite o codigo: ");
        scanf("%d", &confirmar);
    }

    return (confirmar);
}

void ImprimirPessoa(ponteiro_Pessoa pessoa){

    if(pessoa){

        printf("\n--------------------------------------------------------\n");

        printf("\tCodigo:%d - Nome: %s - email: %s\n", pessoa->codigo, pessoa->nome, pessoa->email);

        printf("\n--------------------------------------------------------\n");
    }else{

        printf("\nNada encontrado\n");
    }
}

#endif // PESSOAS_H_INCLUDED
