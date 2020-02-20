#ifndef OPERACOES_H_INCLUDED
#define OPERACOES_H_INCLUDED

int VerificaListaVazia(Lista lista){

    return (lista.primeiro == lista.ultimo);
}

void InserirNaLista(ponteiro_Lista lista, ponteiro_Celula celula){

    ponteiro_Celula suporte = lista->primeiro, suporte_j = suporte->proximo;

    while (suporte_j && suporte_j->pessoa->codigo < celula->pessoa->codigo)
    {

        suporte = suporte_j;
        suporte_j = suporte_j->proximo;
    }

    celula->proximo = suporte_j;
    suporte->proximo = celula;

    if(suporte == lista->ultimo){

        lista->ultimo = suporte->proximo;
    }
}

ponteiro_Pessoa BuscarNaLista(Lista lista, int codigo){

    if(!VerificaListaVazia(lista)){

        ponteiro_Celula suporte = lista.primeiro->proximo;

        while (suporte && suporte->pessoa->codigo != codigo)
        {
            suporte = suporte->proximo;
        }

        if(suporte){

            return (suporte->pessoa);
        }else{

            return (NULL);
        }

    }else{

        return (NULL);
    }
}

void RemoverDaLista(ponteiro_Lista lista, int codigo){

    if(BuscarNaLista(*lista, codigo)){

        ponteiro_Celula suporte = lista->primeiro, remover_celula = lista->primeiro->proximo;
        ponteiro_Pessoa remover_pessoa;

        while (remover_celula && remover_celula->pessoa->codigo != codigo)
        {
            suporte = remover_celula;
            remover_celula = remover_celula->proximo;
        }

        if(remover_celula == lista->ultimo){
            lista->ultimo = suporte;
        }

        remover_pessoa = remover_celula->pessoa;

        printf("\n--------------------------------------------------------\n");

        printf("\nCodigo: %d Removido - Nome: %s | email: %s\n", remover_pessoa->codigo, remover_pessoa->nome, remover_pessoa->email);

        printf("\n--------------------------------------------------------\n");

        suporte->proximo = remover_celula->proximo;

        remover_celula->proximo = NULL;

        free(remover_pessoa);
        free(remover_celula);

    }else{

        if(codigo == 0){

            printf("\nRemocao cancelada\n");
        }else
        {

            printf("\nCodigo nao encontrado\n");
        }
    }
}

void MudarRegistro(ponteiro_Lista lista, int codigo){

    ponteiro_Pessoa suporte = BuscarNaLista(*lista, codigo);

    if(suporte){

        char nome[100], email[100];

        printf("\n--------------------------------------------------------\n");

        printf("\nDigite o novo nome: ");
        scanf("%s", nome);

        printf("\nDigite o novo email: ");
        scanf("%s", email);

        strcpy(suporte->nome,nome);
        strcpy(suporte->email, email);

        printf("\nDados alterados com sucesso\n");

        printf("\n--------------------------------------------------------\n");

    }else{

        if(codigo == 0){

            printf("\nAlteracao cancelada\n");
        }else{

            printf("\nCodigo nao encontrado\n");
        }
    }
}

void Listar(Lista lista){

    if(!VerificaListaVazia(lista)){

        ponteiro_Celula suporte = lista.primeiro->proximo;

        printf("\n--------------------------------------------------------\n");
        while (suporte)
        {
            printf("\tCodigo: %d - Nome: %s | email: %s\n", suporte->pessoa->codigo, suporte->pessoa->nome, suporte->pessoa->email);
            suporte = suporte->proximo;
        }
        printf("\n--------------------------------------------------------\n");
    }else{

        printf("\nLista Vazia\n");
    }
}

#endif // OPERACOES_H_INCLUDED
