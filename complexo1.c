#include <stdio.h>
#include <locale.h>

	int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int numerador, denominador;
	float result;
    // resolvi o problema de guardar uma quantidade que � 
    // composta de duas quantidades.

    float r1 = 5; // parte real do n�mero 1
    float i1 = 10; // parte imagin�ria do n�mero 1
    float r2 = 5; // parte real do n�mero 2
    float i2 = 10; // parte imagin�rio do número 2

    /*
    // exibir texto
    printf("entre com real 1: ");
    // pedir um n�mero para o usu�rio
    scanf("%f", &r1); 
    // exibir texto
    printf("entre com imagin�rio 1: ");
    // pedir um n�mero para o usu�rio
    scanf("%f", &i1);

    printf("entre com real 2: ");
    scanf("%f", &r2);
    printf("entre com imagin�rio 2: ");
    scanf("%f", &i2);
    */

    // fazer a soma de complexo com complexo
    float r3 = r1 + r2;
    float i3 = i1 + i2;

    // fazer a subtra��o de complexo com im�ginario
    float r4 = r1 - r2;
    float i4 = i1 - i2;

    // fazer a multipli��o de complexo com complexo
    float r5 = r1*r2 - i1*i2;  // primeiro erro, aqui deve ser subtra��o!
    float i5 = i1*r2 + r1*i2;

    // fazer a divis�o de um complexo com complexo
    float q = r2*r2 + i2*i2;  
    float r6 = r1 * r2 / q + i1 * i2 / q;
    float i6 = -r1 * i2 / q + i1 * r2 / q;

    // agora fazer a sa�da do resultados
    printf("sa�da da soma          : (%f,%fj)\n", r3, i3);
    printf("sa�da da subtra��o     : (%f,%fj)\n", r4, i4);
    printf("sa�da da multipli��o   : (%f,%fj)\n", r5, i5);
    printf("sa�da da divis�o       : (%f,%fj)\n", r6, i6);

    return 0; // explicar esse tal de return 0
}
