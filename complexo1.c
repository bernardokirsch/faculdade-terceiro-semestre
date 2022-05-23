#include <stdio.h>
#include <locale.h>

	int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int numerador, denominador;
	float result;
    // resolvi o problema de guardar uma quantidade que é 
    // composta de duas quantidades.

    float r1 = 5; // parte real do número 1
    float i1 = 10; // parte imaginária do número 1
    float r2 = 5; // parte real do número 2
    float i2 = 10; // parte imaginário do nÃºmero 2

    /*
    // exibir texto
    printf("entre com real 1: ");
    // pedir um número para o usuário
    scanf("%f", &r1); 
    // exibir texto
    printf("entre com imaginário 1: ");
    // pedir um número para o usuário
    scanf("%f", &i1);

    printf("entre com real 2: ");
    scanf("%f", &r2);
    printf("entre com imaginário 2: ");
    scanf("%f", &i2);
    */

    // fazer a soma de complexo com complexo
    float r3 = r1 + r2;
    float i3 = i1 + i2;

    // fazer a subtraçõo de complexo com imáginario
    float r4 = r1 - r2;
    float i4 = i1 - i2;

    // fazer a multiplição de complexo com complexo
    float r5 = r1*r2 - i1*i2;  // primeiro erro, aqui deve ser subtraçõo!
    float i5 = i1*r2 + r1*i2;

    // fazer a divisão de um complexo com complexo
    float q = r2*r2 + i2*i2;  
    float r6 = r1 * r2 / q + i1 * i2 / q;
    float i6 = -r1 * i2 / q + i1 * r2 / q;

    // agora fazer a saída do resultados
    printf("saída da soma          : (%f,%fj)\n", r3, i3);
    printf("saída da subtração     : (%f,%fj)\n", r4, i4);
    printf("saída da multiplição   : (%f,%fj)\n", r5, i5);
    printf("saída da divisão       : (%f,%fj)\n", r6, i6);

    return 0; // explicar esse tal de return 0
}
