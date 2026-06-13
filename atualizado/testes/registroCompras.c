#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../biblioteca/arquivoTXT.h"

int main() {
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
}