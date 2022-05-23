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
	char nome[30];
	float nota;
	int matricula;
	int id;
}Aluno;

Aluno tab[19];

int hashFunc (int key) {
	return key % 19;
}

void insert (int tab[19], int val) {
	int id = hashFunc(val);
	while (tab[id] != 0) {
		id = hashFunc (id + 1);
	}
	tab[id] = val;
}

Aluno lerAluno (){
	Aluno a;
	
	printf ("\n Informe o nome do aluno: ");
	scanf  ("%s", &a.nome);
	printf ("\n Informe a nota do aluno: ");
	scanf  ("%f", &a.nota);
	printf ("\n Informe a matrícula do aluno: ");
	scanf  ("%d", &a.matricula);
	
	insert (0, a.matricula);
	
	printf ("\n Cadastro realizado com sucesso! \n");
	printf ("\n --------------------------------------------------------------- \n");
}

void imprimeAprovados() {
	Aluno a;
	int i;
	for (i = 0; i < 10; i++) {
		if (tab[i].nota >= 7) {
			printf ("Aluno: %s \t Nota: %.2f \t Matrícula: %d \t Id: %d", a.nome, a.nota, a.matricula, a.id);
		}
	}
}

int search (int tab[], int key) {
	int id = hashFunc(key);
	printf ("\n Hash index: %d", id);
	while (tab[id] != 0) {
		if (tab[id] == key) {
			return tab[id];
		}
		else {
			id = hashFunc (id + 1);
		}
	}
	return 0;
}

void imprimeAluno() {
	Aluno a;
	
	printf ("\n Faça sua busca pela matrícula do aluno: ");
	scanf  ("%d", a.matricula);
	search (a.id, a.matricula);
}

void searchAll() {
	Aluno a;
	int i;
	
	for (i = 0; i < 10; i++) {
		printf ("Aluno: %s \t Nota: %.2f \t Matrícula: %d \t Id: %d", a.nome, a.nota, a.matricula, a.id);
		printf ("\n --------------------------------------------------------------- \n");
	}
}

void imprimeAlunos() {
	Aluno a;
	
	searchAll();
}

void main (void) {
	setlocale(LC_ALL, "Portuguese");
	
	int op, matricula;
	char nome[30];
	float nota;
	
	printf ("\n 1 - Cadastrar aluno");
	printf ("\n 2 - Listar aprovados (nota >= 7)");
	printf ("\n 3 - Listar aluno");
	printf ("\n 4 - Listar todos os alunos");
	printf ("\n 5 - Sair");
	printf ("\n Informe a opção desejada: ");
	scanf  ("%d", &op);
	
	do {
		switch (op) {
			case 1 :
				lerAluno();
			break ;
				
			case 2 :
				imprimeAprovados();
			break;
		
			case 3 :
				imprimeAluno();
			break;
		
			case 4 :
				imprimeAlunos();
			break;
				
			default :
				printf ("\n Opção inválida!");
			break;
		}
	} while (op != 5);
}

