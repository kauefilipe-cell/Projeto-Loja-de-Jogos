//biblioteca para manipulação do arquivo txt, para ler os dados do arquivo e armazenar em uma struct, e depois exibir os dados lidos do arquivo
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

//funcão para ler os dados do arquivo e armazenar em uma struct, e depois exibir os dados lidos do arquivo
void lerArquivo() {
    struct Jogos jogo[10];

    // 1. Declarar o ponteiro para o arquivo
    FILE *arquivo;

    // 2. Abrir o arquivo no modo leitura ("r")
    arquivo = fopen("jogos.txt", "r");

    // 3. Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // 4. Ler os dados do arquivo usando fscanf
    int i = 0;
    while (fscanf(arquivo, "{\n   %[^;];%f;%d\n}\n", jogo[i].nome, &jogo[i].preco, &jogo[i].vendas) == 3) {
        i++;
    }

    // Exibir os dados lidos
    for (int j = 0; j < i; j++) {
        printf("Nome: %s\nPreço: %.2f\nVendas: %d\n\n", jogo[j].nome, jogo[j].preco, jogo[j].vendas);
    }

    // 5. Fechar o arquivo (importante!)
    fclose(arquivo);
}

void editarArquivo() {
    struct Jogos jogo[10];

    char nomeJ[30];
    float precoJ;
    int vendasJ;

    // 1. Declarar o ponteiro para o arquivo
    FILE *arquivo;

    // 2. Abrir o arquivo no modo escrita ("a") para adicionar ao final do arquivo
    arquivo = fopen("jogos.txt", "a");

    // 3. Verificar se o arquivo foi criado com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir ou criar o arquivo!\n");
        return;
    }

    // Solicitar os dados do jogo ao usuário
    printf("Digite o nome do jogo: ");
    scanf("%s", nomeJ);
    printf("Digite o preço do jogo: ");
    scanf("%f", &precoJ);
    printf("Digite a quantidade de vendas: ");
    scanf("%d", &vendasJ);

    // 4. Escrever no arquivo usando fprintf
    fprintf(arquivo, "{\n   %s;%.2f;%d\n}\n", nomeJ, precoJ, vendasJ);
    // nome_jogo;valor_unitario;quantidade

    // 5. Fechar o arquivo (importante!)
    fclose(arquivo);

    printf("Jogo adicionado com sucesso.\n");
}

//e caso n exista o arquivo, criar um novo arquivo e adicionar os dados do jogo
void criarArquivo() {
    struct Jogos jogo[10];

    char nomeJ[30];
    float precoJ;
    int vendasJ;

    // 1. Declarar o ponteiro para o arquivo
    FILE *arquivo;

    // 2. Abrir o arquivo no modo escrita ("w") para criar um novo arquivo ou sobrescrever o existente
    arquivo = fopen("jogos.txt", "w");

    // 3. Verificar se o arquivo foi criado com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }

    // Solicitar os dados do jogo ao usuário
    printf("Digite o nome do jogo: ");
    scanf("%s", nomeJ);
    printf("Digite o preço do jogo: ");
    scanf("%f", &precoJ);
    printf("Digite a quantidade de vendas: ");
    scanf("%d", &vendasJ);

    // 4. Escrever no arquivo usando fprintf
    fprintf(arquivo, "{\n   %s;%.2f;%d\n}\n", nomeJ, precoJ, vendasJ);
    // nome_jogo;valor_unitario;quantidade

    // 5. Fechar o arquivo (importante!)
    fclose(arquivo);

    printf("Jogo adicionado com sucesso.\n");
}