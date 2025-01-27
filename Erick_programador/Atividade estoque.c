#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[51];
    int quantidade;
    float preco;
} Produto;

Produto estoque[MAX_PRODUTOS];
int totalProdutos = 0;

void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos cadastrados atingido.\n");
        return;
    }

    Produto novoProduto;

    printf("Digite o ID do produto: ");
    scanf("%d", &novoProduto.id);
    getchar(); // Limpa o buffer do teclado

    printf("Digite o nome do produto: ");
    fgets(novoProduto.nome, sizeof(novoProduto.nome), stdin);
    novoProduto.nome[strcspn(novoProduto.nome, "\n")] = 0; // Remove a nova linha

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novoProduto.quantidade);

    printf("Digite o preço do produto: ");
    scanf("%f", &novoProduto.preco);

    estoque[totalProdutos] = novoProduto;
    totalProdutos++;

    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\nLista de Produtos:\n");
    printf("ID\tNome\t\tQuantidade\tPreço\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("%d\t%-15s\t%d\t\t%.2f\n", estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
    }
}

void atualizarEstoque() {
    int id, quantidade;
    printf("Digite o ID do produto que deseja atualizar: ");
    scanf("%d", &id);

    // Busca o produto pelo ID
    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].id == id) {
            printf("Produto encontrado: %s\n", estoque[i].nome);
            printf("Quantidade atual: %d\n", estoque[i].quantidade);
            printf("Digite a quantidade a ser adicionada (use valor negativo para diminuir): ");
            scanf("%d", &quantidade);

            // Atualiza a quantidade
            if (estoque[i].quantidade + quantidade < 0) {
                printf("Erro: A quantidade não pode ficar negativa.\n");
            } else {
                estoque[i].quantidade += quantidade;
                printf("Estoque atualizado com sucesso! Nova quantidade: %d\n", estoque[i].quantidade);
            }
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

void buscarProduto() {
    int id;
    char nome[51];
    int found = 0;

    printf("Escolha a forma de busca:\n");
    printf("1. Buscar pelo ID\n");
    printf("2. Buscar pelo nome\n");
    printf("Escolha uma opção: ");
    int opcao;
    scanf("%d", &opcao);
    getchar(); // Limpa o buffer do teclado

    if (opcao == 1) {
        printf("Digite o ID do produto: ");
        scanf("%d", &id);

        // Busca o produto pelo ID
        for (int i = 0; i < totalProdutos; i++) {
            if (estoque[i].id == id) {
                printf("\nProduto encontrado:\n");
                printf("ID: %d\nNome: %s\nQuantidade: %d\nPreço: %.2f\n", estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Produto com ID %d não encontrado.\n", id);
        }
    } else if (opcao == 2) {
        printf("Digite o nome do produto (parcial ou total): ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0; // Remove a nova linha

        printf("\nResultados da busca:\n");
        for (int i = 0; i < totalProdutos; i++) {
            if (strstr(estoque[i].nome, nome) != NULL) {
                printf("ID: %d\nNome: %s\nQuantidade: %d\nPreço: %.2f\n", estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i ].preco);
                found = 1;
            }
        }
        if (!found) {
            printf("Nenhum produto encontrado com o nome '%s'.\n", nome);
        }
    } else {
        printf("Opção inválida.\n");
    }
}

void excluirProduto() {
    int id;
    printf("Digite o ID do produto que deseja excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].id == id) {
            for (int j = i; j < totalProdutos - 1; j++) {
                estoque[j] = estoque[j + 1]; // Move os produtos para preencher o espaço
            }
            totalProdutos--;
            printf("Produto com ID %d excluído com sucesso!\n", id);
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

void calcularValorTotal() {
    float valorTotal = 0.0;
    for (int i = 0; i < totalProdutos; i++) {
        valorTotal += estoque[i].quantidade * estoque[i].preco;
    }
    printf("Valor total em estoque: R$ %.2f\n", valorTotal);
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Atualizar Estoque\n");
        printf("4. Buscar Produto\n");
        printf("5. Excluir Produto\n");
        printf("6. Calcular Valor Total em Estoque\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                atualizarEstoque();
                break;
            case 4:
                buscarProduto();
                break;
            case 5:
                excluirProduto();
                break;
            case 6:
                calcularValorTotal();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}