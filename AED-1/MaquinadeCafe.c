#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declaração de variáveis
    int n1,n2,n3,t1,t2,t3,andar;
    n1=0,n2=0,n3=0,t1=0,t2=0,t3=0,andar=1;
    printf("Digite quantas pessoas tem em cada andar, do primeiro até o terceiro\n");
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    //verificando a válidade dos números
    if((n1>=0)&&(n1<=1000)&&(n2>=0)&&(n2<=1000)&&(n3>=0)&&(n3<=1000))
    {
        while(andar<=3)
        {
            //verificando o tempo de cada andar
            if(andar==1)
            {
                t1=(n2*2)+(n3*4);
            }
            else if(andar==2)
            {
                t2=(n1*2)+(n3*2);
            }
            else if(andar==3)
            {
                t3=(n2*2)+(n1*4);
            }
            andar=andar+1;
        }
        //escolhendo o andar com mais eficiência de tempo
        if((t1==t2)&&(t2==t3))
        {
            printf("Tempo:%d\nMaquina localizada no(s) andar(res): 1 ou 2 ou 3",t1);
        }
        else if((t1<t2)&&(t1<t3)||(t2==t3)&&(t1<t2))
        {
            printf("Tempo:%d\nMaquina localizada no(s) andar(res): 1",t1);
        }
        else if((t2<t3)&&(t2<t1)||(t3==t1)&&(t2<t1))
        {
            printf("Tempo:%d\nMaquina localizada no(s) andar(res): 2",t2);
        }
        else if((t3<t2)&&(t3<t1)||(t2==t1)&&(t3<t1))
        {
            printf("Tempo:%d\nMaquina localizada no(s) andar(res): 3",t3);
        }
        else if((t1==t2)&&(t2<t3))
        {
            printf("Tempo:%d\nMaquina localizada no(s) andar(res): 1 ou 2",t1);
        }
        else if((t2==t3)&&(t2<t1))
        {
            printf("Tempo:%d\nMaquina localizada no(s) andar(res): 2 ou 3",t2);
        }
        else if((t1==t3)&&(t1<t2))
        {
            printf("Tempo:%d\nMaquina localizada no(s) andar(res): 2 ou 3",t1);
        }
    }
    else
    {
        printf("Um ou mais andares estão com os valores inválidos");
    }       






}