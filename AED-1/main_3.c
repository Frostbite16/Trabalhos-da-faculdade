//Faca um programa que receba um n�mero inteiro, positivo N, pela linha de comando,
//calcule e mostre o maior quadrado menor ou igual a N.
//Por exemplo, se N for maior ou igual a 38, o menor quadrado � 36 (quadrado de 6).
//Por exemplo, se N for maior ou igual a 48, o menor quadrado � 36 (quadrado de 6).
//Por exemplo, se N for maior ou igual a 95, o menor quadrado � 81 (quadrado de 9).


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAIDA_1 "\nSAIDA_1 = O maior quadrado menor ou igual a N vale: %d\n"
#define SAIDA_2 "\nSAIDA_2 = N invalido, deve ser um valor positivo!\n"
#define SAIDA_3 "\nSAIDA_3 = Quantidade de argumento invalido!\n"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int N = atoi(argv[1]);

        if (N <= 0) {
            printf(SAIDA_2);
            return 0;
        }

        int maiorQuadrado = 0;
        int i = 1;
        while ((i * i) <= N) {
            maiorQuadrado = i * i;
            i++;
        }

        printf(SAIDA_1, maiorQuadrado);
    } else {
        printf(SAIDA_3);
        return -1;
    }

    return 0;
}