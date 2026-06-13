//biblioteca para manipulação do arquivo txt, para ler os dados do arquivo e armazenar em uma struct, e depois exibir os dados lidos do arquivo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jogos{
    char nome[30];
    char genero[10];
    float preco;
    int classificacao;
    int vendas;
    float faturamento;
};

//funcão para ler os dados do arquivo e armazenar em uma struct, e depois exibir os dados lidos do arquivo
void lerArquivo() {
    struct Jogos jogo[255];

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
    int i = 0, totalJogos = 0;
    while (fscanf(arquivo, "{\n   %[^;];%[^;];%f;%d;%d;%f\n}\n", jogo[i].nome, jogo[i].genero, &jogo[i].preco, &jogo[i].classificacao, &jogo[i].vendas, &jogo[i].faturamento) == 6){
        totalJogos++;
        i++;
    }

    // Exibir os dados lidos
    for (int j = 0; j < i; j++) {
        printf("Nome: %s\nGênero: %s\nPreço: %.2f\nClassificação: %d\nVendas: %d\nFaturamento: %.2f\n\n", jogo[j].nome, jogo[j].genero, jogo[j].preco, jogo[j].classificacao, jogo[j].vendas, jogo[j].faturamento);
    }

    // 5. Fechar o arquivo (importante!)
    fclose(arquivo);
}

void editarArquivo(int n) {
    struct Jogos jogo[255];

    // 1. Declarar o ponteiro para o arquivo
    FILE *arquivo;

    // 2. Abrir o arquivo no modo escrita ("a") para adicionar ao final do arquivo
    arquivo = fopen("jogos.txt", "a");

    // 3. Verificar se o arquivo foi criado com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir ou criar o arquivo!\n");
        return;
    }

    for (int i = 0; i < n; i++){
        printf("Digite o nome do jogo: ");
        scanf("%s", jogo[i].nome);

        printf("Digite o gênero do jogo: ");
        scanf("%s", jogo[i].genero);

        printf("Digite o preço do jogo: ");
        scanf("%f", &jogo[i].preco);

        printf("Digite a classificação do jogo: ");
        scanf("%d", &jogo[i].classificacao);

        printf("Digite as vendas do jogo: ");
        scanf("%d", &jogo[i].vendas);

        float faturamentoBruto = (jogo[0].vendas*jogo[0].preco);
        float imposto = (faturamentoBruto*0.2);
        jogo[i].faturamento = faturamentoBruto-imposto;

        // 4. Escrever no arquivo usando fprintf
        fprintf(arquivo, "{\n   %s;%s;%.2f;%d;%d;%.2f\n}\n", jogo[i].nome, jogo[i].genero, jogo[i].preco, jogo[i].classificacao, jogo[i].vendas, jogo[i].faturamento);
        // nome_jogo;genero;valor_unitario;classificaçao indicativa;quantidade;faturamento total
    }

    // 5. Fechar o arquivo (importante!)
    fclose(arquivo);

    printf("Jogo adicionado com sucesso.\n");
}

//e caso n exista o arquivo, criar um novo arquivo e adicionar os dados do jogo
void criarArquivo(int n) {
    struct Jogos jogo[255];

    // 1. Declarar o ponteiro para o arquivo
    FILE *arquivo;

    // 2. Abrir o arquivo no modo escrita ("w") para criar um novo arquivo ou sobrescrever o existente
    arquivo = fopen("jogos.txt", "w");

    // 3. Verificar se o arquivo foi criado com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }

    for (int i = 0; i < n; i++){
        printf("Digite o nome do jogo: ");
        scanf("%s", jogo[i].nome);

        printf("Digite o gênero do jogo: ");
        scanf("%s", jogo[i].genero);

        printf("Digite o preço do jogo: ");
        scanf("%f", &jogo[i].preco);

        printf("Digite a classificação do jogo: ");
        scanf("%d", &jogo[i].classificacao);

        printf("Digite as vendas do jogo: ");
        scanf("%d", &jogo[i].vendas);

        float faturamentoBruto = (jogo[0].vendas*jogo[0].preco);
        float imposto = (faturamentoBruto*0.2);
        jogo[i].faturamento = faturamentoBruto-imposto;

        // 4. Escrever no arquivo usando fprintf
        fprintf(arquivo, "{\n   %s;%s;%.2f;%d;%d;%.2f\n}\n", jogo[i].nome, jogo[i].genero, jogo[i].preco, jogo[i].classificacao, jogo[i].vendas, jogo[i].faturamento);
        // nome_jogo;genero;valor_unitario;classificaçao indicativa;quantidade;faturamento total
    }
    
    // 5. Fechar o arquivo (importante!)
    fclose(arquivo);

    printf("Jogo adicionado com sucesso.\n");
}

