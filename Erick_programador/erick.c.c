#include <stdio.h>
int main(void) {

 
    int n;
        printf("Numero? ");
        scanf("%d",&n);
        printf("Operacao: ");

        switch( n ) {

             case 1: printf("saldo\n"); break;
             case 2: printf("extrato\n"); break;
             case 3: printf("saque\n"); break;
             case 4: printf("sair\n"); break;

         default: printf("invalido\n");
 }
 return 0;
}