#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
char SISTEMA;
char apresenta(){
	setlocale(LC_ALL,"portuguese");
	/*
	.::::.  ::      .::::.  ||
	::  ::  ::      ::  ::  ||
	::  ::  ::      ::::::  ||
	*::::*  ::::::  ::  ::  ::
    */
	printf("\t.::::.  ::      .::::.  ||\n");
	usleep(200000);
	printf("\t::  ::  ::      ::  ::  ||\n");
	usleep(200000);
	printf("\t::  ::  ::      ::::::  ||\n");
	usleep(200000);
	printf("\t*::::*  ::::::  ::  ::  ::\n\n");
	printf("\tPOR GENTILEZA, INFORME QUAL SISTEMA OPERACIONAL VC UTILIZA:\nD=DOS\nU=UNIX\n\n");
	printf("\tDUVIDAS? DIGITE (i) PARA MAIS INFORMAÇÕES\n");
	pergunta:
	fflush(stdin);
	scanf("%c",&SISTEMA);
	SISTEMA=toupper(SISTEMA);
	switch(SISTEMA){
		case 'D':
		system("cls");
		fflush(stdin);
		break;
		case 'U':
		system("clear");
		fflush(stdin);
		break;
		case 'I':
		printf("\nDOS = Window\nUNIX = Mac e Linux(há exeções)");
		getchar();
		goto pergunta;
		break;
		default:
		printf("\nENTRADA INVALIDA, FAVOR DIGITAR SOMENTE AS LETRAS INDICADAS\n");
		goto pergunta;
	}
	return SISTEMA;
}

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
	setlocale(LC_ALL,"portuguese");
	inicio=NULL;
	inicioMaior==NULL;
}

no *criaNo(char nome[], int cod, int qtd, float pc, float pv){//cria nós da estrutura de prods
	setlocale(LC_ALL,"portuguese");
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

maior *criaNoMaior(int cod, int qtd, float pc, float pv, char nome[]){//cria nós da estrutura de prods caros
	setlocale(LC_ALL,"portuguese");
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
	
	return aux;
}

void insereMaior(int cod, int qtd, float pc, float pv, char nome[]){// insere na struct de prods caros
	setlocale(LC_ALL,"portuguese");
	maior *aux;
	aux = criaNoMaior(cod, qtd, pc, pv, nome);
	
	aux->prox=inicioMaior;
	inicioMaior=aux;
}

void percorre(int i){//reaproveitando código através do parâmetro que indicará a ocasião
	setlocale(LC_ALL,"portuguese");
	if(i==1){
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
	}else{
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
}

no *busca(int cod){
	setlocale(LC_ALL,"portuguese");
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


int verifica(char nome[], int cod, int qtd, float pc, float pv){//verifica se existe código igual já cadastrado
	setlocale(LC_ALL,"portuguese");
	no *aux;
	aux = inicio;
	
	if(aux==NULL){//se tiver no inicio da lista deixa inserir
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
	setlocale(LC_ALL,"portuguese");
	no *aux;
	aux = inicio;
	maior *aux2;
	
	aux2=criaNoMaior(cod, qtd, pc, pv, nome);

 	if(inicioMaior==NULL){ //se a lista estiver vazia o primeiro será o mais caro
 		inicioMaior = aux2;

 	}else if(aux2->pv > inicioMaior->pv){
 		inicioMaior = aux2;
 		inicioMaior->prox = NULL;

 	}else if(aux2->pv == inicioMaior->pv){
 		aux2->prox=inicioMaior;
 		inicioMaior = aux2;

 	}

 }	

 void insere(char nome[], int cod, int qtd, float pc, float pv){
 	setlocale(LC_ALL,"portuguese");
 	no *aux;
 	int x, z;
 	x=verifica(nome, cod, qtd, pc, pv);

	if(x==1){//se nao tiver codigo igual insere
		aux = criaNo(nome, cod, qtd, pc, pv);
		aux->prox=inicio;
		inicio=aux;

		verificaPreco(nome, cod, qtd, pc, pv);//Irá verificiar e adicionar no struct dos produtos caros
		if (SISTEMA == 'D')
			system("pause");
		else
			getchar();
	}else{
		printf("Código existente. Insira novamente com outro código diferente.\n\n");
		if (SISTEMA == 'D')
			system("pause");
		else
			getchar();
	}
	
}

void pegaDados(){
	setlocale(LC_ALL,"portuguese");
	int cod, qtd;
	char nome[100], resp;
	float pc, pv;
	
	fflush(stdin);
	printf("Digite o nome: \n");
	fgets(nome,100,stdin);	
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
	printf("Digite o preço de compra: \n");//utilizar vírgula para separar real de centavos nesse e no outro
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
	
	int op, cod, qtd, c;
	char nome[100], resp;
	float pc, pv;

	SISTEMA=apresenta();
	criaLista(); //cria a lista dos caros e a dos produtos
	
	printf("Bem-vindo. Digite os dados do primeiro produto: \n\n");
	pegaDados();
	if (SISTEMA == 'D')
		system("cls");
	else
		system("clear");
	
	do{
		printf("1- Inserir dados de novo produto\n2- Consultar dados de um produto\n3- Imprimir dados de todos os produtos\n4- Imprimir produto(s) mais caro(s)\n5- Sair\n\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
			pegaDados();					
			if (SISTEMA == 'D')
				system("cls");
			else
				system("clear");
			break;

			case 2:
			if (SISTEMA == 'D')
				system("cls");
			else
				system("clear");
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
			if (SISTEMA == 'D')
				system("cls");
			else
				system("clear");
			percorre(1);
			break;

			case 4:
			if (SISTEMA == 'D')
				system("cls");
			else
				system("clear");
			percorre(2);
			break;

			case 5:
			if (SISTEMA == 'D')
				system("cls");
			else
				system("clear");
			printf("Saindo...");
			break;

			default:
			if (SISTEMA == 'D')
				system("cls");
			else
				system("clear");
			printf("Opção inválida...\n");
			break;
		}

	if(op==5){//para o do...while quando a opção é 5 para que não pergunte se deseja continuar
		break;
	}
	
	printf("Deseja continuar? Digite \"1\" para sim.\n");
	scanf("%d", &c);
}while(c==1);

return 0;
}
