
#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int opcao;
    float saldo = 1000.00;
    float emprestimo = 0.00;
    float valor;
    
    do{
        printf("\nBem Vindo\n");
        printf("1- Verificar saldo\n");
        printf("2- Depositar valor\n");
        printf("3- Sacar valor\n");
        printf("4- Pedir empréstimo\n");
        printf("5- Pagar empréstimo\n");
        printf("6- Consultar empréstimo\n");
        printf("7- Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("\n Seu saldo atual é de R$ %.2F\n", saldo);
            break;
            
            case 2:
                printf("Digite o valor para deposito\n");
                scanf("%f", &valor);
                if(valor > 0){
                    saldo += valor;
                    printf("Depósito de R$ %.2f foi realizado com sucesso\n", valor);
                } else{
                    printf("Valor inválido para deposito\n");
                }
                break;
                
            case 3:
                printf("Digite o valor que você deseja sacar:\n");
                scanf("%f", &valor);
                if(valor > 0 && valor <= saldo){
                    saldo -= valor;
                    printf("O valor de R$ %2.f foi sacado com sucesso\n", valor); 
                } else if(valor > saldo){
                    printf("Saldo insuficiente\n");
                } else{
                    printf("valor inválido\n");
                }
            break;
            
            case 4:
                printf("Digite o valor do empréstimo que deseja soliciatar:\n");
                scanf("%f", &valor);
                if(valor > 0){
                    saldo += valor;
                    emprestimo += valor;
                    printf("O empréstimo de R$ %2.f foi adicionado a sua conta\n", valor);
                } else{
                    printf("Valor de empréstimo inválido\n");
                }
            break;
            
            case 5:
                if(emprestimo == 0){
                    printf("Você não possui dividas de empréstimo para pagar\n");
                } else{
                    printf("Sua divida é de R$ %2.f\n", emprestimo);
                    printf("Digite o valor da divida em que deseja pagar:\n");
                    scanf("%f", &valor);
                }
                
                
                if(valor > 0 && valor <= saldo && valor <= emprestimo){
                    saldo -= valor;
                    emprestimo -= valor;
                    printf("Pagamento de R$ %2.f realizado com sucesso\n", valor);
                } else if( valor > saldo){
                    printf("Saldo insuficiente para realizar o pagamento da divida\n");
                    
                } else if(valor>emprestimo){
                    printf("Valor é maior  que a divida\n");
                    
                } else{
                    printf("Valor inválido\n");
                }
            break;
            
            case 6: 
                printf("O valor de empréstimo solicitado é de R$ %2.f", emprestimo);
            break;
            
            case 7:
                printf("\nObrigado por utilizar o nosso sistema, ate breve\n");
            break;
                
            default:
                printf("\nOpção inválida, tente novamente\n");
            
        }
        
    } while(opcao !=7);
    

    return 0;
}
