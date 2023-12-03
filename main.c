#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX_ATENDIMENTOS 100 // Defina o número máximo de atendimentos

// Estrutura para armazenar informações de atendimento
struct Atendimento {
    char nome[30];
    char cpf[15]; // Tamanho ajustado para comportar cpf com formatação
    int tipoAtendimento;
};

struct Atendimento atendimentos[MAX_ATENDIMENTOS]; // Array para armazenar os atendimentos
int numAtendimentos = 0; // Contador de atendimentos registrados

// Função para cadastrar um novo atendimento
void cadastrarAtendimento() {
    struct Atendimento novoAtendimento;

    printf("\nDigite o nome: ");
    getchar();
    fgets(novoAtendimento.nome, sizeof(novoAtendimento.nome), stdin);
    printf("Digite o CPF: ");
    fgets(novoAtendimento.cpf, sizeof(novoAtendimento.cpf), stdin);
    printf("Escolha o tipo de atendimento:\n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");
    printf(">>> ");
    scanf("%d", &novoAtendimento.tipoAtendimento);

    if (numAtendimentos < MAX_ATENDIMENTOS) {
        atendimentos[numAtendimentos++] = novoAtendimento;
        printf("\nAtendimento registrado com sucesso!\n\n");
    } else {
        printf("\nLimite de atendimentos alcançado.\n\n");
    }
}

// Função para listar todos os atendimentos registrados
void listarTodosAtendimentos() {
    printf("\nListagem de todos os atendimentos registrados:\n");
    for (int i = 0; i < numAtendimentos; ++i) {
        printf("Nome: %s", atendimentos[i].nome);
        printf("CPF: %s", atendimentos[i].cpf);
        printf("Tipo Atendimento: %d\n", atendimentos[i].tipoAtendimento);
        printf("===============================\n");
    }
}

// Função para listar atendimentos por tipo
void listarAtendimentoPorTipo(int tipo) {
    printf("\nListagem de atendimentos para o tipo %d:\n", tipo);
    for (int i = 0; i < numAtendimentos; ++i) {
        if (atendimentos[i].tipoAtendimento == tipo) {
            printf("Nome: %s", atendimentos[i].nome);
            printf("CPF: %s", atendimentos[i].cpf);
            printf("Tipo Atendimento: %d\n", atendimentos[i].tipoAtendimento);
            printf("===============================\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int opcao;
    do {
        printf("Bem-vindo ao sistema de atendimento\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimento por Setor\n");
        printf("4 - Sair\n");
        printf(">>> ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAtendimento();
                break;
            case 2:
                listarTodosAtendimentos();
                break;
            case 3:
                printf("\nDigite o tipo de atendimento para listar: ");
                int tipo;
                scanf("%d", &tipo);
                listarAtendimentoPorTipo(tipo);
                break;
            case 4:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n\n");
        }
    } while (opcao != 4);

    return 0;
}