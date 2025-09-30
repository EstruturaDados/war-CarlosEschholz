#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct que representa um território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função para exibir todos os territórios
void exibirTerritorios(Territorio *mapa, int qtd) {
    printf("\n=== Territorios ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d) Nome: %s | Cor: %s | Tropas: %d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("---------------------------\n");
}

// Função que simula o ataque entre dois territórios
void atacar(Territorio *atacante, Territorio *defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Nao e possivel atacar territorios da mesma cor!\n");
        return;
    }

    int dadoAtq = (rand() % 6) + 1;
    int dadoDef = (rand() % 6) + 1;

    printf("\n%s (dado: %d, tropas: %d) ataca %s (dado: %d, tropas: %d)\n",
           atacante->nome, dadoAtq, atacante->tropas,
           defensor->nome, dadoDef, defensor->tropas);

    if (dadoAtq > dadoDef) {
        printf(">> %s venceu a batalha!\n", atacante->nome);

        // transfere metade das tropas do atacante
        int tropasTransferidas = atacante->tropas / 2;
        atacante->tropas -= tropasTransferidas;

        // defensor muda de dono
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = tropasTransferidas;

    } else {
        printf(">> %s perdeu a batalha e perde 1 tropa.\n", atacante->nome);
        if (atacante->tropas > 0) {
            atacante->tropas -= 1;
        }
    }
}

// Função para liberar a memória alocada
void liberarMemoria(Territorio *mapa) {
    free(mapa);
}

int main() {
    srand(time(NULL)); // Garante aleatoriedade nos dados

    int qtd;
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &qtd);

    // Alocação dinâmica para armazenar os territórios
    Territorio *mapa = (Territorio *) calloc(qtd, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // Cadastro dos territórios
    printf("\n=== Cadastro de Territorios ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("\nTerritorio %d:\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", mapa[i].nome);

        printf("Cor do exercito: ");
        scanf(" %s", mapa[i].cor);

        printf("Numero de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }

    int opcao;
    do {
        printf("\n=== MENU ===\n");
        printf("1 - Exibir territorios\n");
        printf("2 - Atacar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            exibirTerritorios(mapa, qtd);
        } else if (opcao == 2) {
            int atq, def;
            exibirTerritorios(mapa, qtd);

            printf("Escolha o territorio atacante: ");
            scanf("%d", &atq);
            printf("Escolha o territorio defensor: ");
            scanf("%d", &def);

            if (atq < 1 || atq > qtd || def < 1 || def > qtd || atq == def) {
                printf("Escolha invalida!\n");
            } else {
                atacar(&mapa[atq - 1], &mapa[def - 1]);
            }
        }
    } while (opcao != 0);

    // Libera memória antes de encerrar o programa
    liberarMemoria(mapa);

    return 0;
}
