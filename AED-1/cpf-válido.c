#include <stdio.h>
#include <stdlib.h>

int obtem_primeiro_digito_verificador(char cpf[]){//obtem o primeiro digito verificador
    int digito=0,intcpf,cont=10,calccpf;//declaracao de variaveis
    for(int i=0;i<9;i++){//converte digitos do cpf de char para int e faz o calculo necessario
        intcpf = cpf[i] - '0';
        digito+=intcpf*cont;
        cont-=1;
    }
    return(digito);
}
int obtem_segundo_digito_verificador(char cpf[]) {//obtem o primeiro digito verificador
    int digito=0,intcpf,cont=11,calccpf,i;//declaracao de variaveis
    for(int i=0;i<10;i++){//converte digitos do cpf de char para int e faz o calculo necessario
        intcpf = cpf[i] - '0';
        digito+=intcpf*cont;
        cont-=1;
    }
    return(digito);
}
int verifica_cpf_valido(char cpf[]) {
    int d1cpf=cpf[9]-'0',d2cpf=d2cpf=cpf[10]-'0',valido=1,count=0;
    float d1,d2;//declaracao de variaveis
    d1=obtem_primeiro_digito_verificador(cpf)*10%11;
    d2=obtem_segundo_digito_verificador(cpf)*10%11;
    if(d1==10)
        d1=0;
    if(d2==10)
        d2=0;
    for(int i=0;i<11;i++){//exceções da regra, EX: 111.111.111-11
        if(d1cpf==(cpf[i]-'0')){
            count++;
        }
    }
    if((d1cpf==d1)&&(d2cpf==d2)&&(count<11)){//verificação do cpf
        valido=1;
    }
    else{
        valido=0;
    }
    return(valido);
}
int main(){
    char cpf[12];
    scanf("%s,",&cpf);
    printf("%d",verifica_cpf_valido(cpf));
    
}
