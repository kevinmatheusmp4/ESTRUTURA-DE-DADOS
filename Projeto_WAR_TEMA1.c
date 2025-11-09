// ===== PROJETO WAR ======

#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5 // Número máximo de territórios

typedef struct {
    char nome[30];
    char cor [20];
    int tropas;
} Territorio;

// Funçao para limpar o buffer de entrada
void limparBuffer() {
    int c; // Variável para armazenar os caracteres do buffer
    while ((c = getchar()) != '\n' && c != EOF); // Limpa até o final da linha ou EOF - EOF é End Of File
};

// Funçao para Cadastro de territórios

void cadastrarTerritorios(Territorio territorios[], int *totalTerritorios) {
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Digite o nome do território %d: ", i + 1);
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = 0; // Remove o '\n' do final

        printf("Digite a cor do território %d: ", i + 1);
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0; // Remove o '\n' do final

        printf("Digite o número de tropas no território %d: ", i + 1);
        scanf("%d", &territorios[i].tropas);
        limparBuffer(); // Limpa o buffer após a leitura

        (*totalTerritorios)++;
    }
}

// Função para exibir os territórios cadastrados

void exibirTerritorios(Territorio territorios[], int totalTerritorios) {
    printf("\n=== Territórios Cadastrados ===\n");
    for (int i = 0; i < totalTerritorios; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Número de Tropas: %d\n\n", territorios[i].tropas);
    }
}

// FUNÇAO PRINCIPAL

int main () {

    Territorio territorios[MAX_TERRITORIOS];
    int totalTerritorios = 0;

    cadastrarTerritorios(territorios, &totalTerritorios);
    exibirTerritorios(territorios, totalTerritorios);

    return 0;

}
