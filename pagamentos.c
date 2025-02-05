#include <stdio.h>
#include "pagamentos.h"

void registrarPagamento() {
    char cliente[100], freelancer[100], metodo[50];
    float valor;

    printf("Nome do cliente: ");
    scanf(" %[^\n]", cliente);
    printf("Nome do freelancer: ");
    scanf(" %[^\n]", freelancer);
    printf("Valor do pagamento: ");
    scanf("%f", &valor);
    printf("Método de pagamento: ");
    scanf(" %[^\n]", metodo);

    FILE *arquivo = fopen("pagamentos.txt", "a");
    if (arquivo) {
        fprintf(arquivo, "%s;%s;%.2f;%s\n", cliente, freelancer, valor, metodo);
        fclose(arquivo);
        printf("Pagamento registrado com sucesso!\n");
    } else {
        printf("Erro ao salvar dados!\n");
    }
}

void listarPagamentos() {
    FILE *arquivo = fopen("pagamentos.txt", "r");
    char linha[200];

    if (!arquivo) {
        printf("Nenhum pagamento registrado.\n");
        return;
    }

    printf("\n--- Pagamentos Realizados ---\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo);
}
