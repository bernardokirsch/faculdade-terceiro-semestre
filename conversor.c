#include <stdio.h>
#include <locale.h>

void main (void) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int a;
	char b[10];
	
	printf ("\n Digite o n�mero decimal: ");
	scanf("%d", &a);

	itoa(a,b,2); 
	
	printf ("\n Decimal: %d		Bin�rio: %s		Hexadecimal: %X", a, b, a);
	
	//printf("\n O n�mero %d em bin�rio �: %s ", a,b);
	//printf("\n O n�mero %d em hexadecimal �: %X ", a,a);
	
}
