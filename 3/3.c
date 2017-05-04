#include <stdio.h>
#include <locale.h>
int topo;
int pilha[500];


int pilha_cheia(){
	if(topo==499){
		return 1;
	}
	return 0;
}

void empilha(int valor){
	if(pilha_cheia()==0){
	topo++;
	pilha[topo]=valor;		
	}
}

int calculadora(int n){
	
	while(n>0){
		if(n==1){
			empilha(1);
			break;
		}else{
			empilha(n%2);
			n=n/2;
			}
	}
	
	return *pilha;

}

int main(){
	int n, i;
	
	setlocale(LC_ALL,"portuguese");
	
	printf("Digite um número em decimal: \n");
	scanf("%d", &n);
	if(n>0){
		topo=-1;	
		calculadora(n);
		
		printf("Em binario %d fica ", n);
	
		for(i=topo;i>=0;i--){
			printf("%d", pilha[i]);
		}
	}else{
		printf("Numero negativo! Erro.");
	}
	
	
	
	return 0;
}
