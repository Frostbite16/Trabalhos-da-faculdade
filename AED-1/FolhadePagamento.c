#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //declação de variáveis
    char oper;
    long int num_func, num_mat;
    int cont, salario;
    num_func = 0, num_mat = 0, cont = 0, salario = 0;
    //entrada de dados
    printf("Numero de funcionaros: ");
    scanf("%d",&num_func);
    //verificando as validades dos dados
    if((num_func>0)&&(num_func <= pow(10,6))){
        //verificando cada funcionario
        while (num_func>0){
            printf("digite o numero de matricula: ");
            scanf("%d",&num_mat);
            //calculando o salário do funcionário
            if((num_mat>0)&&(num_mat <= (3*pow(10,6)))){
                for(int c = num_mat;c>0;--c){
                    if(num_mat%c==0){
                        salario = salario + c;
                    }
                }
                num_func = num_func - 1;
                //saida de dados
                printf("Numero de matricula: %d\nSalario:%d\n",num_mat, salario);
            }
            else{
                printf("Erro, Digite o numero de matricula novamente\n");
            }
            salario = 0;
        }
        printf("Operaçao finalizada\n");
    }
    else
    {
        printf("Numero de funcionarios incorreto");
    }
    
}