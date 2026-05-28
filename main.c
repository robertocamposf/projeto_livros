#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 100

// Definição da Struct
typedef struct {
    int codigo;
    char titulo[100];
    int ano;
    int quantidade;
} Livro;

// Variáveis globais
Livro acervo[MAX_LIVROS];
int totalLivros = 0;

// Função p/ limpar o buffer do espaço no final por causa do enter
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Leitura de Arquivo Texto
void carregarArquivo() {
    FILE *arquivo = fopen("livros.txt", "r");
    if (arquivo == NULL) {
        printf("Aviso: Arquivo livros.txt nao encontrado. Iniciando acervo vazio.\n");
        return;
    }

    // Lê o formato: codigo;titulo;ano;quantidade
    while (totalLivros < MAX_LIVROS && 
           fscanf(arquivo, "%d;%99[^;];%d;%d\n", 
                  &acervo[totalLivros].codigo, 
                  acervo[totalLivros].titulo, 
                  &acervo[totalLivros].ano, 
                  &acervo[totalLivros].quantidade) == 4) {
        totalLivros++;
    }
    fclose(arquivo);
    printf(">> %d livros carregados do arquivo.\n", totalLivros);
}

// Adicionar Livro
void adicionarLivro() {
    if (totalLivros >= MAX_LIVROS) {
        printf("Acervo lotado!\n");
        return;
    }

    Livro novo;
    printf("Codigo: ");
    scanf("%d", &novo.codigo);
    limparBuffer();

    printf("Titulo: ");
    fgets(novo.titulo, 100, stdin);
    novo.titulo[strcspn(novo.titulo, "\n")] = 0; // Remove o \n do fgets

    printf("Ano de publicacao: ");
    scanf("%d", &novo.ano);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    acervo[totalLivros] = novo;
    totalLivros++;
    printf("Livro adicionado com sucesso!\n");
}

//  Algoritmo de Busca (Busca Linear)
void buscarLivro() {
    int codBusca, encontrado = 0;
    printf("Digite o codigo do livro: ");
    scanf("%d", &codBusca);

    for (int i = 0; i < totalLivros; i++) {
        if (acervo[i].codigo == codBusca) {
            printf("\n--- Livro Encontrado ---\n");
            printf("Titulo: %s\nAno: %d\nQuantidade: %d\n", acervo[i].titulo, acervo[i].ano, acervo[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) printf("Livro nao encontrado.\n");
}

// Imprimir Livros
void imprimirLivros() {
    if (totalLivros == 0) {
        printf("Nenhum livro no acervo.\n");
        return;
    }
    printf("\n--- Acervo de Livros ---\n");
    for (int i = 0; i < totalLivros; i++) {
        printf("[%d] %s | Ano: %d | Qtd: %d\n", acervo[i].codigo, acervo[i].titulo, acervo[i].ano, acervo[i].quantidade);
    }
}

// Algoritmo de Ordenacao (Bubble Sort)
void ordenarPorAno() {
    for (int i = 0; i < totalLivros - 1; i++) {
        for (int j = 0; j < totalLivros - i - 1; j++) {
            if (acervo[j].ano > acervo[j+1].ano) {
                Livro temp = acervo[j];
                acervo[j] = acervo[j+1];
                acervo[j+1] = temp;
            }
        }
    }
    printf("Acervo ordenado por ano com sucesso!\n");
    imprimirLivros();
}

int main() {
    carregarArquivo();
    int opcao;

    do {
        printf("\n=== MENU DE LIVROS ===\n");
        printf("1. Adicionar livro\n");
        printf("2. Buscar livro por codigo\n");
        printf("3. Imprimir livros\n");
        printf("4. Ordenar por ano e imprimir\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarLivro(); break;
            case 2: buscarLivro(); break;
            case 3: imprimirLivros(); break;
            case 4: ordenarPorAno(); break;
            case 5: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}