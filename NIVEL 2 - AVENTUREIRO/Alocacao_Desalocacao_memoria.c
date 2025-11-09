/*

ALOCAÇAO E DESALOCACAO DINAMICA DE MEMORIA (malloc, calloc e free)

é o local onde os dados e as instruções de um programa são armazenados por um tempo durante sua execução.

ALOCAÇAO ESTÁTICA
é quando a memória é alocada em tempo de compilação. Isso significa que o tamanho
e a quantidade de memória necessária são determinados antes do programa ser executado.
Variáveis locais e globais são exemplos de alocação estática.


ALOCAÇAO DINAMICA
é quando a memória é alocada em tempo de execução, ou seja, enquanto o programa está rodando.
Isso permite que o programa solicite memória conforme necessário, o que é útil para
estruturas de dados que podem crescer ou diminuir de tamanho, como listas ligadas, árvores
e outros tipos de coleções dinâmicas.


MALLOC - Memory ALLOcation
A função malloc (memory allocation) é usada para alocar um bloco de memória de um tamanho
específico. Ela retorna um ponteiro para o início do bloco de memória alocado. Se a alocação falhar, ela retorna NULL.


int* vetor = (int*)malloc(5 * sizeof(int));

CALLOC - Clear ALLOcation

Aloca e inicializa todos os bytes com zero.

A função calloc também aloca memória, mas inicializa todos os bytes com zero. Ela recebe dois parâmetros: a quantidade de elementos e o tamanho de cada um.

int* vetor = (int*)calloc(5, sizeof(int));

FREE - Liberação de Memória

A função free é usada para liberar a memória que foi previamente alocada com malloc ou calloc. Isso é importante para evitar vazamentos de memória,
que ocorrem quando a memória alocada não é liberada após o uso.

free(vetor);

// esse "vetor" é o ponteiro retornado por malloc ou calloc.
 

EXEMPLO PRÁTICO

#include <stdio.h>
#include <stdlib.h>

int  *a, b;
:
:
b = 10;
a = (int*) malloc(sizeof(int));
*a = 20;
a = &b;
free(a); // ERRADO! "a" não aponta mais para a memória alocada por malloc

return 0;
}

*/

// EXEMPLO PRÁTICO

#include <stdio.h>
#include <stdlib.h>

int main() {

int  *a, b;

b = 10;
a = (int*) malloc(sizeof(int));
*a = 20;
a = &b;
free(a); // ERRADO! "a" não aponta mais para a memória alocada por malloc

return 0;
}
