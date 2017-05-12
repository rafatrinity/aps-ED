/*- Em caso de haver mais de um produto com maior preço de venda,
todos devem ser impressos*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct maior{
	int cod, qtd;
	char nome[100];
	float pc, pv;
	struct maior *prox;
}maior;

maior *inicioMaior;

typedef struct no{
	int cod, qtd;
	char nome[100];
	float pc, pv;
	struct no *prox;
}no;

no *inicio;

void criaLista(){
	inicio=NULL;
	inicioMaior==NULL;
}

no *criaNo(char nome[], int cod, int qtd, float pc, float pv){
	no *aux;
	aux = (no*) malloc(sizeof(no));
	
	if(aux){
		aux->cod=cod;
		aux->qtd=qtd;
		aux->pc=pc;
		aux->pv=pv;
		strcpy(aux->nome, nome);
		
		aux->prox=NULL;
	}
	
	return aux;
}

maior *criaNoMaior(int cod, int qtd, float pc, float pv, char nome[]){
	maior *aux;
	aux = (maior*)malloc(sizeof(maior));
	
	if(aux){
		aux->cod=cod;
		aux->qtd=qtd;
		aux->pc=pc;
		aux->pv=pv;
		strcpy(aux->nome, nome);
		
		aux->prox=NULL;
	}
}

void insereMaior(int cod, int qtd, float pc, float pv, char nome[]){
	maior *aux;
	aux = criaNoMaior(cod, qtd, pc, pv, nome);
	
	aux->prox=inicioMaior;
	inicioMaior=aux;
}
	
void percorre(){
	no *aux;
	aux=inicio;
	
	while(aux!=NULL){
		printf("%s, ", aux->nome);
		printf("código: %d, ", aux->cod);
		printf("quantidade em estoque %d, ", aux->qtd);
		printf("preço de compra %.2f, ", aux->pc);
		printf("preço de venda %.2f.\n\n", aux->pv);
		
		aux=aux->prox;
	}
}

void percorreProd(){
	maior *aux;
	aux = inicioMaior;
	
	while(aux!=NULL){
		printf("%s, ", aux->nome);
		printf("código: %d, ", aux->cod);
		printf("quantidade em estoque %d, ", aux->qtd);
		printf("preço de compra %.2f, ", aux->pc);
		printf("preço de venda %.2f.\n\n", aux->pv);
		
		aux=aux->prox;
	}
}

no *busca(cod){
	no *aux;
	aux=inicio;
	
	while(aux!=NULL){
		if(aux->cod==cod){
			return aux;
		}
		aux=aux->prox;
	}
	
	return NULL;
}


int verifica(char nome[], int cod, int qtd, float pc, float pv){
	no *aux;
	aux = inicio;
	
	if(inicio==NULL){//se tiver no inicio da lista deixa inserir
		return 1;
	}else{
		while(aux!=NULL){
			if(cod==aux->cod){
				return 0;
			}
			
			aux=aux->prox;
		}
		return 1; //nao encontrou igual
	}
	
}

void verificaPreco(char nome[], int cod, int qtd, float pc, float pv){
	no *aux;
	aux = inicio;
	maior *aux2;
	aux2 = (maior*) malloc(sizeof(maior));
	
	aux2->cod = aux->cod;
	aux2->pc = pc;
	aux2->pv = pv;
	aux2->qtd = qtd;
	strcpy(aux2->nome, nome);
	aux2->prox=NULL;

 	if(inicioMaior==NULL){ //se a lista estiver vazia o promeiro será o mais caro
		inicioMaior = aux2;
		return ;
		
	}else if(aux2->pv > inicioMaior->pv){
		inicioMaior = aux2;
		inicioMaior->prox = NULL;
		return ;
		
	}else if(aux2->pv == inicioMaior->pv){
		aux2->prox=inicioMaior;
		inicioMaior = aux2;
		return ;
			
	}else{
		return ;
		}
	
	}	


void insere(char nome[], int cod, int qtd, float pc, float pv){
	no *aux;
	int x, z;
	x=verifica(nome, cod, qtd, pc, pv);

	if(x==1){//se nao tiver codigo igual insere
		aux = criaNo(nome, cod, qtd, pc, pv);
		aux->prox=inicio;
		inicio=aux;
	
		verificaPreco(nome, cod, qtd, pc, pv);//Irá verificiar e add no struct dos produtos caros
		system("pause");
	}else{
		printf("Código existente. Insira novamente com outro código.\n\n");
		system("pause");
	}
	
}

void pegaDados(){
	int cod, qtd;
	char nome[100], resp;
	float pc, pv;
	
	fflush(stdin);
	printf("Digite o nome: \n");
	gets(nome);	
	printf("Digite o código: \n");
	scanf("%d", &cod);
	printf("Digite a quantidade em estoque: \n");
	scanf("%d", &qtd);
	if(qtd<0){
		while(qtd<0){
			printf("Digite uma quantidade em estoque maior ou igual a zero.\n");
			scanf("%d", &qtd);
			}
	}
	fflush(stdin);
	printf("Digite o preço de compra: \n");
	scanf("%f", &pc);
	if(pc<=0){	
		while(pc<=0){
			printf("Digite um preço de compra maior que zero.\n");
			scanf("%f", &pc);
			}
		}
	printf("Digite o preço de venda: \n");
	scanf("%f", &pv);
	if(pv<=0){	
		while(pv<=0){
			printf("Digite um preço de venda maior que zero.\n");
			scanf("%f", &pv);
			}
		}
		
	insere(nome, cod, qtd, pc, pv);
	
}

int main(){
	setlocale(LC_ALL,"portuguese");
	int op, cod, qtd, c, x;
	char nome[100], resp;
	float pc, pv;
	no *aux2;
	
	criaLista();
	
	printf("Bem-vindo. Digite os dados do primeiro produto: \n\n");
	pegaDados();
	
	
	system("cls");
	
	do{
		printf("1- Inserir dados de novo produto\n2- Consultar dados de um produto\n3- Imprimir dados de todos os produtos\n4- Imprimir produto(s) mais caro(s)\n5- Sair\n\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				do{
					pegaDados();					
					system("cls");
					
					printf("Deseja continuar o cadastro? Digite \"S\" para sim.\n");
					scanf("%s", &resp);
					resp=toupper(resp);
				}while(resp=='S');
				
				break;
			case 2:
				system("cls");
				printf("Digite o código do produto desejado: \n");
				scanf("%d", &cod);
				no *aux;
				aux=busca(cod);
				if(aux!=NULL){
					printf("%s, ", aux->nome);
					printf("código: %d, ", aux->cod);
					printf("quantidade em estoque %d, ", aux->qtd);
					printf("preço de compra %.2f, ", aux->pc);
					printf("preço de venda %.2f.\n\n", aux->pv);
				}else{
					printf("Não encontrado!");
				}
				break;
			case 3:
				system("cls");
				percorre();
				break;
			case 4:
				system("cls");
				percorreProd();
				break;
				
			default:
				system("cls");
				printf("Saindo...\n");
				return 0;
				break;
				
		}
	

	printf("Deseja continuar? Digite \"1\" para sim.\n");
	scanf("%d", &c);
	}while(c==1);

return 0;
}
