#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* struct ficha_de_aluno
  {
    char nome[50];
    char disciplina[30];
    float nota_prova1;
    float nota_prova2;
  };*/
  
  
//funcao para verificar se a conta existe
bool existe_conta (int n, int* num, int conta){
	bool achou = 0;
	while (!achou){
		for (int i = 0; i < n; i++){
			if (conta == num[i]){
				achou = 1;
			}
	}	
		break;
	}
	if (!achou){
		return 0;
	} else{
		return 1;
	}
}

//funcao para creditar
int creditar (int n, int* num, float* sal, float valor, int conta){
	for (int i = 0; i < n; i++){
		if (conta == num[i]){
			sal[i] -= valor;
		}
	}
}

//funcao para debitar
int debitar (int n, int* num, float* sal, float valor, int conta){
	for (int i = 0; i < n; i++){
		if (conta == num[i]){
			sal[i] += valor;
		}
	}
}

// funçao para imprimir o saldo
int saldo (int n, int* num, float* sal, int conta){
	for (int i = 0; i < n; i++){
		if (conta == num[i]){
			printf("seu saldo eh de R$%.2f\n", sal[i]);
		}
	}
}

//funcao para transferir
int tranferir (int n, int* num, float* sal, float valor, int conta, int destino){
	for (int i = 0; i < n; i++){
		if (conta == num[i]){
		creditar (n, num, sal, valor, conta);
		}
	}
	for (int i = 0; i < n; i++){
		if (destino == num[i]){
		debitar (n, num, sal, valor, destino);
		}
	}
}

int main (){
	int  n=0;
	char buf[255];
	
	printf("digite o numero de contas a serem criadas: ");
	n = atoi(fgets(buf, 255, stdin));
	
	struct banco
	{
	int num[n];
	char tipo [35];
	float sal[n];	
	};
    
    struct banco conta;
    
	int res = 1, numero, destino;
	float valor;
	
	//for para inserir o numero de cada conta
	for (int i = 0; i < n; i++){
		printf("digite o numero da %da conta: ", i+1);
		conta.num[i] = atoi(fgets(buf, 35, stdin));
		conta.sal[i] = 0;
	}
	
	system("cls");
	
	//for para inserir o tipo de cada conta
	for (int i = 0; i < n; i++){
		printf("digite o tipo da %da conta: ", i+1);
		fgets(conta.tipo, 35, stdin);
	}
	
	while (res != 0){
		printf("..MENU.. \n1 - credito\n2 - debito\n3 - transferir\n4 - consultar saldo\nselecione uma opcao(0 para sair): ");
		scanf("%d", &res);	
		
		system("cls");
		
		//credito
		if (res == 1){
			
			printf("qual o numero da conta? ");
			scanf("%d", &numero);
			printf("qual o valor a ser creditado? ");
			scanf("%f", &valor);
			
			system("cls");
			
		if(existe_conta (n, conta.num, numero) == true){
			creditar(n, conta.num, conta.sal, valor, numero);
			printf("operacao realizada com sucesso\n");
			system("pause");
		} else {
			printf("erro, a conta nao existe\n");
			system("pause");
		}
	}
		//debito
		if (res == 2){
			
			printf("qual o numero da conta? ");
			scanf("%d", &numero);
			printf("qual o valor a ser debitado? ");
			scanf("%f", &valor);
			
			system("cls");
			
		if(existe_conta (n, conta.num, numero) == true){
			debitar(n, conta.num, conta.sal, valor, numero);
			printf("operacao realizada com sucesso\n");
			system("pause");
			} else {
			printf("erro, a conta nao existe\n");
			system("pause");
		}
	}
		//tranferencia
		if (res == 3){

			printf("digite o numero da conta de origem: ");
			scanf("%d", &numero);
			printf("digite o numero da conta de destino: ");
			scanf("%d", &destino);
			printf("digite o valor a ser tranferido: ");
			scanf("%f", &valor);
			
			//isso aqui é pra verificar se as duas contas existem
			if((existe_conta (n, conta.num, numero) == true) || (existe_conta (n, conta.num, destino) == true)){
			tranferir (n, conta.num, conta.sal, valor, numero, destino);
			printf("operacao realizada com sucesso\n");
			system("pause");
		      } else {
			printf("erro, a conta nao existe\n");
			system("pause");
			}
		}
		
		//consulta de saldo
		if (res == 4){
			
			printf("qual o numero da conta? ");
			scanf("%d", &numero);
			
			system("cls");
			
		if(existe_conta (n, conta.num, numero) == true){
			saldo (n, conta.num, conta.sal, numero);
			system("pause");
		} else {
			printf("erro, a conta nao existe\n");
			system("pause");
			}
		}
	}
	
 return 0;
}




