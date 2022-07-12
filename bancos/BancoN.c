#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int res = 1, conta, destino, n;
float valor;
char tipo [35];
bool achou = 0;

int main (){
	
	printf("digite o numero de contas a serem criadas: ");
	scanf("%d", &n);
	
	system("cls");
	
	int num[n];
	float sal[n];
	
	//for para inserir o numero das contas
		for (int i = 1; i <= n; i++){
			printf("digite o numero da %da conta: ", i);
			scanf("%d", &num[i]);
			sal[i] = 0;
		}
		
	system("cls");
	
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
				
				//loop para verificar qual a conta a ser creditada e creditar
				while(!achou){
					//verificando se a conta digitada corresponde a alguma existente
					for (int i = 1; i <= n; i++){
						if (conta == num[i]){
							//credito
							sal[i] -= valor;
							achou = 1;
						}
					}
					
					//condição de erro, a conta nao existe
					if (!achou){
						printf("erro conta inexistente, voltando ao menu..\n");
						system ("pause");
						achou = 1;
					}
				}
				
				achou = 0;
			}	
			
			//debito
			if (res == 2){
				
				printf("qual o numero da conta? ");
				scanf("%d", &conta);
				printf("qual o valor a ser debitado? ");
				scanf("%f", &valor);
				system("cls");
				
				//loop para verificar qual a conta a ser debitada e debitar
				while(!achou){
					//verificando se a conta digitada corresponde a alguma existente
					for (int i = 1; i <= n; i++){
						if (conta == num[i]){
							//debito
							sal[i] += valor;
							achou = 1;
						}
					}
					//condição de erro, a conta nao existe
					if (!achou){
						printf("erro conta inexistente, voltando ao menu..\n");
						system ("pause");
						achou = 1;
					}
				}
				
				achou = 0;
	
			}
			
			//transferir
			if (res == 3){
				
				printf("digite o numero da conta de origem: ");
				scanf("%d", &conta);
				printf("digite o numero da conta de destino: ");
				scanf("%d", &destino);
				printf("digite o valor a ser tranferido: ");
				scanf("%f", &valor);
				
				//okay, agora iremos verificar se as contas existem e fazer a transferencia
				while(!achou){
					//verificando se a conta digitada corresponde a alguma existente
					for (int i = 1; i <= n; i++){
						//aqui ele procura a conta de origem
						if (conta == num[i]){
							for (int j = 1; j <= n; j++){
								//aqui ele procura a conta de destino
								if(destino == num[j]){
								//a transferencia em si
									num[i] -= valor;
									num[j] += valor;
										achou = 1;
								}
							}
						}
					}
					
					//condição de erro, uma das contas ou as duas nao existem
					if (!achou){
						printf("erro uma das contas ou as duas inexistem, voltando ao menu..\n");
						system ("pause");
						achou = 1;
					}
				}
				
				achou = 0;
			}	
		
		
		    //consultar o saldo
			if (res == 4){
				printf("digite o numero da conta: ");
				scanf("%d", &conta);
				
					while(!achou){
					//verificando se a conta digitada corresponde a alguma existente
					for (int i = 1; i <= n; i++){
						if (conta == num[i]){
							//imprimindo o valor
							printf("o saldo na conta de numero %d eh R$%.2f\n", conta, sal[i]);
							system ("pause");
							achou = 1;
						}
					}
					
					//condição de erro, a conta nao existe
					if (!achou){
						printf("erro conta inexistente, voltando ao menu..\n");
						system ("pause");
						achou = 1;
					}
				}
			}
		}
	    
	    
return 0;
}
