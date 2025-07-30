#include <stdio.h>

#include "tabuleiro.h"
#include "game.h"

int main() {
    int linha, coluna;  // variaveis para armazenar a linha e coluna da jogada
    char jogo = 'y';  // define loop do jogo

    int partida = 0, placar1 = 0, placar2 = 0;  // variaveis para armazenar o placar dos jogadores

    while(jogo == 'y'){
        int jogador = (partida % 2 == 0) ? 1 : 2, rodada = 1, vencedor = 0;
        inicializarTabuleiro();
        do {
            imprimeTabuleiro(placar1, placar2, rodada, jogador);

            printf("\nDigite a linha e coluna que deseja fazer sua jogada.\n");
            scanf(" %d %d", &linha, &coluna);
            linha--;
            coluna--;

            if(linha >= 0 && linha <= 2 && coluna >= 0 && coluna <= 2 && tabuleiro[linha][coluna] == ' ') {
                tabuleiro[linha][coluna] = (jogador == 1) ? 'X' : 'O';
                rodada++;
                vencedor = verificaVencedor();
                if (vencedor == 0) {
                    if (rodada > 9) {
                        printf("Empate! Ninguem venceu.\n");
                        break;
                    }
                    jogador = (jogador == 1) ? 2 : 1; // troca de jogador
                    
                }

            } else {
                printf("Jogada invalida. Tente novamente.\n");

                while (getchar() != '\n');
                printf("Pressione Enter para continuar...\n");
                getchar();
            }

            
        } while (vencedor == 0 && rodada <= 9);
        
        if (vencedor != 0) {
            if (vencedor == 1 ? placar1++ : placar2++);
        } 

        imprimeTabuleiro(placar1, placar2, rodada, jogador);

        if (vencedor != 0) {
            printf("Jogador %d (%c) venceu!\n", (vencedor == 1) ? 1 : 2, (vencedor == 1) ? 'X' : 'O');
        } else {
            printf("Fim do jogo! Ninguem venceu.\n");
        }
        partida++;
        printf("Deseja jogar novamente? (y/n): ");
        scanf(" %c", &jogo);

    }
    return 0;
}