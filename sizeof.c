#include <stdio.h>
#include <conio.h>

void main (void) {
  
	float vteste;
	printf(" --------- TIPO ---------|--------- BYTES ---------\n");
	printf(" char ..................: %d bytes\n", sizeof(char));
	printf(" unsigned char..........: %d bytes\n", sizeof(unsigned char));
	printf(" signed char............: %d bytes\n", sizeof(signed char));
	printf(" short..................: %d bytes\n", sizeof(short));
	printf(" unsigned short ........: %d bytes\n", sizeof(unsigned short));
	printf(" signed short...........: %d bytes\n", sizeof(signed short));
	printf(" int....................: %d bytes\n", sizeof(int));
	printf(" unsigned int ..........: %d bytes\n", sizeof(unsigned int));
	printf(" signed int.............: %d bytes\n", sizeof(signed int));
	printf(" long int...............: %d bytes\n", sizeof(long int));
	printf(" unsigned long int......: %d bytes\n", sizeof(unsigned long int));
	printf(" signed long int .......: %d bytes\n", sizeof(signed long int));
	printf(" long long int..........: %d bytes\n", sizeof(long long int));
	printf(" unsigned long long int.: %d bytes\n", sizeof(unsigned long long int));
	printf(" signed long long int...: %d bytes\n", sizeof(signed long long int));
	printf(" float..................: %d bytes\n", sizeof(float));
	//printf(" double float...........: %d bytes\n", sizeof(double float));
	printf(" long double............: %d bytes\n", sizeof(long double));
	printf(" void ..................: %d bytes\n", sizeof(void));
	printf(" void *.................: %d bytes\n", sizeof(void*));
	printf("\nO tamanho de vteste e...: %d \n\n", sizeof vteste); 
	  
	getch();
}
