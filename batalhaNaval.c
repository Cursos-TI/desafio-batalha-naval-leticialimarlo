#include <stdio.h>

#define TAM 10   // Tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3  // Cada navio ocupa 3 posições
#define AGUA 0       // Representa água
#define NAVIO 3      // Representa parte do navio

int main() {
    // Declaração e inicialização do tabuleiro (matriz 10x10)
    int tabuleiro[TAM][TAM] = {0};

    // Declaração dos dois navios (vetores unidimensionais)
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Definição das coordenadas iniciais dos navios
    // Obs: As coordenadas começam em 0, então linha 2 = terceira linha
    int linhaHorizontal = 2;  // Linha onde o navio horizontal será colocado
    int colunaHorizontal = 1; // Coluna inicial do navio horizontal

    int linhaVertical = 5;    // Linha inicial do navio vertical
    int colunaVertical = 7;   // Coluna onde o navio vertical será colocado

    // Validação dos limites do tabuleiro
    if (colunaHorizontal + TAM_NAVIO > TAM || linhaVertical + TAM_NAVIO > TAM) {
        printf("Erro: As coordenadas ultrapassam os limites do tabuleiro.\n");
        return 1;
    }

    // Verifica se há sobreposição (posição igual nos dois navios)
    int sobreposicao = 0;
    for (int i = 0; i < TAM_NAVIO; i++) {
        for (int j = 0; j < TAM_NAVIO; j++) {
            if ((linhaHorizontal == linhaVertical + i) &&
                (colunaHorizontal + j == colunaVertical)) {
                sobreposicao = 1;
            }
        }
    }

    if (sobreposicao) {
        printf("Erro: Os navios se sobrepõem!\n");
        return 1;
    }

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }

    // Exibição do tabuleiro no console
    printf("\n======= TABULEIRO BATALHA NAVAL =======\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");
    printf("=======================================\n");

    return 0;
}
