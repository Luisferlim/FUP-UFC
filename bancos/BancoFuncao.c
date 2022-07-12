#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*A partir do programa anterior, crie um novo programa chamado BancoFuncao capaz de
armazenar e gerenciar “n” contas bancárias, onde “n” é um número fornecido pelo
usuário. As contas devem ser armazenadas em um vetor. Utilize funções quando
necessário. Não utilize registros ou arquivos. 
*/

// funçao para imprimir o saldo
//funcao para debitar
//funcao para transfer

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
int creditar (int n, int* num, int* sal, int valor, int conta){
	for (int i = 0; i < n; i++){
		if (conta == num[i]){
			sal[i] -= valor;
		}
	}
}

int main (){
	int res = 1, conta, destino, n;
	float valor;
	char tipo [35];

	printf("digite o numero de contas a serem criadas: ");
	scanf("%d", &n);
	
	int num[n];
	int sal[n];

	//for para inserir o numero de cada conta
	for (int i = 1; i <= n; i++){
		printf("digite o numero da %da conta: ", i);
		scanf("%d", &num[i]);
		sal[i] = 0;
	}
	
	while (res != 0){
		printf("..MENU.. \n1 - credito\n2 - debito\n3 - transferir\n4 - consultar saldo\nselecione uma opcao(0 para sair): ");
		scanf("%d", &res);	
		
		system("cls");
		
		//credito
		if (res == 1){
			
			printf("qual o numero da conta? ");
			scanf("%d", &conta);
			printf("qual o valor a ser creditado? ");
			scanf("%f", &valor);
			
			system("cls");
			
		if(existe_conta (n, num, conta) == true){
			creditar(n, num, sal, valor, conta);
			printf("operacao realizada com sucesso");
			system("pause");
		} else {
			printf("erro, a conta nao existe\n");
			system("pause");
		}
}
		
		if (res == 2){
			
		}
		
		if (res == 3){
			
		}
		
		if (res == 4){
			
		}
		else{
		}
		
	}
	
 return 0;
}


