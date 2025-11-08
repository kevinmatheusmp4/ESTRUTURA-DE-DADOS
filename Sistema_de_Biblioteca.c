// CRIANDO UM SISTEMA DE CADASTRO DE BIBLIOTECA SIMPLES

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constantes Globais

#define MAX_LIVROS 50
#define TAM_STRINGS 100

// Estrutura para representar um livro

typedef struct {
    char titulo[TAM_STRINGS];
    char autor[TAM_STRINGS];
    char editora[TAM_STRINGS];
    int anoPublicacao;
    int disponivel; // 1 para disponível, 0 para emprestado
} Livro;

// Funçao para limpar o buffer de entrada
void limparBuffer() {
    int c; // Variável para armazenar os caracteres do buffer
    while ((c = getchar()) != '\n' && c != EOF); // Limpa até o final da linha ou EOF - EOF é End Of File
};

// Função para adicionar um livro à biblioteca

int main () {
    Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    do {
        printf ("BEM VINDO AO SISTEMA DE BIBLIOTECA\n");
        printf ("=============================\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Emprestar Livro\n");
        printf("4. Devolver Livro\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer(); // Limpa o buffer após a leitura do inteiro

        switch (opcao) {
            case 1:
                if (totalLivros < MAX_LIVROS) {
                    Livro novoLivro;
                    printf("Digite o título do livro: ");
                    fgets(novoLivro.titulo, TAM_STRINGS, stdin);
                    novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = 0; // Remove o '\n' do final

                    printf("Digite o autor do livro: ");
                    fgets(novoLivro.autor, TAM_STRINGS, stdin);
                    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = 0;

                    printf("Digite a editora do livro: ");
                    fgets(novoLivro.editora, TAM_STRINGS, stdin);
                    novoLivro.editora[strcspn(novoLivro.editora, "\n")] = 0;

                    printf("Digite o ano de publicação: ");
                    scanf("%d", &novoLivro.anoPublicacao);
                    limparBuffer(); // Limpa o buffer após a leitura do inteiro

                    novoLivro.disponivel = 1; // Livro está disponível
                    biblioteca[totalLivros++] = novoLivro;
                    printf("Livro adicionado com sucesso!\n");
                } else {
                    printf("Capacidade máxima de livros atingida!\n");
                }
                break; // parada da funçao

            case 2: // Listar livros
                printf("\n=== Lista de Livros ===\n");
                for (int i = 0; i < totalLivros; i++) {
                    printf("%d. %s by %s (%d) - %s\n", i + 1, biblioteca[i].titulo, biblioteca[i].autor,
                           biblioteca[i].anoPublicacao,
                           biblioteca[i].disponivel ? "Disponível" : "Emprestado");
                }
                break;

            case 3: { // Emprestar livro
                int livroIndex;
                printf("Digite o número do livro para emprestar: ");
                scanf("%d", &livroIndex);
                limparBuffer(); // Limpa o buffer após a leitura do inteiro

                if (livroIndex > 0 && livroIndex <= totalLivros) {
                    if (biblioteca[livroIndex - 1].disponivel) { // Se o livro está disponível
                        biblioteca[livroIndex - 1].disponivel = 0; // Marca como emprestado
                        printf("Livro emprestado com sucesso!\n");
                    } else {
                        printf("Livro já está emprestado!\n"); // Livro não disponível
                    }
                } else {
                    printf("Número de livro inválido!\n"); // Caso de uma entrada inválida
                }
                break;
            }

            case 4: { // Devolver livro
                int livroIndex;
                printf("Digite o número do livro para devolver: ");
                scanf("%d", &livroIndex);
                limparBuffer(); // Limpa o buffer após a leitura do inteiro
                
                // Verifica se o índice do livro é válido
                // SISTEMA PARA DEVOLUÇÃO DE LIVROS
                if (livroIndex > 0 && livroIndex <= totalLivros) {
                    if (!biblioteca[livroIndex - 1].disponivel) { // Se o livro está emprestado
                        biblioteca[livroIndex - 1].disponivel = 1; // Marca como disponível
                        printf("Livro devolvido com sucesso!\n\n");
                    } else {
                        printf("Livro já está disponível na biblioteca!\n\n");
                    }
                } else {
                    printf("Número de livro inválido!\n\n"); // Caso de uma entrada inválida
                }
                break;
            }   

            case 5: // Sair
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");

        }

    } while (opcao != 5); // Continua até o usuário escolher sair
    return 0;
}
// Fim do código do sistema de biblioteca
            