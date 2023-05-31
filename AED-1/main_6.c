/* Fa�a um programa que receba via argumento do programa dois numeros inteiros positivos A e B,
   onde B deve ser maior ou igual a A. O programa deve mostrar os n�meros primos entre A e B,
   inclusive os extremos A e B.
*/

#include <stdio.h>
#include <stdlib.h>

#define SAIDA_1 "\nSAIDA_1 = Os primos entre A (%d) e B (%d) sao:"
#define SAIDA_2 "\nPrimo = %d"
#define SAIDA_3 "\nSAIDA_3 = O valor de B (%d) e menor que o valor de A (%d)"
#define SAIDA_4 "\nSAIDA_4 = Quantidade invalida de argumentos!"
#define SAIDA_5 "\nSAIDA_5 = Um dos argumentos nao e positivo!"
#define SAIDA_6 "\nSAIDA_6 = Nao existe nenhum primo no intervalo entre A (%d) e B(%d)!"

/* exemplos de execucao

	app.exe 
		SAIDA_4 = Quantidade invalida de argumentos!

	app.exe 5 -1
		SAIDA_3 = O valor de B (-1) e menor que o valor de A (5)
		SAIDA_5 = Um dos argumentos nao e positivo!

	app.exe -1 5
		SAIDA_5 = Um dos argumentos nao e positivo!

	app.exe 2 6
		SAIDA_1 = Os primos entre A (2) e B (6) sao:
		Primo = 2
		Primo = 3
		Primo = 5
*/

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf(SAIDA_4);
        return 0;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    if (a > b)
    {
        printf(SAIDA_3, b, a);
        return 0;
    }

    if (a <= 0 || b <= 0)
    {
        printf(SAIDA_5);
        return 0;
    }

    printf(SAIDA_1, a, b);

    int i, j;
    int eprimo;
    int temprimo = 0;

    for (i = a; i <= b; i++)
    {
        eprimo = 1;

        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                eprimo = 0;
                break;
            }
        }

        if (eprimo)
        {
            printf(SAIDA_2, i);
            temprimo = 1;
        }
    }

    if (!temprimo)
        printf(SAIDA_6, a, b);

    return 0;
}