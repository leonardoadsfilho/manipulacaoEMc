#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

void GravarArquivo(Lista lista, FILE* arquivo){


    if(!VerificaListaVazia(lista)){

        ponteiro_Celula suporte = lista.primeiro->proximo;

        while(suporte){

            fprintf(arquivo, "%d;%s;%s", suporte->pessoa->codigo, suporte->pessoa->nome, suporte->pessoa->email);
            if(suporte != lista.ultimo){

                fprintf(arquivo, "\n");
            }

            suporte = suporte->proximo;
        }

        printf("\nArquivo Gravado com sucesso\n");
    }else{

        printf("\nNenhum dado para ser gravado\n");
    }
}
void LerArquivo(Lista lista, FILE* arquivo){

    char linha[300];
    char* pedaco_da_linha;

    do{

        fscanf(arquivo, "%[^\n]s", linha);

        pedaco_da_linha = strtok(linha, ";");

        printf("Codigo: %s - ", pedaco_da_linha);

        pedaco_da_linha = strtok(NULL, ";");

        printf("Nome: %s | ", pedaco_da_linha);

        pedaco_da_linha = strtok(NULL, "\n");

        printf("Email: %s\n", pedaco_da_linha);

    }while(fgetc(arquivo) != EOF);

    printf("\nLeitura finalizada\n");
}

void OperacoesArquivo(Lista lista, int operacao){

    FILE* arquivo;

    switch (operacao)
    {
    case 0:
        arquivo = fopen("arquivo.txt", "w");
        arquivo ? GravarArquivo(lista, arquivo) : printf("\nNao foi possivel completar a operacao\n");
        break;

    case 1:
        arquivo = fopen("arquivo.txt", "r");
        arquivo ? LerArquivo(lista, arquivo) : printf("\nNao foi possivel completar a operacao\n");
        break;
    }

    fclose(arquivo);
}

#endif // ARQUIVO_H_INCLUDED
