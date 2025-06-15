#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_TABULEIRO 10
#define TAMANHO_LINHA 3
#define TAMANHO_COLUNA 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro com habilidades especiais:\n");

    /*
        Identificação no tabuleiro:
            Cone (1)
            Octaedro (2)
            Cruz (3)
    */

    printf("  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para construir habilidade Cone (1 = afetado, 0 = não afetado)
void construirCone(int matriz[TAMANHO_LINHA][TAMANHO_COLUNA]) {
    for (int i = 0; i < TAMANHO_LINHA; i++) {
        for (int j = 0; j < TAMANHO_COLUNA; j++) {
            // centro do cone na coluna central
            int centro = TAMANHO_COLUNA / 2;
            
            if (j >= centro - i && j <= centro + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para construir Cruz
void construirCruz(int matriz[TAMANHO_LINHA][TAMANHO_COLUNA]) {
    for (int i = 0; i < TAMANHO_LINHA; i++) {
        for (int j = 0; j < TAMANHO_COLUNA; j++) {
            if (i == TAMANHO_LINHA / 2 || j == TAMANHO_COLUNA / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para construir Octaedro (losango)
void construirOctaedro(int matriz[TAMANHO_LINHA][TAMANHO_COLUNA]) {
    for (int i = 0; i < TAMANHO_LINHA; i++) {
        for (int j = 0; j < TAMANHO_COLUNA; j++) {
            // Distância do centro da matriz (1,2)
            if (abs(i - 1) + abs(j - 2) <= 1)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para aplicar a matriz de habilidade no tabuleiro
void aplicarHabilidadeNoTabuleiro(
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
    int matriz[TAMANHO_LINHA][TAMANHO_COLUNA],
    int origem_linha,
    int origem_coluna,
    int numero_habilidade
) {
    for (int i = 0; i < TAMANHO_LINHA; i++) {
        for (int j = 0; j < TAMANHO_COLUNA; j++) {
            if (matriz[i][j] == 1) {
                int linha = origem_linha - TAMANHO_LINHA / 2 + i;
                int coluna = origem_coluna - TAMANHO_COLUNA / 2 + j;

                if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
                    if (tabuleiro[linha][coluna] == 0)
                        tabuleiro[linha][coluna] = numero_habilidade;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int habilidade[TAMANHO_LINHA][TAMANHO_COLUNA];

    inicializarTabuleiro(tabuleiro);

    // Habilidade: Cone
    construirCone(habilidade);
    aplicarHabilidadeNoTabuleiro(tabuleiro, habilidade, 5, 5, 1);

    // Habilidade: Cruz
    construirCruz(habilidade);
    aplicarHabilidadeNoTabuleiro(tabuleiro, habilidade, 2, 2, 3);

    // Habilidade: Octaedro
    construirOctaedro(habilidade);
    aplicarHabilidadeNoTabuleiro(tabuleiro, habilidade, 8, 8, 2);

    imprimirTabuleiro(tabuleiro);

    return 0;
}
