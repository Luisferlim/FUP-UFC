#include <stdio.h>
#include <stdlib.h>

int num1, num2, num3, res = 1, conta, destino;
float sal1 = 0, sal2 = 0, sal3 = 0, valor;
char tipo [35];

int main (){
		printf("digite o numero da primeira conta: ");
	scanf("%d", &num1);
		printf("digite o numero da segunda conta: ");
	scanf("%d", &num2);
		printf("digite o numero da terceira conta: ");
	scanf("%d", &num3);
	
	system("cls");
	
	while (res != 0){
			printf("..MENU.. \n1 - credito\n2 - debito\n3 - transferir\n4 - consultar saldo\nselecione uma opcao(0 para sair): ");
			scanf("%d", &res);
			
			system("cls");
			
			//credito
			if (res == 1){
				
				printf("digite o numero da conta: ");
				scanf("%d", &conta);
				printf("qual o valor a ser creditado? ");
				scanf("%f", &valor);
				system("cls");
				
				//se for igual a conta 1
				if (conta == num1){
					sal1 -= valor;
				}
				//se for igual a conta 2
				else if (conta == num2){
					sal2 -= valor;
				} 
				//se for igual a conta 3
				else if (conta == num3){
					sal3 -= valor;
				} 
				//se não for igual a nenhuma conta
				else{
					printf("erro, retornando ao menu\n");
					system("pause");
				}
				
			}
			
			//debito
			if (res == 2){
				
				printf("digite o numero da conta: ");
				scanf("%d", &conta);
				printf("qual o valor a ser debitado? ");
				scanf("%f", &valor);
				system("cls");
				
				//se for igual a conta 1
				if (conta == num1){
					sal1 += valor;
				}
				//se for igual a conta 2
				else if (conta == num2){
					sal2 += valor;
				} 
				//se for igual a conta 3
				else if (conta == num3){
					sal3 += valor;
				} 
				//se não for igual a nenhuma conta
				else{
					printf("erro, retornando ao menu\n");
					system("pause");
				}
				
			}
			//transferir
			if (res == 3){
				
				printf("digite o numero da conta de origem: ");
				scanf("%d", &conta);
				printf("digite o numero da conta de destino: ");
				scanf("%d", &destino);
				printf("digite o valor a ser tranferido: ");
				scanf("%f", &valor);
				
				//casos que envolvem a conta 1
				if (conta == num1){
	
					if(destino == num2){
						sal1-= valor;
						sal2+= valor;
					}
					
					if(destino == num3){
						sal1-= valor;
						sal2+= valor;
					}
					
				}
				
				//casos que envolvem a conta 2
				if (conta == num2){
	
					if(destino == num1){
						sal2-= valor;
						sal1+= valor;
					}
					
					if(destino == num3){
						sal2-= valor;
						sal3+= valor;
					}
					
				//casos que envolvem a conta 3
				if (conta == num3){
	
					if(destino == num1){
						sal3-= valor;
						sal1+= valor;
					}
					
					if(destino == num2){
						sal3-= valor;
						sal2+= valor;
					}
				}
				
				if(conta == destino){
					printf("erro, nao se pode tranferir dinheiro pra mesma conta de origem\n");
					system("pause");
				}
				//caso de erro
				 else {
					printf("ocorreu algum erro, retornando ao menu\n");
					system("pause");
				}
			}
		}
		
		    //consultar o saldo
			if (res == 4){
				
				printf("digite o numero da conta: ");
				scanf("%d", &conta);
			
				
				//se for igual a conta 1
				if (conta == num1){
					printf("saldo da conta de numero %d: R$%.2f\n", num1, sal1);
					system("pause");
				}
				//se for igual a conta 2
				else if (conta == num2){
					printf("saldo da conta de numero %d: R$%.2f\n", num2, sal2);
					system("pause");
				} 
				//se for igual a conta 3
				else if (conta == num3){
					printf("saldo da conta de numero %d: R$%.2f\n", num3, sal3);
					system("pause");
				} 
				//se não for igual a nenhuma conta
				else{
					printf("erro, retornando ao menu\n");
					system("pause");
				}
			}
	    }
	    
	    printf("saldo da conta de numero %d: R$%.2f\n", num1, sal1);
	    printf("saldo da conta de numero %d: R$%.2f\n", num2, sal2);
	    printf("saldo da conta de numero %d: R$%.2f\n", num3, sal3);
	    system("pause");
	    
return 0;
}



