#include <stdio.h>
#include <stdlib.h>

struct Jogos{
    char nome[30];
    /*char genero[10];
    float preco;
    int classificacao;*/
    int vendas;
    float faturamento;
};

int main(){
    struct Jogos p1[10];

    printf("Digite o nome do jogo: ");
    scanf("%29s", p1[1].nome);
    printf("Digite as vendas: ");
    scanf("%d", &p1[1].vendas);

    printf("Digite o nome do jogo: ");
    scanf("%29s", p1[2].nome);
    printf("Digite as vendas: ");
    scanf("%d", &p1[2].vendas);

    printf("Nome: %s\nVendas: %d\n\n", p1[1].nome, p1[1].vendas);
     printf("Nome: %s\nVendas: %d\n\n", p1[2].nome, p1[2].vendas);
}