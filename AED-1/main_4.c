//Faca um programa que informa as duas maiores alturas das mo�as de um concurso de beleza.
//A altura deve estar entre 1.50 e 2.35 e podem existir alturas iguais.
//A quantidade de mo�as termina quando a ultima altura � 0.

#include <stdio.h>
#include <stdlib.h>

#define SAIDA_PRIMEIRA_MAIOR_ALTURA "\nSAIDA_PRIMEIRA_MAIOR_ALTURA = %.2f"
#define SAIDA_SEGUNDA_MAIOR_ALTURA "\nSAIDA_SEGUNDA_MAIOR_ALTURA = %.2f"
#define SAIDA_ALTURA_FORA_LIMITE "\nSAIDA_ALTURA_FORA_LIMITE = %.2f"

int main(int numargs, char *arg[]) {
    float altura, primeiraMaior = 0, segundaMaior = 0;

    for (int i = 1; i < numargs; i++) {
        altura = atof(arg[i]);

        if (altura == 0)
            break;

        if (altura < 1.50 || altura > 2.35) {
            printf(SAIDA_ALTURA_FORA_LIMITE, altura);
            continue;
        }

        if (altura > primeiraMaior) {
            segundaMaior = primeiraMaior;
            primeiraMaior = altura;
        } else if (altura > segundaMaior) {
            segundaMaior = altura;
        }
    }

    printf(SAIDA_PRIMEIRA_MAIOR_ALTURA, primeiraMaior);
    printf(SAIDA_SEGUNDA_MAIOR_ALTURA, segundaMaior);

    return 0;
}
