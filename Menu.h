#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int Menu(){

    int opcao = 0;

    printf("\n1- Inserir uma pessoa na lista");
    printf("\n2- Remover uma pessoa da lista");
    printf("\n3- Editar os dados de uma pessoa da lista");
    printf("\n4- Listar os dados de todas as pessoas da lista");
    printf("\n5- Recuperar os dados de uma pessoa da lista");
    printf("\n6- Gravar todos os registros em um arquivo");
    printf("\n7- Ler todos os registros de um arquivo");
    printf("\n0- Sair");
    printf("\n\nSelecione uma opcao: ");
    scanf("%d", &opcao);

    while(opcao < 0 || opcao > 7){

        printf("\nInsira uma opcao valida: ");
        scanf("%d", &opcao);
    }

    return (opcao);
}

#endif // MENU_H_INCLUDED





