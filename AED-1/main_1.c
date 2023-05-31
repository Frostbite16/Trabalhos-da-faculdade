//Construa um programa para resolver o exercicio 8 da lista 3.1 (parte 1).
//O programa deve receber a entrada pela linha de comando.

//Exemplo de execucao: prog 478.90

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sa�das permitidas e que NAO PODEM ser modificadas
#define SAIDA_1 "\nSAIDA_1 = O salario antes do reajuste: R$ %.2f"
#define SAIDA_2 "\nSAIDA_2 = O salario reajustado ficou: R$ %.2f"
#define SAIDA_3 "\nSAIDA_3 = O percentual de reajuste foi de: %d%%"
#define SAIDA_4 "\nSAIDA_4 = O salario deve estar entre R$ 0,00 e R$ 1.000,00"

int main(int argc, char *argv[]) {
    float sal = atof(argv[1]);
    float aumento = 0;
    if( argc == 2 ) 
    {
        //construa a solucao aqui
        //verifica se os dados são válidos
        if((sal >= 0) && (sal <= 1000))
        {
            //se menor que 300 aplica 35%
            if(sal <= 300)
            {
                printf(SAIDA_1, sal);
                printf(SAIDA_2, sal+(sal*0.35));
                printf(SAIDA_3"\n", 35);
            }
            //se maior que 300 aplica 15%
            else if(sal > 300)
            {
                printf(SAIDA_1, sal);
                printf(SAIDA_2, sal+(sal*0.15));
                printf(SAIDA_3"\n", 15);
            }
        }
        else
        {
            printf(SAIDA_4);
        }
    }
    return 0;
}
