#include <stdio.h>
#include <stdlib.h>

int res = 1, conta, destino, n;
float valor;
char tipo [35];

int main (){
	
		printf("digite o numero de contas a serem criadas: ");
	scanf("%d", &n);
	
	system("cls");
	
	int num[n];
	float sal[n];
	
	//for para inserir o numero das contas
		for (int i = 0; i < n; i++){
			printf("digite o numero da %da conta: ", i+1);
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
				
				
			}
			
			//debito
			if (res == 2){
				
			}
			//transferir
			if (res == 3){
			}
		
		    //consultar o saldo
			if (res == 4){
				
			}
		}
	    
	    
return 0;
}


