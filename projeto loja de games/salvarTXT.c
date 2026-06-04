
#include <stdio.h>
#include <stdlib.h>

struct Jogos{
    char nome[30];
    /*char genero[10];*/
    float preco;
    /*int classificacao;*/
    int vendas;
    /*float faturamento;*/
};

int main() {
    struct Jogos jogo[10];

    char nome[30] = "cod";
    float preco = 100.00;
    int vendas = 10;

    // 1. Declarar o ponteiro para o arquivo
    FILE *arquivo;

    // 2. Abrir o arquivo no modo escrita ("w")
    arquivo = fopen("jogos.txt", "w");

    // 3. Verificar se o arquivo foi criado com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir ou criar o arquivo!\n");
        return 1;
    }

    // 4. Escrever no arquivo usando fprintf
    fprintf(arquivo, "{\n   %s;%.2f;%d\n}\n", nome, preco, vendas);
    // nome_jogo;valor_unitario;quantidade

    // 5. Fechar o arquivo (importante!)
    fclose(arquivo);

    printf("Arquivo salvo com sucesso.\n");
}
