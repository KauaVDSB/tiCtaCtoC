#include "game.h"
#include "tabuleiro.h"


int verificaVencedor() {
    // Verifica linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return (tabuleiro[i][0] == 'X') ? 1 : 2;
        }
    }

    // Verifica colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j] && tabuleiro[0][j] != ' ') {
            return (tabuleiro[0][j] == 'X') ? 1 : 2;
        }
    }

    // Verifica diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
        return (tabuleiro[0][0] == 'X') ? 1 : 2;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return (tabuleiro[0][2] == 'X') ? 1 : 2;
    }

    return 0; // Nenhum vencedor
}

