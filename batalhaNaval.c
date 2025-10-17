#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tab[TAM][TAM]){
    printf("\n=== TABULEIRO COM HABILIDADES ===\n\n");
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\nLegenda: 0=Água | 3=Navio | 1=Cone | 2=Cruz | 3=Octaedro\n");
}

// Função para aplicar habilidade ao tabuleiro
void aplicarHabilidade(int tab[TAM][TAM], int hab[3][5], int origemLinha, int origemColuna, int valor){
    int offsetLinha = 1;  // centro da matriz 3x5
    int offsetColuna = 2;
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            if(hab[i][j]==1){ // posição afetada
                int linha = origemLinha + (i - offsetLinha);
                int col = origemColuna + (j - offsetColuna);
                if(linha>=0 && linha<TAM && col>=0 && col<TAM){
                    if(tab[linha][col]!=NAVIO) // não sobrescreve navio
                        tab[linha][col] = valor;
                }
            }
        }
    }
}

int main(){
    int tabuleiro[TAM][TAM] = {0};

    // 1️⃣ Posicionar 4 navios
    int linhaH1=1, colunaH1=2; // horizontal
    int linhaV1=5, colunaV1=7; // vertical
    int linhaD1=0, colunaD1=0; // diagonal principal
    int linhaD2=2, colunaD2=9; // diagonal secundária

    for(int i=0;i<3;i++){
        tabuleiro[linhaH1][colunaH1+i] = NAVIO;
        tabuleiro[linhaV1+i][colunaV1] = NAVIO;
        tabuleiro[linhaD1+i][colunaD1+i] = NAVIO;
        tabuleiro[linhaD2+i][colunaD2-i] = NAVIO;
    }

    // 2️⃣ Criar matrizes de habilidade dinamicamente (0 = não afeta, 1 = afeta)
    int cone[3][5];
    int cruz[3][5];
    int octaedro[3][5];

    // Preencher cone
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            if(i==0 && j==2) cone[i][j]=1;
            else if(i==1 && (j>=1 && j<=3)) cone[i][j]=1;
            else if(i==2) cone[i][j]=1;
            else cone[i][j]=0;
        }
    }

    // Preencher cruz
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            if(i==1 || j==2) cruz[i][j]=1;
            else cruz[i][j]=0;
        }
    }

    // Preencher octaedro
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            if(i==0 && j==2) octaedro[i][j]=1;
            else if(i==1 && (j>=1 && j<=3)) octaedro[i][j]=1;
            else if(i==2 && j==2) octaedro[i][j]=1;
            else octaedro[i][j]=0;
        }
    }

    // 3️⃣ Definir pontos de origem
    int origemConeLinha=1, origemConeColuna=3;
    int origemCruzLinha=3, origemCruzColuna=2;
    int origemOctaedroLinha=0, origemOctaedroColuna=7;

    // 4️⃣ Aplicar habilidades
    aplicarHabilidade(tabuleiro, cone, origemConeLinha, origemConeColuna, 1);
    aplicarHabilidade(tabuleiro, cruz, origemCruzLinha, origemCruzColuna, 2);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaedroLinha, origemOctaedroColuna, 3);

    // 5️⃣ Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
