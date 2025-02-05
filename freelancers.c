#include <stdio.h>
#include "freelancers.h"

void cadastrarFreelancer() {
    char nome[100], habilidade[100];

    printf("Nome do freelancer: ");
    scanf(" %[^\n]", nome);
    printf("Habilidade principal: ");
    scanf(" %[^\n]", habilidade);

    FILE *arquivo = fopen("freelancers.txt", "a");
    if (arquivo) {
        fprintf(arquivo, "%s;%s\n", nome, habilidade);
        fclose(arquivo);
        printf("Freelancer cadastrado com sucesso!\n");
    } else {
        printf("Erro ao salvar dados!\n");
    }
}

void listarFreelancers() {
    FILE *arquivo = fopen("freelancers.txt", "r");
    char linha[200];

    if (!arquivo) {
        printf("Nenhum freelancer cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Freelancers ---\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo);
}
