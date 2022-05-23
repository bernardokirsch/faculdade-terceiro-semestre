#include <stdio.h>
#include <locale.h>

void main (void) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int a;
	char b[10];
	
	printf ("\n Digite o número decimal: ");
	scanf("%d", &a);

	itoa(a,b,2); 
	
	printf ("\n Decimal: %d		Binário: %s		Hexadecimal: %X", a, b, a);
	
	//printf("\n O número %d em binário é: %s ", a,b);
	//printf("\n O número %d em hexadecimal é: %X ", a,a);
	
}
