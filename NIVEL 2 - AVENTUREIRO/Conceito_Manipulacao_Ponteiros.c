// CONCEITO E MANIUPULAÇÃO DE PONTEIROS

/*

um ponteiro é uma variável especial que armazena o endereço de memória de outra variável.
No entanto, em vez de guardar um valor, como o número 10 ou a letra A,
o ponteiro guarda onde esse valor está localizado na memória do computador.

Com isso, ele permite que você acesse, modifique e gerencie dados de maneira muito mais flexível e poderosa.


& - Operador "Endereço de": Usado para obter o endereço de memória de uma variável.
* - Operador "DIREÇAO": Usado para acessar ou modificar o valor armazenado

OPERAÇÕES COM PONTEIROS

1. Declaração de Ponteiros:
Para declarar um ponteiro, você usa o operador asterisco (*) antes do nome da variável

int *p; // p é um ponteiro para um inteiro

2. Atribuição de Endereço:

int x = 10;
int *p = &x; // o operador & obtém o endereço de x

3. Acesso ao Valor Apontado:

int valor = *p; // o operador * desreferencia o ponteiro para obter o valor de x


*/


#include <stdio.h>

int main() {
    int x = 10;
    int* p = &x; // ponteiro para x

    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Conteúdo de p: %p\n", p);
    printf("Valor apontado por p: %d\n", *p);

    // Caso queira manipular o valor da variável original através do ponteiro, você pode fazer o seguinte:

    *p = 20; // altera o valor de x para 20

    printf("Novo valor de x: %d\n", x); // agora x é 20

    return 0;
} //no endereço que o ponteiro está apontando.

