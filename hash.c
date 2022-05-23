/*
Faça um programa que apresente o menu de opções abaixo:
1 - Cadastrar aluno
2 - Listar aprovados (nota >= 7)
3 - Listar aluno
4 - Listar todos os alunos
5 - Sair
As opções devem ser implementadas em uma tabela hashing, utilizando o método do resto da divisão.
Use endereçamento aberto e, como chave, utilize o número da matrícula de cada aluno (composto por 8 dígitos).
Projete tudo para uma turma fixa de 10 alunos.
O cadastro deve contemplar o número da matrícula, o nome e a nota do aluno.
Postar no SIGAA o arquivo com o código em ANSI C.
*/

#include <stdio.h>
#include <locale.h>

typedef struct {
	char nome[20];
	int matricula;
	float nota;	
} Aluno;

Aluno tab[19];

void inicializarTabela() {
	int i;
	for (i = 0; i < 19; i++) {
		tab[i].matricula = -1;
	}
		
}

Aluno lerAluno() {
	Aluno a;
	printf ("\n Informe o nome do aluno: ");
	scanf  ("%s", &a.nome);
	printf ("\n Informe a nota do aluno: ");
	scanf  ("%f", &a.nota);
	printf ("\n Informe a matrícula do aluno: ");
	scanf  ("%d", &a.matricula);
	printf ("\n Cadastro realizado com sucesso! \n");
	printf ("\n --------------------------------------------------------------- \n");
}

int hashFunc (int key) {
	return key % 19;
}

void insert () {
	Aluno aluno1 = lerAluno();
	int id = hashFunc(aluno1.matricula);
	while (tab[id].matricula != -1) {
		id = hashFunc (id + 1);
	}
	tab[id] = aluno1;
}

void imprimir() {
	int i;
	printf ("\n ----------------------TABELA--------------------- \n");
	for (i = 0; i < 19; i++) {
		if (tab[i].matricula != -1) {
			printf ("%s \t %2.f \t %d = %d", tab[i].nome, tab[i].nota, i, tab[i].matricula);
		}
		else {
			printf ("%d = \n", i);
		}
		printf ("\n --------------------------------------------------------------- \n");
	}
}

void aprovado (int nota) {
	if (nota >= 7) {
		printf (" Aprovado");
	}
	else {
		printf (" Reprovado");
	}
}

void main (void) {
	setlocale(LC_ALL, "Portuguese");
	
	int op;
	Aluno *al;
	
	inicializarTabela();
	
	do {
		printf ("\n 1 - Cadastrar aluno");
		printf ("\n 2 - Listar aprovados (nota >= 7)");
		printf ("\n 3 - Listar aluno");
		printf ("\n 4 - Listar todos os alunos");
		printf ("\n 5 - Sair");
		printf ("\n Informe a opção desejada: ");
		scanf  ("%d", &op);
		
		switch (op) {
			case 1 :
				insert();
			break ;
				
			case 2 :
				printf ("");
			break;
			
			case 3 :
				printf ("");
			break;
			
			case 4 :
				imprimir();
			break;
				
			case 5 :
				printf ("");
			break;
				
			default :
				printf ("\n Opção inválida!");
		}
	} while (op != 5);
}
