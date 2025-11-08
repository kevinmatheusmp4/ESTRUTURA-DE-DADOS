/*

STRUCT ENCAPSULAMENTO

Uma struct permite agrupar diferentes informações (de tipos variados) sobre um mesmo objeto.
É um tipo de dado composto que permite agrupar diferentes variáveis sob um mesmo nome,
facilitando a organização de informações relacionadas.

Cada variável em uma struct é chamada de membro ou campo, e pode ter um tipo diferente.


Crie uma struct chamada "Aluno" que contenha os seguintes membros privados:
- nome (string de até 50 caracteres)
- idade (inteiro)
- altura (float)

Implemente funções públicas para:
- definir o nome, idade e altura de uma pessoa
- obter o nome, idade e altura de uma pessoa
- imprimir os detalhes de uma pessoa



*/

// Estrutura SIMPLES que representa um aluno

struct Aluno
{
    char nome[50]; // Nome do aluno
    int idade;     // Idade do aluno
    float media;  // Média do aluno
    /* data */
};

// Mas também podemos usar o Typedef para facilitar a criação de variáveis do tipo struct

typedef struct
{
    char nome[50]; // Nome do aluno
    int idade;     // Idade do aluno
    float media;  // Média do aluno

} Aluno;
 

// Como exibir estes dados?

#include <stdio.h>

// Definindo a estrutura do tipo Aluno
typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno;

int main() {
    // Criando uma variável do tipo Aluno
    Aluno aluno1 = {"João", 20, 8.5};

    // Exibindo os dados do aluno

    printf("Nome: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Média: %.2f\n", aluno1.media);

    return 0;
}