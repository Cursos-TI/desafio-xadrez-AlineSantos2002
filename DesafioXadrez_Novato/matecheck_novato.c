#include <stdio.h>

int main() {
    // Declaração das variáveis
    char peca[10];
    char posicaoPecaColuna, posicaoReiColuna;
    int posicaoPecaLinha, posicaoReiLinha;

    // Entrada de dados
    printf("Digite a peca (Torre ou Bispo): ");
    scanf("%s", peca);

    printf("Digite a posicao da peca (ex: D4): ");
    scanf(" %c%d", &posicaoPecaColuna, &posicaoPecaLinha);

    printf("Digite a posicao do rei (ex: E6): ");
    scanf(" %c%d", &posicaoReiColuna, &posicaoReiLinha);

    // Cálculos auxiliares
    int mesmaColuna = (posicaoPecaColuna == posicaoReiColuna);
    int mesmaLinha = (posicaoPecaLinha == posicaoReiLinha);
    int mesmaDiagonal = ((posicaoPecaColuna - posicaoReiColuna == posicaoPecaLinha - posicaoReiLinha) ||
                         (posicaoPecaColuna - posicaoReiColuna == -(posicaoPecaLinha - posicaoReiLinha)));

    // Verificação lógica sem if/else
    int ameacaTorre = (peca[0] == 'T') * (mesmaColuna || mesmaLinha);
    int ameacaBispo = (peca[0] == 'B') * mesmaDiagonal;

    int ameacaRei = ameacaTorre || ameacaBispo;

    // Saída
    printf("\nResultado:\n");
    printf("A peca %s em %c%d ", peca, posicaoPecaColuna, posicaoPecaLinha);
    printf("%s o rei em %c%d.\n", ameacaRei ? "AMEACA" : "NAO AMEACA", posicaoReiColuna, posicaoReiLinha);

    return 0;
}
