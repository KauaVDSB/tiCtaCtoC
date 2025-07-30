#include "tabuleiro.h"
#include "terminal_utils.h"

#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];

void inicializarTabuleiro() {
    int i, j, k;  // reservado para loops
    // vez do jogador
    int jogador = 1, rodada = 1, linha, coluna;
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}


void imprimeTabuleiro(int placar1, int placar2, int rodada, int jogador) {
    clear_terminal();

    int i, j;

    printf("Placar:\n");
    printf("Jogador 1 (X): %d\n", placar1);
    printf("Jogador 2 (O): %d\n", placar2);

    printf("\nRodada %d\n", rodada);
    printf("Vez do jogador %d (%c)\n\n", jogador, (jogador == 1) ? 'X' : 'O');
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf(" %c ", tabuleiro[i][j]);
            if(j != 2){
                printf("|");
            }
        }
        if(i != 2) {
            printf("\n");
            for(j = 0; j < 11; j++){
                printf("-");
            }
            printf("\n");
        }
    }
    printf("\n");
    
    
}