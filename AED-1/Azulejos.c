#include <stdio.h>
#include <stdlib.h>

int main()
{
	//declação de variáveis
	int num,n1,n2,count;
	num=0,n1=0,n2=0,count=0;
	printf("Digite o numero de azulejos presentes\n");
	//entrada de dados
	scanf("%d",&num);
	scanf("%d",&n1);
	scanf("%d",&n2);
	//validação dos dados
	if((num>=3)&&(num<=10000)&&(n1<num)&&(n2<num)){
		//loop pela variavel c
		for(int c=num;c>0;c=c-1)
		{
			//checando os multiplos de n1 e n2 atráves da variável n
			if((c%n1==0)||(c%n2==0))
			{
				count = count + 1;
			}
		}
		//checando se algum azulejo sera pinta
		if(count>0)
		{
			printf("Numero de azulejos que serão pintados: %d\n",count);
		}
		else
		{
			printf("Nenhum azulejo será pintado\n");
		}
	}
	//caso os dados não sejam válidos
	else
	{
		printf("Um ou mais numeros estão excedendo o valor permitido");
	}
}