#include <stdio.h>
#include <math.h>

void main() {
    //declaração de variaveis
    int andar,contador,num_andar;
    andar=0,contador=0,num_andar=0;
    //entrada de dados
    printf("Número do andar que deseja: ");
    scanf("%d",&andar);
    //validação de dados
    if((1<=andar)&&(andar<=pow(10,6))){
        //contador ate que vai de 1 até o andar desejado
        for(contador=1;contador<=andar;contador++)
        {
            num_andar=num_andar+1;
            //verificação de quantos 4 e 13 tem dentro do andar através de divisão pelas bases
            if(num_andar%10000000==1300000)
            {
                num_andar=num_andar+200000;
            }
            else if(num_andar%1000000==400000)
            {
                num_andar=num_andar+100000;
            }
            else if(num_andar%1000000==130000)
            {
                num_andar=num_andar+20000;
            }
            else if(num_andar%100000==40000)
            {
                num_andar=num_andar+10000;
            }
            else if(num_andar%100000==13000)
            {
                num_andar=num_andar+2000;
            }
            else if(num_andar%10000==4000)
            {
                num_andar=num_andar+1000;
            }
            else if(num_andar%10000==1300)
            {
                num_andar=num_andar+200;
            }
            else if(num_andar%1000==400)
            {
                num_andar=num_andar+100;
            }
            else if(num_andar%1000==130)
            {
                num_andar=num_andar+20;
            }
            else if(num_andar%100==40)
            {
                num_andar=num_andar+10;
            }
            else if(num_andar%100==13)
            {
                num_andar=num_andar+2;
            }
            else if(num_andar%10==4)
            {
                num_andar=num_andar+1;
            }

        }
        //saida
        printf("%d\n",num_andar);
    }

    else{
        printf("Dados inválidos");
    }
    
    
}
