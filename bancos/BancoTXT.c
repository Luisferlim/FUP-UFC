#include <stdio.h>

int num;

int nEx = 0;

typedef struct conta{
    int c;
    float s;
    char t[35];
} acc;

int main(){
    printf("Digite a quantidade de contas: ");
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
        setbuf(stdin, NULL);
        if(op == 0)
            ent = 0;
        if(op == 1){
            int n;
            int exC = 0;
            float val;
            printf("Entre número da conta e valor a ser creditado: ");
            scanf("%d %f", &n, &val);
            for(int i = 0; i < num; i++){
                if(n == conta[i].c){
                    conta[i].s += val;
                    exC = 1;
                }
            }
            if(exC == 0){
                printf("Conta não existe, programa finalizado.");
                return 1;
            }
        }
        if(op == 2){
            int n;
            int exC = 0;
            float val;
            printf("Entre número da conta e valor a ser debitado: ");
            scanf("%d %f", &n, &val);
            for(int i = 0; i < num; i++){
                if(n == conta[i].c){
                    conta[i].s -= val;
                    exC = 1;
                }
            }
            if(exC == 0){
                printf("Conta não existe, programa finalizado.");
                return 1;
            }
        }
        if(op == 3){
            int no, nd;
            float val;
            int exCo = 0;
            int exCd = 0;
            printf("Entre o número da conta de origem, o número da conta de destino e o valor a ser transferido: ");
            scanf("%d %d %f", &no, &nd, &val);
            for(int i = 0; i < num; i++){
                if(no == conta[i].c){
                    conta[i].s -= val;
                    exCo = 1;
                }
                if(nd == conta[i].c){
                    conta[i].s += val;
                    exCo = 1;
                }
            }
            if(exCo == 0 || exCd == 0){
                printf("Conta não existe, programa finalizado.");
                return 1;
            }
        }
        if(op == 4){
            int n;
            int exC = 0;
            printf("Entre número da conta a ter saldo consultado: ");
            scanf("%d", &n);
            for(int i = 0; i < num; i++){
                if(n == conta[i].c){
                    printf("R$%.2f\n", conta[i].s);
                    exC = 1;
                }
            }
            if(exC == 0){
                printf("Conta não existe, programa finalizado.");
                return 1;
            }
        }
        if(op == 5){
            int n;
            int exC = 0;
            printf("Entre número da conta a ser removida: %d", n);
            scanf("%d", &n);
            --nEx;
            for(int i = 0; i < num;  i++){
                if(n == conta[i].c){
                    conta[i].c = nEx;
                    exC = 1;
                }
            }
            if(exC == 0){
                printf("Conta não existe, programa finalizado.");
                return 1;
            }
        }
    }
    
    //armazena as contas no arquivo e as printa
    file = fopen("banco.txt", "w");
    
    for(int i = 0; i < num; i++){
        if(conta[i].c >= 0){
            fprintf(file, "Número da conta: %d\nTipo da conta: %sSaldo da conta: R$%.2f\n\n", conta[i].c, conta[i].t, conta[i].s);
        }
    }
    
    fclose(file);
    
    printf("Contas armazenadas no arquivo banco.txt");

    return 439;
}






