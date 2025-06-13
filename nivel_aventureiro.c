#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAMANHO_NAVIO 3

// Função para verificar se a posição está dentro do tabuleiro
int posicao_valida(int linha, int coluna) {
    return linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM;
}

// Função para verificar se o espaço está livre para o navio (sem sobreposição)
int espaco_livre(int tabuleiro[10][10], int linha, int coluna, int d_linha, int d_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i * d_linha;
        int c = coluna + i * d_coluna;
        if (!posicao_valida(l, c) || tabuleiro[l][c] != AGUA) {
            return 0; // Posição inválida ou ocupada
        }
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionar_navio(int tabuleiro[10][10], int linha, int coluna, int d_linha, int d_coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i * d_linha][coluna + i * d_coluna] = NAVIO;
    }
}

// Função para imprimir o tabuleiro
void imprimir_tabuleiro(int tabuleiro[10][10]) {
    printf("   ");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[10][10] = {0}; // Inicializa tudo com água (0)

    // Exemplo de posicionamento: horizontal (d_linha=0, d_coluna=1)
    if (espaco_livre(tabuleiro, 0, 0, 0, 1)) {
        posicionar_navio(tabuleiro, 0, 0, 0, 1);
    }

    // vertical (d_linha=1, d_coluna=0)
    if (espaco_livre(tabuleiro, 2, 5, 1, 0)) {
        posicionar_navio(tabuleiro, 2, 5, 1, 0);
    }

    // diagonal principal (d_linha=1, d_coluna=1)
    if (espaco_livre(tabuleiro, 4, 4, 1, 1)) {
        posicionar_navio(tabuleiro, 4, 4, 1, 1);
    }

    // diagonal secundária (d_linha=1, d_coluna=-1)
    if (espaco_livre(tabuleiro, 1, 8, 1, -1)) {
        posicionar_navio(tabuleiro, 1, 8, 1, -1);
    }

    // Exibe o tabuleiro
    imprimir_tabuleiro(tabuleiro);

    return 0;
}
