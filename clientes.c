#include <stdio.h>
#include "clientes.h"

void cadastrarCliente() {
    char nome[100], servico[100];

    printf("Nome do cliente: ");
    scanf(" %[^\n]", nome);
    printf("Serviço que precisa: ");
    scanf(" %[^\n]", servico);

    FILE *arquivo = fopen("clientes.txt", "a");
    if (arquivo) {
        fprintf(arquivo, "%s;%s\n", nome, servico);
        fclose(arquivo);
        printf("Cliente cadastrado com sucesso!\n");
    } else {
        printf("Erro ao salvar dados!\n");
    }
}

void listarClientes() {
    FILE *arquivo = fopen("clientes.txt", "r");
    char linha[200];

    if (!arquivo) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Clientes ---\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo);
}
