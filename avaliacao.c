#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int folha=0;

struct nodo {
    int dado;              // Nodo ser� armazenado como inteiro
    struct nodo *sad;      // Sub �rvore direita
    struct nodo *sae;      // Sub �rvore esquerda
};

//Fun��o para criar um nodo
struct nodo* novoNodo(int x){
    struct nodo *p;
    p = malloc(sizeof(struct nodo));
    p->dado = x;
    p->sae = NULL;
    p->sad = NULL;
    return p;
}

//Fun��o para inserir um valor
struct nodo* inserir(struct nodo *raiz, int x){
    if(raiz == NULL)
        return novoNodo(x);
    else if(x > raiz->dado) //x � maior, ent�o inserir a�direita
            raiz->sad = inserir(raiz->sad, x);
         else  //x � menor, ent�o inserir a esquerda
            raiz->sae = inserir(raiz->sae, x);
    return raiz;
}

//Buscar um valor na �rvore
struct nodo* buscar(struct nodo *raiz, int x)
{
    if(raiz == NULL || raiz->dado == x) //Se raiz->dado igual a x o elemento foi encontrado
        return raiz;
    else if(x > raiz->dado) //Se x � maior, buscar na sub �rvore direita
        return buscar(raiz->sad, x);
    else  //Se x � menor, buscar na sub�rvore esquerda
        return buscar(raiz->sae, x);
}

//Exibe quantidade de nodos da �rvore
int numeroNodos(struct nodo *raiz){
    if(raiz == NULL) return(0);
    return (numeroNodos(raiz->sae) + 1 + numeroNodos(raiz->sad));
}

//Exibir estrutura da �rvore
void exibirArvore(struct nodo *raiz){
    if (raiz != NULL){
        printf("%i", raiz->dado);
        printf("(");
        exibirArvore(raiz->sae);
        exibirArvore(raiz->sad);
        printf(")");
    }
    else printf("()"); 
}

//encontra o menor nodo de uma �rvore/sub�rvore
struct nodo* menorNodo(struct nodo *raiz)
{
    if(raiz == NULL) return NULL;
    else if(raiz->sae != NULL) return menorNodo(raiz->sae);
    return raiz;
}

//encontra o maior nodo de uma �rvore/sub�rvore
struct nodo* maiorNodo(struct nodo *raiz)
{
    if(raiz == NULL) return NULL;
    else if(raiz->sad != NULL) return maiorNodo(raiz->sad);
    return raiz;
}

//Fun��o para encontrar os nodos folha
//enviada pelo colega Gabriel Vargas Padilha
void exibirFolhas(struct nodo *raiz){
    if (raiz != NULL){
        if (raiz->sae == NULL && raiz->sad == NULL) {
            printf("%i, ", raiz->dado);
        }
        exibirFolhas(raiz->sae);
        exibirFolhas(raiz->sad); 
    }
    else printf(""); 
}

//excluir
void excluir(struct nodo *raiz, int dado) {
	
	struct nodo *temp;
	
    if (raiz == NULL) {
       printf ("Dado n�o existe na �rvore!");
    }
    
    else if (dado < raiz->dado) {
    	excluir(raiz->sae, dado);
	}
       
    else if (dado > raiz->dado) {
    	excluir(raiz->sad, dado);
	}
    
	else {
        temp = raiz;
        
        if (raiz->sae == NULL && raiz->sad == NULL) {
            free(temp);
            raiz = NULL; 
        }
        
    	else {
            if (raiz->sae == NULL) {
				raiz = raiz->sad;
	            temp->sad = NULL;
	            free(temp);
				temp = NULL;
            }
            else {
                if (raiz->sad == NULL) {
                    raiz = raiz->sae;
                    temp->sae = NULL;
                    free(temp);
					temp = NULL;
                }
                else {
                   temp = maiorNodo(raiz->sae);
                   temp->sae = raiz->sae;
                   temp->sad = raiz->sad;
                   raiz->sae = NULL;
                   raiz->sad = NULL;
                   free(raiz);  
				   raiz = temp;
				   temp = NULL;   
                   }
                }
             }
          }
}

//inorder
void inorder(struct nodo *raiz)
{
   if (raiz == NULL) {
   	return NULL;
   }
   	inorder(raiz->sae);
   	printf (" %d  ", raiz->dado);
   	inorder(raiz->sad);
}

//preorder
void preorder(struct nodo *raiz)
{
   if (raiz == NULL) {
   	return NULL;
   }
   	printf (" %d  ", raiz->dado);
	preorder(raiz->sae);
   	preorder(raiz->sad);
}

//postorder
void postorder(struct nodo *raiz)
{
   if (raiz == NULL) {
   	return NULL;
   }
	postorder(raiz->sae);
   	postorder(raiz->sad);
	printf (" %d  ", raiz->dado);
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
    struct nodo *raiz;

    raiz = novoNodo(45);
    inserir(raiz,33);
    inserir(raiz,52);
    inserir(raiz,14);
    inserir(raiz,50);
    inserir(raiz,58);
    inserir(raiz,51);
    inserir(raiz,55);
    inserir(raiz,63);

    printf ("\n Estrutura da �rvore: ");
    exibirArvore(raiz);
    
    excluir(raiz,58);
    
    printf ("\n Estrutura da �rvore: ");
    exibirArvore(raiz);

    return 0;
}


