/*Fa�a um programa em C que gerencie os dados de produtos de uma
loja atrav�s do uso de listas simplesmente encadeadas. Os dados
dos produtos s�o: c�digo, nome, quantidade em estoque, pre�o de
compra, pre�o de venda.

O programa deve apresentar um menu com as seguintes op��es:
1- Inserir dados de novo produto
2- Consultar dados de um produto
3- Imprimir dados de todos os produtos
4- Imprimir produto mais caro
5- Sair

Obs.:
- O usu�rio pode cadastrar produtos enquanto desejar, isto �, o
limite de cadastro � a mem�ria do computador.
- Em caso de haver mais de um produto com maior pre�o de venda,
todos devem ser impressos*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct no{
	int cod, qtd;
	char nome[100];
	float pc, pv;
	struct no *prox;
}no;

no *inicio;

void criaLista(){
	inicio=NULL;
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

void insere(char nome[], int cod, int qtd, float pc, float pv){
	no *aux;
	aux = criaNo(nome, cod, qtd, pc, pv);
	printf("foi");
	aux->prox=inicio;
	inicio=aux;
}

void percorre(){
	no *aux;
	aux=inicio;
	
	while(aux!=NULL){
		printf("%s, ", aux->nome);
		printf("c�digo: %d, ", aux->cod);
		printf("quantidade em estoque %d, ", aux->qtd);
		printf("pre�o de compra %.2f, ", aux->pc);
		printf("pre�o de venda %.2f.\n\n", aux->pv);
		
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

void pegaDados(){
	int cod, qtd;
	char nome[100], resp;
	float pc, pv;
	
	fflush(stdin);
	printf("Digite o nome: \n");
	gets(nome);	
	printf("Digite o c�digo: \n");
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
	printf("Digite o pre�o de compra: \n");
	scanf("%f", &pc);
	if(pc<=0){	
		while(pc<=0){
			printf("Digite um pre�o de compra maior que zero.\n");
			scanf("%f", &pc);
			}
		}
	printf("Digite o pre�o de venda: \n");
	scanf("%f", &pv);
	if(pv<0){	
		while(pv<=0){
			printf("Digite um pre�o de venda maior que zero.\n");
			scanf("%f", &pv);
			}
		}
	insere(nome, cod, qtd, pc, pv);
	
	
}
int main(){
	setlocale(LC_ALL,"portuguese");
	int op, cod, qtd, c;
	char nome[100], resp;
	float pc, pv;
	
	criaLista();
	
	printf("Bem-vindo. Digite os dados do primeiro produto: \n\n");
	pegaDados();
	
	
	system("cls");
	
	do{
		printf("1- Inserir dados de novo produto\n2- Consultar dados de um produto\n3- Imprimir dados de todos os produtos\n4- Imprimir produto mais caro\n5- Sair\n\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				do{
					pegaDados();					
					system("cls");
					
					printf("Deseja continuar? Digite \"S\" para sim.\n");
					scanf("%s", &resp);
					resp=toupper(resp);
				}while(resp=='S');
				
				
				break;
			case 2:
				system("cls");
				printf("Digite o c�digo do produto desejado: \n");
				scanf("%d", &cod);
				no *aux;
				aux=busca(cod);
				if(aux!=NULL){
					printf("%s, ", aux->nome);
					printf("c�digo: %d, ", aux->cod);
					printf("quantidade em estoque %d, ", aux->qtd);
					printf("pre�o de compra %.2f, ", aux->pc);
					printf("pre�o de venda %.2f.\n\n", aux->pv);
				}else{
					printf("N�o encontrado!");
				}
				break;
			case 3:
				system("cls");
				percorre();
				break;
			default:
				printf("Erro\n");
				break;
				
		}
	

	printf("Deseja continuar? Digite \"1\" para sim.\n");
	scanf("%d", &c);
	}while(c==1);

return 0;
}
