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
//funcao para creditar
//funcao para transfer
bool existe_conta (int n, int* num, int conta);

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

 return 0;
}

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
		return false;
	} else{
		return true;
	}
}
