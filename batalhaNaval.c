#include <stdio.h>


#define TAMANHODOTABULEIRO 10
#define TAMANHODONAVIO 3



void exibirTabuleiro(int tabuleiro[TAMANHODOTABULEIRO][TAMANHODOTABULEIRO]) {
    
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHODOTABULEIRO; i++) {
        for (int j = 0; j < TAMANHODOTABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}



int podePosicionarNavio(int tabuleiro[TAMANHODOTABULEIRO][TAMANHODOTABULEIRO], int linha, int coluna, char sentido) {
    for (int i = 0; i < TAMANHODONAVIO; i++) {
        int l = linha + (sentido == 'V' ? i : 0);
        int c = coluna + (sentido == 'H' ? i : 0);

        if (l >= TAMANHODOTABULEIRO || c >= TAMANHODOTABULEIRO) {
            return 0; 
        }
        if (tabuleiro[l][c] != 0) {
            return 0; 
        }
    }
    return 1;
}



void posicionarNavio(int tabuleiro[TAMANHODOTABULEIRO][TAMANHODOTABULEIRO], int linha, int coluna, char sentido) {
    for (int i = 0; i < TAMANHODONAVIO; i++) {
        int l = linha + (sentido == 'V' ? i : 0);
        int c = coluna + (sentido == 'H' ? i : 0);
        tabuleiro[l][c] = 3;
    }
}


int main() {
    int tabuleiro[TAMANHODOTABULEIRO][TAMANHODOTABULEIRO] = {0};

   
    int linhaHorizontal = 3;
    int colunaHorizontal = 3;

    
    int linhaVertical = 5;
    int colunaVertical = 7;

    if (podePosicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 'H')) {
        posicionarNavio(tabuleiro, linhaHorizontal, colunaHorizontal, 'H');
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
        return 1;
    }

    if (podePosicionarNavio(tabuleiro, linhaVertical, colunaVertical, 'V')) {
        posicionarNavio(tabuleiro, linhaVertical, colunaVertical, 'V');
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
        return 1;
    }

    exibirTabuleiro(tabuleiro);


    return 0;


}