//função para atualizar as vendas do jogo, onde o cliente pode escolher o jogo que deseja comprar e a quantidade de jogos que deseja comprar, e depois atualizar as vendas do jogo no arquivo
void atualizarVendas(char nomeJogo[30], int quantidade) {
    struct Jogos jogo[255];
    
    // 1. Declarar o ponteiro para o arquivo
    FILE *arquivo;
    int totalJogos = 0;

    // 2. Abrir o arquivo no modo leitura ("r")
    arquivo = fopen("jogos.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // 3. Ler todos os jogos do arquivo
    while (fscanf(arquivo, "{\n   %[^;];%[^;];%f;%d;%d;%f\n}\n", 
           jogo[totalJogos].nome, 
           jogo[totalJogos].genero, 
           &jogo[totalJogos].preco, 
           &jogo[totalJogos].classificacao, 
           &jogo[totalJogos].vendas, 
           &jogo[totalJogos].faturamento) == 6) {
        totalJogos++;
    }

    // 4. Buscar e atualizar o jogo na memória
    int encontrado = -1;
    for (int i = 0; i < totalJogos; i++) {
        if (strcmp(jogo[i].nome, nomeJogo) == 0) {
            jogo[i].vendas += quantidade;
            jogo[i].faturamento += (quantidade * jogo[i].preco);
            encontrado = i;
            printf("Venda atualizada: %s\n", jogo[i].nome);
            break;
        }
    }

    // 5. Se não encontrou, mostrar erro
    if (encontrado == -1) {
        printf("Jogo não encontrado!\n");
        return;
    }

    // 6. Abrir o arquivo para ESCRITA (sobrescrever)
    arquivo = fopen("jogos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao escribir no arquivo!\n");
        return;
    }

    // 7. Escrever todos os jogos de volta no arquivo
    for (int i = 0; i < totalJogos; i++) {
        fprintf(arquivo, "{\n   %s;%s;%.2f;%d;%d;%.2f\n}\n",
                jogo[i].nome,
                jogo[i].genero,
                jogo[i].preco,
                jogo[i].classificacao,
                jogo[i].vendas,
                jogo[i].faturamento);
    }

    fclose(arquivo);
}

//função para buscar um jogo no arquivo, onde o cliente pode escolher o jogo que deseja comprar e a quantidade de jogos que deseja comprar, e depois atualizar as vendas do jogo no arquivo
void buscarJogo(char nomeJogo[30]) {
    struct Jogos jogo[255];
    // 1. Declarar o ponteiro para o arquivo
    FILE *arquivo;

    // 2. Abrir o arquivo no modo leitura ("r")
    arquivo = fopen("jogos.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // 3. Ler todos os dados do arquivo usando fscanf
    int totalJogos = 0, i = 0;
    while (fscanf(arquivo, "{\n   %[^;];%[^;];%f;%d;%d;%f\n}\n", jogo[i].nome, jogo[i].genero, &jogo[i].preco, &jogo[i].classificacao, &jogo[i].vendas, &jogo[i].faturamento) == 6) {
        if (strcmp(jogo[i].nome, nomeJogo) == 0) {
            printf("Nome: %s\nGênero: %s\nPreço: %.2f\nClassificação: %d\nVendas: %d\nFaturamento: %.2f\n\n", jogo[i].nome, jogo[i].genero, jogo[i].preco, jogo[i].classificacao, jogo[i].vendas, jogo[i].faturamento); 
        }
        i++;
        totalJogos++;
    }

    // 4. Se não encontrou, mostrar erro
    if (i == 10) {
        printf("Jogo não encontrado!\n");
    }
    // 5. Fechar o arquivo (importante!)
    fclose(arquivo);
}