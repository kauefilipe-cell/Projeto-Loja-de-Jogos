//menu da loja de jogos, onde o cliente pode escolher entre pesquisar os jogos ou cadastrar novos jogos no sistema, comprar jogos ou sair do sistema.
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca/arquivoTXT.h"

int main(){
    int menu;
    //Pesquisa de jogos; cadastro de jogos; compra de jogos;

    do{
        printf("================Menu de Jogos===================\n");
        printf("(1) - Pesquisar jogos\n");
        printf("(2) - Cadastrar novos jogos no sistema\n");
        printf("(3) - Registrar venda de jogos\n");
        printf("(4) - Gerar relatórios\n");
        printf("(0) - Sair!!\n");
        printf("Digite o que vc deseja utilizar: ");
        scanf("%d", &menu);

        switch (menu){
        case 1:
            
            printf("\nPesquisar jogos funcionou\n\n");
            break;

        case 2:
            
            int n;

            printf("Digite o número de jogos a cadastrar: ");
            scanf("%d", &n);

            //verificar se o arquivo já existe, caso o arquivo já exista, não será criado um novo arquivo, apenas será aberto o arquivo existente
            if (n > 0 && fopen("jogos.txt", "r") == NULL) {
                //criarArquivo();
                criarArquivo(n);
            }

            if(n > 0){
                //chamar a função para editar o arquivo e adicionar um novo jogo ao final do arquivo
                editarArquivo(n);
            }
        
            break;
        
        case 3:
            
            char nomeJogo[30];
            int quantidade;

            printf("Digite o nome do jogo que deseja comprar: ");
            scanf("%s", nomeJogo);

            printf("Digite a quantidade de jogos que deseja comprar: ");
            scanf("%d", &quantidade);

            //chamar a função para atualizar as vendas do jogo escolhido, caso o jogo escolhido não exista, exibir uma mensagem de erro
            atualizarVendas(nomeJogo, quantidade);

            //chamar a função para ler o arquivo e exibir os dados lidos do arquivo
            lerArquivo();
            break;

        case 4:
            
            
            printf("Gerar relatório!");
            break;

        default:
            break;
        }
    }while(menu != 0);

    printf("\nVc saiu do sistema\n\n");
}
