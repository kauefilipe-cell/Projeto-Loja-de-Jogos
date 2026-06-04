#include <stdio.h>
#include <stdlib.h>

struct Jogos{
    char nome[30];
    char genero[10];
    float preco;
    int classificacao;
    int vendas;
    float faturamento;
};

int main(){
    struct Jogos jogo[10];

    strcpy(jogo[0].nome, "cod");
    strcpy(jogo[0].genero, "FPS");
    jogo[0].preco = 100.00;
    jogo[0].classificacao = 18;
    jogo[0].vendas = 0;
    jogo[0].faturamento = 0;

    int compra;
    scanf("%d", &compra);

    jogo[0].vendas += compra;
    float faturamentoBruto = (jogo[0].vendas*jogo[0].preco);
    float imposto = (faturamentoBruto*0.2);
    jogo[0].faturamento = faturamentoBruto-imposto;

    printf("Vendas: %d Bruto: %.2f Imposto: %.2f Faturamento: %.2f", jogo[0].vendas, faturamentoBruto, imposto, jogo[0].faturamento);
}