/* Construa um programa para resolver o exerc�cio 21 da Lista 3.
   O valor X deve ser obtido via argumento do programa.
*/

#include <stdio.h>
#include <stdlib.h>

#define SAIDA_1 "\nRAIZ QUADRADA de %d = %.3f"
#define SAIDA_2 "\nSAIDA = Argumento nao e positivo!"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int y = atoi(argv[1]);

        if (y < 0)
        {
            printf(SAIDA_2);
            return 0;
        }

        float x = y / 2.0;
        float xn;

        do
        {
            xn = x;
            x = (xn + (y / xn)) / 2;
        } while (x != xn);

        printf(SAIDA_1, y, x);
    }

    return 0;
}

