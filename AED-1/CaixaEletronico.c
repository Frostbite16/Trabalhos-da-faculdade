#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //declaração de variaveis
    int c500,c150,c50,c20,c10,c5,c2,c1,escmenu,menuger,numcpf,count,count1,count2,vercpf1,vercpf2,total,saqtotal;
    int saqueregs,cen1,dez1,un1,cen2,dez2,un2,quantia;
    int cpf[10];
    int c[7];//valores das cedulas em c 0:500,1:150,2:50,3:20,4:10,5:5,6:2,7:1
    float saque = 0;
    c500=100,c150=200,c50=400,c20=800,c10=1600,c5=3200,c2=6400,c1=12800;
    count=0,count1=10,vercpf1=0,count2=11,vercpf2=0;
    saqtotal=0;
    int cv[8]={500, 150, 50, 20, 10, 5, 2, 1};
    while(escmenu != 3){
        for(int z=0;z<=7;++z){//limpa da váriavel das cedulas
        c[z] = 0;
        }
        printf("\nescolha uma opcao:\n1-Saque\n2-gerente\n3-finalizar\n");
        scanf("%d",&escmenu);
        if(escmenu==1){
            vercpf1=0,vercpf2=0,count=0,count1=10,count2=11;//reseta os valores das variaveis na verificação de cpf
            for(int i=0;i<11;i=i+1){   
                printf("\nDigite a %d posicao do seu cpf: ",i+1);
                scanf("%d",&cpf[i]);
            }
            for(int i=0;i<11;i=i+1){//verificador do cpf
                if(i<9){//verificando a primeira parte
                    vercpf1 = vercpf1 + cpf[i] * count1;
                    --count1;
                }
                if(i<10){//verificando a segunda parte
                    vercpf2 = vercpf2 + cpf[i] * count2;
                    --count2;
                }
                if(cpf[0]==cpf[i]){//verifica casos invalidos conhecidos,ex:111.111.111-11
                    ++count;
                }
            }
            if((vercpf1*10)%11>=10){//parte da verificação do cpf
                vercpf1=0;
            }
            else{
                vercpf1=(vercpf1*10)%11;
            }
            if ((vercpf2*10)%11>=10){
                vercpf2=0;
            }
            else{
                vercpf2=(vercpf2*10)%11;
            }//atribui os valores e garante que valores maiores ou iguais a 10 sejam válidos
            if((vercpf1==cpf[9])&&(vercpf2==cpf[10])&(count<11)){//validando o cpf
                puts("Forneça o valor do saque: ");
                //entrada do saque
                scanf("%f",&saque);
                //registro do saque para o valor por extenso e para o valor total sacado em todas as sessôes da máquina
                
                    //verifica se o saque e maior que 0
                    if(saque>0){
                        saqtotal += saque;
                        saqueregs = saque;
                        //verifica se a máquina ainda tem cédulas
                        if((c500>0)||(c150>0)||(c50>0)||(c20>0)||(c10>0)||(c5>0)||(c2>0)||(c1>0)){
                            while(saque>0){
                                //subtrai o saque pelas cedulas, começando da maior para a menor, e analizando os resultados    
                                if(saque>=((c500*500)+(c150*150)+(c50*50)+(c20*20)+(c10*10)+(c5*5)+(c2*2)+(c1*1))){
                                    printf("não temos notas suficientes para fazer seu saque, fale com o gerente");
                                    saque = -1;
                                    break;      
                                }
                                else if((c500 > 0)&&(saque-500>=0)){
                                    saque = saque - 500;
                                    c[0] = c[0] + 1;
                                    c500 -= 1;
                                }
                                else if((c150 > 0)&&(saque-150>=0)){
                                    saque = saque - 150;
                                    c[1] += 1;
                                    c150 -= 1;
                                }
                                else if((c50 > 0)&&(saque-50>=0)){
                                    saque = saque - 50;
                                    c[2] += 1;
                                    c50 -= 1;
                                }
                                else if((c20 > 0)&&(saque-20>=0)){
                                    saque = saque - 20;
                                    c[3] += 1;
                                    c20 -= 1;
                                }
                                else if((c10 > 0)&&(saque-10>=0)){
                                    saque = saque - 10;
                                    c[4] += 1;
                                    c10 -= 1;
                                }
                                else if((c5 > 0)&&(saque-5>=0)){
                                    saque = saque - 5;
                                    c[5] += 1;
                                    c5 -= 1;
                                }
                                else if((c2 > 0)&&(saque-2>=0)){
                                    saque = saque - 2;
                                    c[6] += 1;
                                    c2 -= 1;
                                }
                                else if((c1 > 0)&&(saque-1>=0)){
                                    saque = saque - 1;
                                    c[7] += 1;
                                    c1 -= 1;
                                }
                            }
                            if(saque==0){
                                //escrever o número por extenso
                                //verifica os casos especificos
                                if(saqueregs>0)
                                {
                                    cen2=((saqueregs/1000)/100);
                                    dez2=((saqueregs/1000)-cen2*100)/10;
                                    un2=((saqueregs/1000)-cen2*100)-dez2*10;
                                    cen1=(saqueregs-((saqueregs/1000)*1000))/100;
                                    dez1=((saqueregs-(saqueregs/1000)*1000)-cen1*100)/10;
                                    un1=((saqueregs-(saqueregs/1000)*1000)-cen1*100)-dez1*10;
                                }
                                //soma a parte de milhar e centena para a verificação posteriormente
                                int total2=cen2+dez2+un2;
                                int total1=cen1+dez1+un1;
                                //escreve a parte de milhar por extenso
                                    if(total2!=0){
                                        printf("Valor do Saque: ");
                                        if(cen2==total2){
                                            puts("Cem mil\n");
                                            if (total1!=0)
                                            {
                                                printf(" e ");

                                            }
                                            
                                        }
                                        else{
                                            if(cen2==1){
                                                printf("Cento e ");
                                            }
                                            switch(dez2){
                                                case 0:
                                                    break;
                                                case 1:
                                                    switch(un2){
                                                        case 0:
                                                            printf("Dez");
                                                            break;
                                                        case 1:
                                                            printf("Onze");
                                                            break;
                                                        case 2:
                                                            printf("Doze");
                                                            break;
                                                        case 3:
                                                            printf("Treze");
                                                            break;
                                                        case 4:
                                                            printf("Quatorze");
                                                            break;
                                                        case 5:
                                                            printf("Quinze");
                                                            break;
                                                        case 6:
                                                            printf("Dezesseis");
                                                            break;
                                                        case 7:
                                                            printf("Dezessete");
                                                            break;
                                                        case 8:
                                                            printf("Dezoito");
                                                            break;
                                                        case 9:
                                                            printf("Dezenove");
                                                            break;
                                                        }
                                                    break;
                                                case 2:
                                                    printf("Vinte");
                                                    break;
                                                case 3:
                                                    printf("Trinta");
                                                    break;
                                                case 4:
                                                    printf("Quarenta");
                                                    break;
                                                case 5:
                                                    printf("Cinquenta");
                                                    break;
                                                case 6:
                                                    printf("Sessenta");
                                                    break;
                                                case 7:
                                                    printf("Setenta");
                                                    break;
                                                case 8:
                                                    printf("Oitenta");
                                                    break;
                                                case 9:
                                                    printf("Noventa");
                                                    break;
                                            }
                                            if((dez2!=1)&&(dez2!=0)&&(un2!=0)){
                                                printf(" e ");
                                            }
                                            if(dez2 != 1){
                                                switch(un2){
                                                        case 0:
                                                            break;
                                                        case 1:
                                                            printf("Um");
                                                            break;
                                                        case 2:
                                                            printf("Dois");
                                                            break;
                                                        case 3:
                                                            printf("Três");
                                                            break;
                                                        case 4:
                                                            printf("Quatro");
                                                            break;
                                                        case 5:
                                                            printf("Cinco");
                                                            break;
                                                        case 6:
                                                            printf("Seis");
                                                            break;
                                                        case 7:
                                                            printf("Sete");
                                                            break;
                                                        case 8:
                                                            printf("Oito");
                                                            break;
                                                        case 9:
                                                            printf("Nove");
                                                            break;
                                                }
                                            }
                                            printf(" mil");
                                            if(total1!=0)
                                            {
                                                printf(" e ");
                                            }
                                        }        

                                    }
                                    //escreva a parte de centena por extenso
                                    if((cen1==total1)&&(cen1==1)){
                                        printf("Cem");
                                    }
                                    else{
                                        switch(cen1){
                                            case 0:
                                                break;
                                            case 1:
                                                printf("Cento");
                                                break;
                                            case 2:
                                                printf("Duzentos");
                                                break;
                                            case 3:
                                                printf("Trezentos");
                                                break;
                                            case 4:
                                                printf("Quatrocentos");
                                                break;
                                            case 5:
                                                printf("Quinhentos");
                                                break;
                                            case 6:
                                                printf("Seiscentos");
                                                break;
                                            case 7:
                                                printf("Setecentos");
                                                break;
                                            case 8:
                                                printf("Oitocentos");
                                                break;
                                            case 9:
                                                printf("Novecentos");
                                                break;
                                        }
                                        if((total1!=cen1)&&(cen1!=0)){
                                            printf(" e ");
                
                                        }
                                        switch(dez1){
                                            case 0:
                                                break;
                                            case 1:
                                                switch(un1){
                                                    case 0:
                                                        printf("Dez");
                                                        break;
                                                    case 1:
                                                        printf("Onze");
                                                        break;
                                                    case 2:
                                                        printf("Doze");
                                                        break;
                                                    case 3:
                                                        printf("Treze");
                                                        break;
                                                    case 4:
                                                        printf("Quatorze");
                                                        break;
                                                    case 5:
                                                        printf("Quinze");
                                                        break;
                                                    case 6:
                                                        printf("Dezesseis");
                                                        break;
                                                    case 7:
                                                        printf("Dezessete");
                                                        break;
                                                    case 8:
                                                        printf("Dezoito");
                                                        break;
                                                    case 9:
                                                        printf("Dezenove");
                                                        break;
                                                }
                                                break;
                                            case 2:
                                                printf("Vinte");
                                                break;
                                            case 3:
                                                printf("Trinta");
                                                break;
                                            case 4:
                                                printf("Quarenta");
                                                break;
                                            case 5:
                                                printf("Cinquenta");
                                                break;
                                            case 6:
                                                printf("Sessenta");
                                                break;
                                            case 7:
                                                printf("Setenta");
                                                break;
                                            case 8:
                                                printf("Oitenta");
                                                break;
                                            case 9:
                                                printf("Noventa");
                                                break;
                                            
                                        }
                                        if((dez1!=1)&&(dez1!=0)&&(un1!=0))
                                        {
                                            printf(" e ");
                                        }
                                        if(dez1!=1){
                                            switch(un1){
                                                case 0:
                                                    break;
                                                case 1:
                                                    printf("um");
                                                    break;
                                                case 2:
                                                    printf("Dois");
                                                    break;
                                                case 3:
                                                    printf("Três");
                                                    break;
                                                case 4:
                                                    printf("Quatro");
                                                    break;
                                                case 5:
                                                    printf("Cinco");
                                                    break;
                                                case 6:
                                                    printf("Seis");
                                                    break;
                                                case 7:
                                                    printf("Sete");
                                                    break;
                                                case 8:
                                                    printf("Oito");
                                                    break;
                                                case 9:
                                                    printf("Nove");
                                                    break;
                                            }
                                        }
                                    }
                                }
                            //saida das cedulas que serão sacadas do caixa
                            printf("\nQuantidades de cedulas: \n500: %d\n150: %d\n50: %d\n20: %d\n10: %d\n5: %d\n2: %d\n1: %d\n",c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7]);
                        }
                        
                        else{
                            puts("\nA maquina está atualmente sem notas, fale com o gerente se deseja continuar a operação");
                        }
                }
                else{
                    puts("\nO saque deve ser maior que 0");
                }
            }
            else{
                puts("\ncpf inválido");
            }
        }
        if(escmenu==2){
            menuger=-1;
            while (menuger!=5)
            {  
                int total1,total2;
                puts("\nMENU GERENTE:\n1-Valor total Sacado\n2-Valor do saldo existente\n3-Quantidade de Cedulas existentes\n4-Abastecer caixa eletrónico\n5-Voltar ao Menu Principal ");
                scanf("%d",&menuger);
                //primeiro menu do gerente
                if(menuger==1)
                {   
                    if(saqtotal>0){
                        //entrada de dados
                        printf("Valor total Sacado: %d ou ",saqtotal); 
                        //extrai cada caracter do saque
                        if(saqtotal>0)
                        {
                            cen2=((saqtotal/1000)/100);
                            dez2=((saqtotal/1000)-cen2*100)/10;
                            un2=((saqtotal/1000)-cen2*100)-dez2*10;
                            cen1=(saqtotal-((saqtotal/1000)*1000))/100;
                            dez1=((saqtotal-(saqtotal/1000)*1000)-cen1*100)/10;
                            un1=((saqtotal-(saqtotal/1000)*1000)-cen1*100)-dez1*10;
                        }
                        //soma 
                        total2 = cen2+dez2+un2;
                        total1 = cen1+dez1+un1;
                        //extenso da centena de milhares
                        if(total2!=0){
                            if((cen2==total2)&&(cen2==1)){
                                puts("Cem mil\n");
                                if (total1!=0){
                                    printf(" e ");
                                }
                                                
                            }
                            else{
                                switch(cen2){
                                    case 0:
                                        break;
                                    case 1:
                                        printf("Cento");
                                        break;
                                    case 2:
                                        printf("Duzentos");
                                        break;
                                    case 3:
                                        printf("Trezentos");
                                        break;
                                    case 4:
                                        printf("Quatrocentos");
                                        break;
                                    case 5:
                                        printf("Quinhentos");
                                        break;
                                    case 6:
                                        printf("Seiscentos");
                                        break;
                                    case 7:
                                        printf("Setecentos");
                                        break;
                                    case 8:
                                        printf("Oitocentos");
                                        break;
                                    case 9:
                                        printf("Novecentos");
                                        break;
                                }
                                if((total2!=cen2)&&(cen2!=0))
                                {
                                    printf(" e ");
                                }
                                switch(dez2){
                                    case 0:
                                    break;
                                    case 1:
                                        switch(un2){
                                            case 0:
                                                printf("Dez");
                                                break;
                                            case 1:
                                                printf("Onze");
                                                break;
                                            case 2:
                                                printf("Doze");
                                                break;
                                            case 3:
                                                printf("Treze");
                                                break;
                                            case 4:
                                                printf("Quatorze");
                                                break;
                                            case 5:
                                                printf("Quinze");
                                                break;
                                            case 6:
                                                printf("Dezesseis");
                                                break;
                                            case 7:
                                                printf("Dezessete");
                                                break;
                                            case 8:
                                                printf("Dezoito");
                                                break;
                                            case 9:
                                                printf("Dezenove");
                                                break;
                                        }
                                        break;
                                    case 2:
                                        printf("Vinte");
                                        break;
                                    case 3:
                                        printf("Trinta");
                                        break;
                                    case 4:
                                        printf("Quarenta");
                                        break;
                                    case 5:
                                        printf("Cinquenta");
                                        break;
                                    case 6:
                                        printf("Sessenta");
                                        break;
                                    case 7:
                                        printf("Setenta");
                                        break;
                                    case 8:
                                        printf("Oitenta");
                                        break;
                                    case 9:
                                        printf("Noventa");
                                        break;
                                }
                                if((dez2!=1)&&(dez2!=0)&(un2!=0)){
                                    printf(" e ");
                                }
                                if(dez2 != 1){
                                    switch(un2){
                                        case 0:
                                            break;
                                        case 1:
                                            printf("Um");
                                            break;
                                        case 2:
                                            printf("Dois");
                                            break;
                                        case 3:
                                            printf("Três");
                                            break;
                                        case 4:
                                            printf("Quatro");
                                            break;
                                        case 5:
                                            printf("Cinco");
                                            break;
                                        case 6:
                                            printf("Seis");
                                            break;
                                        case 7:
                                            printf("Sete");
                                            break;
                                        case 8:
                                            printf("Oito");
                                            break;
                                        case 9:
                                            printf("Nove");
                                            break;
                                    }
                                }
                                printf(" mil ");
                                if(total1!=0)
                                {
                                    printf(" e ");
                                }
                            }        

                        }
                        //parte da centena
                        if((cen1==total1)&&(cen1==1))
                        {
                            printf("cem");
                        }
                        else{
                            switch(cen1){
                                case 0:
                                    break;
                                case 1:
                                    printf("Cento");
                                    break;
                                case 2:
                                    printf("Duzentos");
                                    break;
                                case 3:
                                    printf("Trezentos");
                                    break;
                                case 4:
                                    printf("Quatrocentos");
                                    break;
                                case 5:
                                    printf("Quinhentos");
                                    break;
                                case 6:
                                    printf("Seiscentos");
                                    break;
                                case 7:
                                    printf("Setecentos");
                                    break;
                                case 8:
                                    printf("Oitocentos");
                                    break;
                                case 9:
                                    printf("Novecentos");
                                    break;
                            }
                        
                            if((total1!=cen1)&&(cen1!=0)){
                                printf(" e ");
                            }
                            switch(dez1){
                                case 0:
                                    break;
                                case 1:
                                    switch(un1){
                                        case 0:
                                            printf("Dez");
                                            break;
                                        case 1:
                                            printf("Onze");
                                            break;
                                        case 2:
                                            printf("Doze");
                                            break;
                                        case 3:
                                            printf("Treze");
                                            break;
                                        case 4:
                                            printf("Quatorze");
                                            break;
                                        case 5:
                                            printf("Quinze");
                                            break;
                                        case 6:
                                            printf("Dezesseis");
                                            break;
                                        case 7:
                                            printf("Dezessete");
                                            break;
                                        case 8:
                                            printf("Dezoito");
                                            break;
                                        case 9:
                                            printf("Dezenove");
                                            break;
                                        }
                                        break;
                                    case 2:
                                        printf("Vinte");
                                        break;
                                    case 3:
                                        printf("Trinta");
                                        break;
                                    case 4:
                                        printf("Quarenta");
                                        break;
                                    case 5:
                                        printf("Cinquenta");
                                        break;
                                    case 6:
                                        printf("Sessenta");
                                        break;
                                    case 7:
                                        printf("Setenta");
                                        break;
                                    case 8:
                                        printf("Oitenta");
                                        break;
                                    case 9:
                                        printf("Noventa");
                                        break;
                                                
                            }
                            if((dez1!=1)&&(dez1!=0)&&(un1!=0))
                            {
                                printf(" e ");
                            }
                            if(dez1!=1){
                                switch(un1){
                                    case 0:
                                        break;
                                    case 1:
                                        printf("um");
                                        break;
                                    case 2:
                                        printf("Dois");
                                        break;
                                    case 3:
                                        printf("Três");
                                        break;
                                    case 4:
                                        printf("Quatro");
                                        break;
                                    case 5:
                                        printf("Cinco");
                                        break;
                                    case 6:
                                        printf("Seis");
                                        break;
                                    case 7:
                                        printf("Sete");
                                        break;
                                    case 8:
                                        printf("Oito");
                                        break;
                                    case 9:
                                        printf("Nove");
                                        break;
                                }
                            }
                        }
                    }
                    else{
                        printf("Ainda nenhum saque foi feito no caixa");
                        break;
                    }
                }
                //segundo menu do gerente
                if(menuger==2){
                    saqueregs = 500*c500+150*c150+50*c50+20*c20+10*c10+5*c5+2*c2+1*c1;
                    if(saqueregs>0){
                        printf("Saque restante no caixa: %d ou ",saqueregs);
                        if(saqueregs>0)
                        {
                            cen2=((saqueregs/1000)/100);
                            dez2=((saqueregs/1000)-cen2*100)/10;
                            un2=((saqueregs/1000)-cen2*100)-dez2*10;
                            cen1=(saqueregs-((saqueregs/1000)*1000))/100;
                            dez1=((saqueregs-(saqueregs/1000)*1000)-cen1*100)/10;
                            un1=((saqueregs-(saqueregs/1000)*1000)-cen1*100)-dez1*10;
                        }
                        total2 = cen2+dez2+un2;
                        total1 = cen1+dez1+un1;
                        //extenso da centena de milhares
                        if(total2!=0){
                            if((cen2==total2)&&(cen2==1)){
                                puts("Cem mil\n");
                                if (total1!=0){
                                    printf(" e ");
                                }
                                                
                            }
                            else{
                                switch(cen2){
                                    case 0:
                                        break;
                                    case 1:
                                        printf("Cento");
                                        break;
                                    case 2:
                                        printf("Duzentos");
                                        break;
                                    case 3:
                                        printf("Trezentos");
                                        break;
                                    case 4:
                                        printf("Quatrocentos");
                                        break;
                                    case 5:
                                        printf("Quinhentos");
                                        break;
                                    case 6:
                                        printf("Seiscentos");
                                        break;
                                    case 7:
                                        printf("Setecentos");
                                        break;
                                    case 8:
                                        printf("Oitocentos");
                                        break;
                                    case 9:
                                        printf("Novecentos");
                                        break;
                                }
                                if((total2!=cen2)&&(cen2!=0))
                                {
                                    printf(" e ");
                                }
                                switch(dez2){
                                    case 0:
                                    break;
                                    case 1:
                                        switch(un2){
                                            case 0:
                                                printf("Dez");
                                                break;
                                            case 1:
                                                printf("Onze");
                                                break;
                                            case 2:
                                                printf("Doze");
                                                break;
                                            case 3:
                                                printf("Treze");
                                                break;
                                            case 4:
                                                printf("Quatorze");
                                                break;
                                            case 5:
                                                printf("Quinze");
                                                break;
                                            case 6:
                                                printf("Dezesseis");
                                                break;
                                            case 7:
                                                printf("Dezessete");
                                                break;
                                            case 8:
                                                printf("Dezoito");
                                                break;
                                            case 9:
                                                printf("Dezenove");
                                                break;
                                        }
                                        break;
                                    case 2:
                                        printf("Vinte");
                                        break;
                                    case 3:
                                        printf("Trinta");
                                        break;
                                    case 4:
                                        printf("Quarenta");
                                        break;
                                    case 5:
                                        printf("Cinquenta");
                                        break;
                                    case 6:
                                        printf("Sessenta");
                                        break;
                                    case 7:
                                        printf("Setenta");
                                        break;
                                    case 8:
                                        printf("Oitenta");
                                        break;
                                    case 9:
                                        printf("Noventa");
                                        break;
                                }
                                if((dez2!=1)&&(dez2!=0)&(un2!=0)){
                                    printf(" e ");
                                }
                                if(dez2 != 1){
                                    switch(un2){
                                        case 0:
                                            break;
                                        case 1:
                                            printf("Um");
                                            break;
                                        case 2:
                                            printf("Dois");
                                            break;
                                        case 3:
                                            printf("Três");
                                            break;
                                        case 4:
                                            printf("Quatro");
                                            break;
                                        case 5:
                                            printf("Cinco");
                                            break;
                                        case 6:
                                            printf("Seis");
                                            break;
                                        case 7:
                                            printf("Sete");
                                            break;
                                        case 8:
                                            printf("Oito");
                                            break;
                                        case 9:
                                            printf("Nove");
                                            break;
                                    }
                                }
                                printf(" mil");
                                if(total1!=0)
                                {
                                    printf(" e ");
                                }
                            }        

                        }
                        //parte da centena
                        if((cen1==total1)&&(cen1==1))
                        {
                            printf("cem");
                        }
                        else{
                            switch(cen1){
                                case 0:
                                    break;
                                case 1:
                                    printf("Cento");
                                    break;
                                case 2:
                                    printf("Duzentos");
                                    break;
                                case 3:
                                    printf("Trezentos");
                                    break;
                                case 4:
                                    printf("Quatrocentos");
                                    break;
                                case 5:
                                    printf("Quinhentos");
                                    break;
                                case 6:
                                    printf("Seiscentos");
                                    break;
                                case 7:
                                    printf("Setecentos");
                                    break;
                                case 8:
                                    printf("Oitocentos");
                                    break;
                                case 9:
                                    printf("Novecentos");
                                    break;
                            }
                        
                            if((total1!=cen1)&&(cen1!=0)){
                                printf(" e ");
                            }
                            switch(dez1){
                                case 0:
                                    break;
                                case 1:
                                    switch(un1){
                                        case 0:
                                            printf("Dez");
                                            break;
                                        case 1:
                                            printf("Onze");
                                            break;
                                        case 2:
                                            printf("Doze");
                                            break;
                                        case 3:
                                            printf("Treze");
                                            break;
                                        case 4:
                                            printf("Quatorze");
                                            break;
                                        case 5:
                                            printf("Quinze");
                                            break;
                                        case 6:
                                            printf("Dezesseis");
                                            break;
                                        case 7:
                                            printf("Dezessete");
                                            break;
                                        case 8:
                                            printf("Dezoito");
                                            break;
                                        case 9:
                                            printf("Dezenove");
                                            break;
                                        }
                                        break;
                                    case 2:
                                        printf("Vinte");
                                        break;
                                    case 3:
                                        printf("Trinta");
                                        break;
                                    case 4:
                                        printf("Quarenta");
                                        break;
                                    case 5:
                                        printf("Cinquenta");
                                        break;
                                    case 6:
                                        printf("Sessenta");
                                        break;
                                    case 7:
                                        printf("Setenta");
                                        break;
                                    case 8:
                                        printf("Oitenta");
                                        break;
                                    case 9:
                                        printf("Noventa");
                                        break;
                                                
                            }
                            if((dez1!=1)&&(dez1!=0)&&(un1!=0))
                            {
                                printf(" e ");
                            }
                            if(dez1!=1){
                                switch(un1){
                                    case 0:
                                        break;
                                    case 1:
                                        printf("um");
                                        break;
                                    case 2:
                                        printf("Dois");
                                        break;
                                    case 3:
                                        printf("Três");
                                        break;
                                    case 4:
                                        printf("Quatro");
                                        break;
                                    case 5:
                                        printf("Cinco");
                                        break;
                                    case 6:
                                        printf("Seis");
                                        break;
                                    case 7:
                                        printf("Sete");
                                        break;
                                    case 8:
                                        printf("Oito");
                                        break;
                                    case 9:
                                        printf("Nove");
                                        break;
                                }
                            }
                        }
                    }
                    else{
                        printf("não tem nenhuma cédula restante no caixa");
                        break;
                    }
                }
                if(menuger==3){
                    //atribuindo a quantidade de cédulas a um vetor
                    c[0]=c500,c[1]=c150,c[2]=c50,c[3]=c20,c[4]=c10,c[5]=c5,c[6]=c2,c[7]=c1;
                    printf("Quantidade de cédulas existentes:\n");
                    for(int i=0;i<=7;i++){    
                        printf(" %d: %d ou ",cv[i], c[i]);
                        if(c[i]>0)
                        {
                            cen2=((c[i]/1000)/100);
                            dez2=((c[i]/1000)-cen2*100)/10;
                            un2=((c[i]/1000)-cen2*100)-dez2*10;
                            cen1=(c[i]-((c[i]/1000)*1000))/100;
                            dez1=((c[i]-(c[i]/1000)*1000)-cen1*100)/10;
                            un1=((c[i]-(c[i]/1000)*1000)-cen1*100)-dez1*10;
                        }
                        int total1 = cen1+dez1+un1;
                        int total2 = dez2+un2;
                        //milhares
                        switch(dez2){
                            case 0:
                                break;
                            case 1:
                                switch(un2){
                                    case 0:
                                        printf("Dez");
                                        break;
                                    case 1:
                                        printf("Onze");
                                        break;
                                    case 2:
                                        printf("Doze");
                                        break;
                                    case 3:
                                        printf("Treze");
                                        break;
                                    case 4:
                                        printf("Quatorze");
                                        break;
                                    case 5:
                                        printf("Quinze");
                                        break;
                                    case 6:
                                        printf("Dezesseis");
                                        break;
                                    case 7:
                                        printf("Dezessete");
                                        break;
                                    case 8:
                                        printf("Dezoito");
                                        break;
                                    case 9:
                                        printf("Dezenove");
                                        break;
                                    }
                                break;
                            }
                            if((dez2!=1)&&(dez2!=0)&(un2!=0)){
                                printf(" e ");
                            }
                            if(dez2 != 1){
                                switch(un2){
                                    case 0:
                                        break;
                                    case 1:
                                        printf("Um");
                                        break;
                                    case 2:
                                        printf("Dois");
                                        break;
                                    case 3:
                                        printf("Três");
                                        break;
                                    case 4:
                                        printf("Quatro");
                                        break;
                                    case 5:
                                        printf("Cinco");
                                        break;
                                    case 6:
                                        printf("Seis");
                                        break;
                                    case 7:
                                        printf("Sete");
                                        break;
                                case 8:
                                    printf("Oito");
                                    break;
                                case 9:
                                    printf("Nove");
                                    break;
                            }
                        }
                        
                        if(total2!=0){
                        printf(" mil");
                        }
                        if((total1!=0)&&(total2!=0))
                        {
                            printf(" e ");
                        }
                        //centenas,dezenas,unidades
                        if((cen1==total1)&&(cen1==1))
                        {
                        printf("cem");
                        }
                        else{
                            switch(cen1){
                                case 0:
                                    break;
                                case 1:
                                    printf("Cento");
                                    break;
                                case 2:
                                    printf("Duzentos");
                                    break;
                                case 3:
                                    printf("Trezentos");
                                    break;
                                case 4:
                                    printf("Quatrocentos");
                                    break;
                                case 5:
                                    printf("Quinhentos");
                                    break;
                                case 6:
                                    printf("Seiscentos");
                                    break;
                                case 7:
                                    printf("Setecentos");
                                    break;
                                case 8:
                                    printf("Oitocentos");
                                    break;
                                case 9:
                                    printf("Novecentos");
                                    break;
                            }
                        
                            if((total1!=cen1)&&(cen1!=0)){
                                printf(" e ");
                            }
                            switch(dez1){
                                case 0:
                                    break;
                                case 1:
                                    switch(un1){
                                        case 0:
                                            printf("Dez");
                                            break;
                                        case 1:
                                            printf("Onze");
                                            break;
                                        case 2:
                                            printf("Doze");
                                            break;
                                        case 3:
                                            printf("Treze");
                                            break;
                                        case 4:
                                            printf("Quatorze");
                                            break;
                                        case 5:
                                            printf("Quinze");
                                            break;
                                        case 6:
                                            printf("Dezesseis");
                                            break;
                                        case 7:
                                            printf("Dezessete");
                                            break;
                                        case 8:
                                            printf("Dezoito");
                                            break;
                                        case 9:
                                            printf("Dezenove");
                                            break;
                                        }
                                        break;
                                    case 2:
                                        printf("Vinte");
                                        break;
                                    case 3:
                                        printf("Trinta");
                                        break;
                                    case 4:
                                        printf("Quarenta");
                                        break;
                                    case 5:
                                        printf("Cinquenta");
                                        break;
                                    case 6:
                                        printf("Sessenta");
                                        break;
                                    case 7:
                                        printf("Setenta");
                                        break;
                                    case 8:
                                        printf("Oitenta");
                                        break;
                                    case 9:
                                        printf("Noventa");
                                        break;
                                                
                            }
                            if((dez1!=1)&&(dez1!=0)&&(un1!=0))
                            {
                                printf(" e ");
                            }
                            if(dez1!=1){
                                switch(un1){
                                    case 0:
                                        break;
                                    case 1:
                                        printf("um");
                                        break;
                                    case 2:
                                        printf("Dois");
                                        break;
                                    case 3:
                                        printf("Três");
                                        break;
                                    case 4:
                                        printf("Quatro");
                                        break;
                                    case 5:
                                        printf("Cinco");
                                        break;
                                    case 6:
                                        printf("Seis");
                                        break;
                                    case 7:
                                        printf("Sete");
                                        break;
                                    case 8:
                                        printf("Oito");
                                        break;
                                    case 9:
                                        printf("Nove");
                                        break;
                                }
                            }  
                        }
                        if((total1==0)&&(total2==2))
                        {
                            printf("Nenhuma cédula");
                        }
                        printf("\n");
                    }
                }
                if(menuger==4){
                    while(escmenu!=0)
                    {
                        printf("Menu Abastecer o caixa: \nEscolha uma das opções:\n500-cédulas de 500\n150-cédulas de 150");
                        printf("\n50-cédulas de 50\n20-cédulas de 20\n10-cédulas de 10\n5-cédulas de 5\n2-cédulas de 2\n1-cédulas de 1\n0-Voltar ao menu gerente\n");
                        scanf("%d",&escmenu);
                        switch(escmenu)
                        {
                            case 500:
                                if(c500<100)
                                {
                                    printf("\nDigite a quantia que deseja adicionar: \n");
                                    scanf("%d",&quantia);
                                    if((c500+quantia<=100)&&(quantia>0))
                                    {
                                        c500+=quantia;
                                        printf("\nQuantia adicionada\n");
                                    }
                                    else if(quantia<=0){
                                        printf("\na quantia deve ser maior que 0\n");
                                    }
                                    else{
                                        printf("\nA quantia excede o limite máximo para a cédula selecionada\n");
                                    }
                                }
                                else{
                                    printf("\na cédula selecionada já está no limite\n");
                                }
                                break;
                            case 150:
                                if(c150<200)
                                {
                                    printf("\nDigite a quantia que deseja adicionar: \n");
                                    scanf("%d",&quantia);
                                    if((c150+quantia<=200)&&(quantia>0))
                                    {
                                        c150+=quantia;
                                        printf("\nQuantia adicionada\n");
                                    }
                                    else if(quantia<=0){
                                        printf("\na quantia deve ser maior que 0\n");
                                    }
                                    else{
                                        printf("\nA quantia excede o limite máximo para a cédula selecionada\n");
                                    }
                                }
                                else{
                                    printf("\na cédula selecionada já está no limite\n");
                                }
                                break;
                            case 50:
                                if(c50<100)
                                {
                                    printf("\nDigite a quantia que deseja adicionar: \n");
                                    scanf("%d",&quantia);
                                    if((c50+quantia<=400)&&(quantia>0))
                                    {
                                        c50+=quantia;
                                        printf("\nQuantia adicionada");
                                    }
                                    else if(quantia<=0){
                                        printf("\na quantia deve ser maior que 0");
                                    }
                                    else{
                                        printf("\nA quantia excede o limite máximo para a cédula selecionada");
                                    }
                                }
                                else{
                                    printf("a cédula selecionada já está no limite");
                                }
                                break;
                            case 20:
                                if(c20<800)
                                {
                                    printf("\nDigite a quantia que deseja adicionar: ");
                                    scanf("%d",&quantia);
                                    if((c20+quantia<=800)&&(quantia>0))
                                    {
                                        c20+=quantia;
                                        printf("\nQuantia adicionada");
                                    }
                                    else if(quantia<=0){
                                        printf("\na quantia deve ser maior que 0");
                                    }
                                    else{
                                        printf("\nA quantia excede o limite máximo para a cédula selecionada");
                                    }
                                }
                                else{
                                    printf("a cédula selecionada já está no limite");
                                }
                                break;
                            case 10:
                                if(c10<1600)
                                {
                                    printf("\nDigite a quantia que deseja adicionar: ");
                                    scanf("%d",&quantia);
                                    if((c10+quantia<=1600)&&(quantia>0))
                                    {
                                        c20+=quantia;
                                        printf("\nQuantia adicionada");
                                    }
                                    else if(quantia<=0){
                                        printf("\na quantia deve ser maior que 0");
                                    }
                                    else{
                                        printf("\nA quantia excede o limite máximo para a cédula selecionada");
                                    }
                                }
                                else{
                                    printf("a cédula selecionada já está no limite");
                                }
                                break;   
                            case 5:
                                if(c5<3200)
                                {
                                    printf("\nDigite a quantia que deseja adicionar: ");
                                    scanf("%d",&quantia);
                                    if((c5+quantia<=3200)&&(quantia>0))
                                    {
                                        c5+=quantia;
                                        printf("\nQuantia adicionada");
                                    }
                                    else if(quantia<=0){
                                        printf("\na quantia deve ser maior que 0");
                                    }
                                    else{
                                        printf("\nA quantia excede o limite máximo para a cédula selecionada");
                                    }
                                }
                                else{
                                    printf("a cédula selecionada já está no limite");
                                }
                                break;
                            case 2:
                                if(c2<6400)
                                {
                                    printf("\nDigite a quantia que deseja adicionar: ");
                                    scanf("%d",&quantia);
                                    if((c2+quantia<=6400)&&(quantia>0))
                                    {
                                        c2+=quantia;
                                        printf("\nQuantia adicionada");
                                    }
                                    else if(quantia<=0){
                                        printf("\na quantia deve ser maior que 0");
                                    }
                                    else{
                                        printf("\nA quantia excede o limite máximo para a cédula selecionada");
                                    }
                                }
                                else{
                                    printf("a cédula selecionada já está no limite");
                                }
                                break;
                            case 1:
                                if(c1<800)
                                {
                                    printf("\nDigite a quantia que deseja adicionar: ");
                                    scanf("%d",&quantia);
                                    if((c1+quantia<=12400)&&(quantia>0))
                                    {
                                        c1+=quantia;
                                        printf("\nQuantia adicionada");
                                    }
                                    else if(quantia<=0){
                                        printf("\na quantia deve ser maior que 0");
                                    }
                                    else{
                                        printf("\nA quantia excede o limite máximo para a cédula selecionada");
                                    }
                                }
                                else{
                                    printf("a cédula selecionada já está no limite");
                                }
                                break;
                            case 0:
                                break;
                            default:
                                printf("Opção inválida");
                                break;
                        }
                    }
                }   
            }   
        }   
    }
}