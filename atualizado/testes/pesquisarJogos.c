//pesquisar jogo em especifico, caso o jogo exista, exibir os dados do jogo, caso o jogo n exista, exibir uma mensagem de erro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../biblioteca/arquivoTXT.h"

int main() {
    char nomeJogo[30];

    printf("Digite o nome do jogo que deseja pesquisar: ");
    scanf("%s", nomeJogo);

    //chamar a função para buscar o jogo escolhido, caso o jogo escolhido não exista, exibir uma mensagem de erro
    buscarJogo(nomeJogo);

    return 0;
}