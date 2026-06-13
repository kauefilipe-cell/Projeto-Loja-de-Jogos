#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../biblioteca/arquivoTXT.h"

int main() {
    int n;

    printf("Digite o número de jogos a cadastrar: ");
    scanf("%d", &n);

    //verificar se o arquivo já existe, caso o arquivo já exista, não será criado um novo arquivo, apenas será aberto o arquivo existente
    if (fopen("jogos.txt", "r") == NULL) {
        //criarArquivo();
        criarArquivo(n);
    }

    if(n > 0){
        //chamar a função para editar o arquivo e adicionar um novo jogo ao final do arquivo
        editarArquivo(n);
    }

    //chamar a função para ler o arquivo e exibir os dados lidos do arquivo
    //lerArquivo();
}