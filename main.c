#include <stdio.h>
#include <locale.h>

#define MAX_ATENDIMENTOS 100

// Definindo a estrutura para armazenar informações de atendimento
struct Atendimento {
    char nome[30];
    char cpf[15];
    int tipoAtendimento;
};

// Protótipos de função
void cadastrarAtendimento();

void listarTodosAtendimentos();

void listarAtendimentoPorTipo(int tipo);

// Array para armazenar os atendimentos
struct Atendimento atendimentos[MAX_ATENDIMENTOS];
int numAtendimentos = 0;

int main() {
    setlocale(LC_ALL, "portuguese");

    int opcao;

    do {
        // Exibindo o menu principal
        printf("Bem-vindo ao sistema de atendimento\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimento por Setor\n");
        printf("4 - Sair\n>>> ");
        scanf("%d", &opcao);

        // Executando a opção escolhida pelo usuário
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

void cadastrarAtendimento() {
    struct Atendimento novoAtendimento;

    // Capturando informações do novo atendimento
    printf("\nDigite o nome: ");
    getchar();
    fgets(novoAtendimento.nome, sizeof(novoAtendimento.nome), stdin);
    printf("Digite o CPF: ");
    fgets(novoAtendimento.cpf, sizeof(novoAtendimento.cpf), stdin);
    printf("Escolha o tipo de atendimento:\n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n>>> ");
    scanf("%d", &novoAtendimento.tipoAtendimento);

    // Verificando a validade do tipo de atendimento e adicionando-o à lista
    if (numAtendimentos < MAX_ATENDIMENTOS) {
        if (novoAtendimento.tipoAtendimento >= 1 && novoAtendimento.tipoAtendimento <= 4) {
            atendimentos[numAtendimentos++] = novoAtendimento;
            printf("\nAtendimento registrado com sucesso!\n\n");
        } else {
            printf("\nTipo de atendimento inválido. Tente novamente.\n\n");
        }
    } else {
        printf("\nLimite de atendimentos alcançado.\n\n");
    }
}

void listarTodosAtendimentos() {
    // Array de descrições para os tipos de atendimento
    char tiposAtendimentos[4][30] = {
            "Abertura de conta", "Caixa", "Gerente Pessoa Física", "Gerente Pessoa Jurídica"
    };

    // Exibindo todos os atendimentos registrados
    printf("\nListagem de todos os atendimentos registrados:\n");
    for (int i = 0; i < numAtendimentos; ++i) {
        printf("Nome: %s", atendimentos[i].nome);
        printf("CPF: %s", atendimentos[i].cpf);
        printf("Tipo Atendimento: %s\n", tiposAtendimentos[atendimentos[i].tipoAtendimento - 1]);
        printf("===============================\n");
    }
}

void listarAtendimentoPorTipo(int tipo) {
    // Exibindo atendimentos específicos de acordo com o tipo escolhido
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
