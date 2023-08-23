#include <stdio.h>
#include <stdlib.h>

int obtem_primeiro_digito_verificador(char cpf[]){//obtem o primeiro digito verificador
    int digito=0,intcpf,cont=10,calccpf;//declaracao de variaveis
    for(int i=0;i<9;i++){//converte digitos do cpf de char para int e faz o calculo necessario
        intcpf = cpf[i] - '0';
        digito+=intcpf*cont;
        cont-=1;
    }
    if(digito*10%11==10){
        digito=0;
    }
    else{
        digito=digito*10%11;
    }
    return(digito);
}
int obtem_segundo_digito_verificador(char cpf[]) {//obtem o primeiro digito verificador
    int digito=0,intcpf,cont=11,calccpf,i;//declaracao de variaveis
    for(int i=0;i<10;i++){//converte digitos do cpf de char para int e faz o calculo necessario
        if(i<=8){
            intcpf = cpf[i] - '0';
        }
        else{
            intcpf = obtem_primeiro_digito_verificador(cpf);
        }
        digito+=intcpf*cont;
        cont-=1;
    }
    if(digito*10%11==10){
        digito=0;
    }
    else{
        digito=digito*10%11;
    }
    return(digito);
}
int verifica_cpf_valido(char cpf[]) {
    int d1cpf=cpf[12]-'0',d2cpf=cpf[13]-'0',valido=1,count=0,d1,d2,c=0;//declaracao de variaveis
    char cpf2[12];
    for(int i=0;i<15;i++){
        if((cpf[i]=='.')||(cpf[i]=='-')){
            ++i;
        }
        if(d1cpf==(cpf[i]-'0')){
            count++;
        }
        if(c<=11){
            cpf2[c]=cpf[i];
            
        }
        c++;
    }
    d1=obtem_primeiro_digito_verificador(cpf2);
    d2=obtem_segundo_digito_verificador(cpf2);
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
    char icpf[15];
    scanf("%s",&cpf);
    scanf("%s",&icpf);
    printf("%d, %d, %d",obtem_primeiro_digito_verificador(cpf),obtem_segundo_digito_verificador(cpf), verifica_cpf_valido(icpf));
    
}
