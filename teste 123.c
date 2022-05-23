#include <stdio.h>

int hashFunc (int matricula) {
	return matricula % 19;
}


void main (void) {
	int matricula = 99999704;
	float teste = hashFunc(matricula);
	
	printf ("teste = %f", teste);
	
	getch();
}
