#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    int navio_horizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navio_vertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    int linha_h = 2, coluna_h = 4; // Navio horizontal (linha C, coluna 4)
    int linha_v = 5, coluna_v = 7; // Navio vertical (linha F, coluna 7)

    // Posiciona navio horizontal
    if (coluna_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode_colocar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != AGUA) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
            }
        } else {
            printf("Erro: Sobreposição detectada no navio horizontal.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites.\n");
        return 1;
    }

    // Posiciona navio vertical
    if (linha_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int pode_colocar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != AGUA) {
                pode_colocar = 0;
                break;
            }
        }
        if (pode_colocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
            }
        } else {
            printf("Erro: Sobreposição detectada no navio vertical.\n");
            return 1;
        }
    } else {
        printf("Erro: Navio vertical fora dos limites.\n");
        return 1;
    }

    // Exibe cabeçalho das colunas
    printf("   "); // Espaço para alinhar com as letras das linhas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Exibe o tabuleiro com letras para linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%c  ", 'A' + i); // Letra da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
