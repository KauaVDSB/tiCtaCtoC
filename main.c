#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k;  // reservado para loops
    char jogo = 'y';  // define loop do jogo
    char tabuleiro[3][3];
    // vez do jogador
    int jogador = 1, rodada = 1, linha, coluna;
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            tabuleiro[i][j] = (i+j+1);
        }
    }

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
                printf("—");
            }
            printf("\n");
        }
    }
    printf("\n");

    while(jogo == 'y'){
        printf("Rodada %d\n", rodada);
        printf("Vez do jogador %c\n", jogador);

        printf("Digite a linha e coluna que deseja fazer sua jogada.\n");
        scanf(" %d %d", &linha, &coluna);

        tabulei
        break;
    }
    return 0;
}