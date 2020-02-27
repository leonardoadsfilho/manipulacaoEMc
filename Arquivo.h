#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

void GravarArquivo(Lista lista, FILE* arquivo){


    if(!VerificaListaVazia(lista)){

        ponteiro_Celula suporte = lista.primeiro->proximo;

        fwrite(&lista.quantidade, sizeof(int), 1, arquivo);

        while(suporte){

            fwrite(suporte->pessoa, sizeof(Pessoa), 1, arquivo);

            suporte = suporte->proximo;
        }

        printf("\nArquivo Gravado com sucesso\n");
    }else{

        printf("\nNenhum dado para ser gravado\n");
    }
}
void LerArquivo(Lista lista, FILE* arquivo){

    Pessoa pessoa;
    int quantidade = 0;

    fread(&quantidade, sizeof(int), 1, arquivo);

    for(int c = 0; c < quantidade; c++){

        fread(&pessoa, sizeof(Pessoa), 1, arquivo);
        printf("\tCodigo: %d - Nome: %s | email: %s\n", pessoa.codigo, pessoa.nome, pessoa.email);
    }

    printf("\nLeitura finalizada\n");
}

void PesquisaBinariaNoArquivo(FILE* arquivo, int codigo){

    int quantidade = 0, inicio = 0, meio = 0, fim = 0, seek_posicao = 0;
    Pessoa suporte, pessoa;

    suporte.codigo = -1;

    pessoa = suporte;

    fread(&quantidade, sizeof(int), 1, arquivo);

    fim = quantidade;

    while (inicio <= fim){

        meio = (inicio + fim)/2;

        seek_posicao = fseek(arquivo, (sizeof(Pessoa) * (meio)) + sizeof(int), SEEK_SET);

        if(seek_posicao != 0){
            printf("\nErro na busca.\n"); break;
        }

        fread(&suporte, sizeof(Pessoa), 1, arquivo);

        if(codigo < suporte.codigo) fim = meio-1;
        else if(codigo > suporte.codigo) inicio = meio+1;
        else{
            pessoa = suporte; break;
        }
    }

    fclose(arquivo);

    if(pessoa.codigo == -1){
        printf("\nCodigo nao encontrado\n");
    }else{
        printf("\tCodigo:%d - Nome: %s - email: %s\n", pessoa.codigo, pessoa.nome, pessoa.email);
    }
}

void OperacoesArquivo(Lista lista, int operacao){

    FILE* arquivo;

    switch (operacao)
    {
    case 0:
        arquivo = fopen("arquivo.bin", "wb");
        arquivo ? GravarArquivo(lista, arquivo) : printf("\nNao foi possivel completar a operacao\n");
        break;

    case 1:
        arquivo = fopen("arquivo.bin", "rb");
        arquivo ? LerArquivo(lista, arquivo) : printf("\nNao foi possivel completar a operacao\n");
        break;

    case 3:
        arquivo = fopen("arquivo.bin", "rb");
        arquivo ? PesquisaBinariaNoArquivo(arquivo, Confirmar(lista, 3)) : printf("\nNao foi possivel completar a operacao\n");
    }

    fclose(arquivo);
}

#endif // ARQUIVO_H_INCLUDED
