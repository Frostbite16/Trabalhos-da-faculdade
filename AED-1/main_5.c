/*Faca um programa que receba pelo argumento do programa uma lista de numeros inteiros entre 0 e 10.
  O programa deve calcular e mostrar o valor do fatorial de cada numero da lista e tamb�m informar:
  a somatoria dos fatoriais, a m�dia dos fatoriais, o maior fatorial e o segundo menor fatorial.
*/

/* Exemplos de execucao

    1- app.exe
            SAIDA_2 = O_PROGRAMA_NAO_TEM_SAIDA!

    2- app.exe 50
            NUMERO_INVALIDO_LISTA = 50

    3- app.exe 1 2 3
            O_FATORIAL_DE = (1) VALE 1
            O_FATORIAL_DE = (2) VALE 2
            O_FATORIAL_DE = (3) VALE 6
            SOMA_FATORIAL = 9
            MEDIA_FATORIAL = 3.0
            MAIOR_FATORIAL = 6
            SEGUNDO_MENOR_FATORIAL = 2

    4- app.exe 1 -9 3
        O_FATORIAL_DE = (1) VALE 1
        NUMERO_INVALIDO_LISTA = -9
        O_FATORIAL_DE = (3) VALE 6
        SOMA_FATORIAL = 7
        MEDIA_FATORIAL = 3.5
        MAIOR_FATORIAL = 6
        SEGUNDO_MENOR_FATORIAL = 6

    5- app.exe 1 -9
        O_FATORIAL_DE = (1) VALE 1
        NUMERO_INVALIDO_LISTA = -9
        SOMA_FATORIAL = 1
        MEDIA_FATORIAL = 1.0
        MAIOR_FATORIAL = 1
        SAIDA_1 = SEGUNDO_MENOR_FATORIAL_INEXISTENTE

    6- app.exe 3 1 3
        O_FATORIAL_DE = (3) VALE 6
        O_FATORIAL_DE = (1) VALE 1
        O_FATORIAL_DE = (3) VALE 6
        SOMA_FATORIAL = 13
        MEDIA_FATORIAL = 4.3
        MAIOR_FATORIAL = 6
        SEGUNDO_MENOR_FATORIAL = 6
*/


#include <stdio.h>
#include <stdlib.h>

#define SAIDA_O_FATORIAL_VALE "\nO_FATORIAL_DE = (%d) VALE %llu"
#define SAIDA_SOMA_FATORIAL "\nSOMA_FATORIAL = %llu"
#define SAIDA_MEDIA_FATORIAL "\nMEDIA_FATORIAL = %.1f"
#define SAIDA_MAIOR_FATORIAL "\nMAIOR_FATORIAL = %llu"
#define SAIDA_SEGUNDO_MENOR_FATORIAL "\nSEGUNDO_MENOR_FATORIAL = %llu"
#define SAIDA_SEGUNDO_MENOR_FATORIAL_INEXISTENTE "\nSAIDA_1 = SEGUNDO_MENOR_FATORIAL_INEXISTENTE"
#define SAIDA_NUMERO_INVALIDO_LISTA "\nNUMERO_INVALIDO_LISTA = %d"
#define SAIDA_O_PROGRAMA_NAO_TEM_SAIDA "\nSAIDA_2 = O_PROGRAMA_NAO_TEM_SAIDA!"

unsigned long long fatorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * fatorial(n - 1);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf(SAIDA_O_PROGRAMA_NAO_TEM_SAIDA);
        return 0;
    }

    int *lista = (int *)malloc((argc - 1) * sizeof(int));
    int tamanhoLista = 0;
    unsigned long long somaFatorial = 0;
    float mediaFatorial;
    unsigned long long maiorFatorial = 0;
    unsigned long long segundoMaiorFatorial = 0;
    unsigned long long menorFatorial = 0;

    for (int i = 1; i < argc; i++) {
        lista[tamanhoLista] = atoi(argv[i]);

        if (lista[tamanhoLista] < 0 || lista[tamanhoLista] > 10) {
            printf(SAIDA_NUMERO_INVALIDO_LISTA, lista[tamanhoLista]);
            continue;
        }

        tamanhoLista++;
    }

    if (tamanhoLista == 0) {
        printf(SAIDA_O_PROGRAMA_NAO_TEM_SAIDA);
        return 0;
    }

    unsigned long long *fatoriais = (unsigned long long *)malloc(tamanhoLista * sizeof(unsigned long long));

    for (int i = 0; i < tamanhoLista; i++) {
        int numero = lista[i];
        unsigned long long fatorialNumero = fatorial(numero);
        fatoriais[i] = fatorialNumero;
        printf(SAIDA_O_FATORIAL_VALE, numero, fatorialNumero);

        somaFatorial += fatorialNumero;

        if (fatorialNumero > maiorFatorial) {
            segundoMaiorFatorial = maiorFatorial;
            maiorFatorial = fatorialNumero;
        } else if (fatorialNumero > segundoMaiorFatorial && fatorialNumero != maiorFatorial) {
            segundoMaiorFatorial = fatorialNumero;
        }
    }

    mediaFatorial = somaFatorial / (float)tamanhoLista;

    printf(SAIDA_SOMA_FATORIAL, somaFatorial);
    printf(SAIDA_MEDIA_FATORIAL, mediaFatorial);
    printf(SAIDA_MAIOR_FATORIAL, maiorFatorial);

    if (segundoMaiorFatorial != 0) {
        printf(SAIDA_SEGUNDO_MENOR_FATORIAL, segundoMaiorFatorial);
    } else {
        printf(SAIDA_SEGUNDO_MENOR_FATORIAL_INEXISTENTE);
    }

    free(lista);
    free(fatoriais);
    return 0;
}
