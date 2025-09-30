#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Cada território deverá conter um nome, a cor do exército e a quantidade de tropas
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    // Vetor de structs para armazenar os 5 territórios
    struct Territorio territorios[5];

    // Cadastro dos territórios
    printf("=== Cadastro de Territorios ===\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do territorio %d: ", i + 1);
        scanf(" %[^\n]", territorios[i].nome); // Lê string com espaços

        printf("Digite a cor do exercito: ");
        scanf(" %s", territorios[i].cor); // Lê string sem espaços

        printf("Digite o numero de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n"); // Linha em branco deixar a interface melhor
    }

    // Exibição dos dados cadastrados
    printf("\n=== Territorios Cadastrados ===\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf(" Nome: %s\n", territorios[i].nome);
        printf(" Cor do exercito: %s\n", territorios[i].cor);
        printf(" Tropas: %d\n", territorios[i].tropas);
        printf("-----------------------------\n");
    }

    return 0;
}
