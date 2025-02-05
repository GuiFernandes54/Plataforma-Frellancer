#include <stdio.h>
#include "freelancers.h"
#include "clientes.h"
#include "pagamentos.h"

int main() {
    int opcao;
    
    do {
        printf("\n--- Plataforma de Freelancers ---\n");
        printf("1. Cadastrar Freelancer\n");
        printf("2. Listar Freelancers\n");
        printf("3. Cadastrar Cliente\n");
        printf("4. Listar Clientes\n");
        printf("5. Registrar Pagamento\n");
        printf("6. Listar Pagamentos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFreelancer();
                break;
            case 2:
                listarFreelancers();
                break;
            case 3:
                cadastrarCliente();
                break;
            case 4:
                listarClientes();
                break;
            case 5:
                registrarPagamento();
                break;
            case 6:
                listarPagamentos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
