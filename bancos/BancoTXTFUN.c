#include <stdio.h>

int num;
/*

Refatore o programa chamado BancoTXT, a fim de organizar o código utilizando subrotinas (funções).

*/

typedef struct conta{
    int c;
    float s;
    char t[35];
} acc;

void credito(acc *conta){
    int n;
    float val;
    printf("Entre número da conta e valor a ser creditado: ");
    scanf("%d %f", &n, &val);
    for(int i = 0; i < num; i++){
       if(n == conta[i].c)
        conta[i].s += val;
    }                  
}

void debito(acc *conta){
    int n;
    float val;
    printf("Entre número da conta e valor a ser debitado: ");
    scanf("%d %f", &n, &val);
    for(int i = 0; i < num; i++){
        if(n == conta[i].c)
            conta[i].s -= val;
    }
}

void transferencia(acc *conta){
    int no, nd;
    float val;
    printf("Entre o número da conta de origem, o número da conta de destino e o valor a ser transferido: ");
    scanf("%d %d %f", &no, &nd, &val);
    for(int i = 0; i < num; i++){
        if(no == conta[i].c)
            conta[i].s -= val;
        if(nd == conta[i].c)
            conta[i].s += val;
    }
}

void saldo(acc *conta){
    int n;
    printf("Entre número da conta a ter saldo consultado: ");
    scanf("%d", &n);
    for(int i = 0; i < num; i++){
        if(n == conta[i].c)
            printf("R$%.2f\n", conta[i].s);
    }
}

int main(){
    printf("Entre quantas contas serão: ");
    scanf("%d", &num);
    
    acc conta[num];

    for(int i = 0; i < num; i++){
        conta[i].s = 0;
    }
    
    for(int i = 0; i < num; i++){
        printf("Entre número da conta %d: ", i+1);
        scanf("%d", &conta[i].c);
    }
    
    for(int i = 0 ;  i < num; i++){
        printf("Entre tipo da conta %d: ", i+1);
        setbuf(stdin, NULL);
        fgets(conta[i].t, 35, stdin);
    }
    
    int ent = 1;
    int op;
    
    FILE *file;
    
    while(ent != 0){
        printf("..MENU.. \n1 - credito\n2 - debito\n3 - transferir\n4 - consultar saldo\n5 - remover conta \nselecione uma opcao(0 para sair)");
        scanf("%d", &op);
        if(op == 0)
            ent = 0;
        if(op == 1){
            credito(conta);
        }
        if(op == 2){
            debito(conta);
        }
        if(op == 3){
            transferencia(conta);
        }
        if(op == 4){
            saldo(conta);
        }
    }
    
    file = fopen("banco.txt", "w");
    
    for(int i = 0; i < num; i++){
        if(conta[i].c >= 0){
            fprintf(file, "Número da conta: %d\nTipo da conta: %sSaldo da conta: R$%.2f\n\n", conta[i].c, conta[i].t, conta[i].s);
        }
    }
    
    fclose(file);

    if (file == NULL)
        printf("Erro na abertura do arquivo\n");
    else
        printf("Contas armazenadas no arquivo banco.txt\n");

    return 0;
}







