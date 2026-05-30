#include <stdio.h>
#include <stdlib.h>

int main(){
    int menu;
//pesquisa de jogos; cadastro de jogos; 

    do{
        printf("================Menu de Jogos===================\n");
        printf("(1) - Pesquisar jogos\n");
        printf("(2) - Cadastrar novos jogos no sistema\n");
        printf("(0) - Sair!!\n");
        printf("Digite o que vc deseja utilizar: ");
        scanf("%d", &menu);

        switch (menu){
        case 1:
            
            printf("\nPesquisar jogos funcionou\n\n");
            break;

        case 2:
            
            printf("\nCadastrar jogos funcionou\n\n");
            break;
        
        default:
            break;
        }
    }while(menu != 0);

    printf("\nVc saiu do sistema\n\n");
    
}