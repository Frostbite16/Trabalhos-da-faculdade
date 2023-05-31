//Construa um programa para resolver o exercicio 21 da lista 3.1 (parte 1).
//O programa deve receber as entradas pela linha de comando

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAIDA_1 "\nSAIDA_1 = Para o codigo de origem %d e preco %.2f a procedencia vale: %s\n"
#define SAIDA_2 "\nSAIDA_2 = O preco e invalido, deve ser um valor maior que ZERO!\n"
#define SAIDA_3 "\nSAIDA_3 = O codigo de origem e invalido!\n"

int main(int argc, char *argv[]) {
    if (argc == 3) {
        int codigoOrigem = atoi(argv[1]);
        float preco = atof(argv[2]);
        char procedencia[20];

        if (preco <= 0) {
            printf(SAIDA_2);
            return 0;
        }

        switch (codigoOrigem) {
            case 1:
                strcpy(procedencia, "Sul");
                break;
            case 2:
                strcpy(procedencia, "Norte");
                break;
            case 3:
                strcpy(procedencia, "Leste");
                break;
            case 4:
                strcpy(procedencia, "Oeste");
                break;
            case 5:
            case 6:
                strcpy(procedencia, "Nordeste");
                break;
            case 7:
            case 8:
            case 9:
                strcpy(procedencia, "Sudeste");
                break;
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
                strcpy(procedencia, "Centro-oeste");
                break;
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
                strcpy(procedencia, "Nordeste");
                break;
            default:
                printf(SAIDA_3);
                return 0;
        }

        printf(SAIDA_1, codigoOrigem, preco, procedencia);
    }

    return 0;
}
