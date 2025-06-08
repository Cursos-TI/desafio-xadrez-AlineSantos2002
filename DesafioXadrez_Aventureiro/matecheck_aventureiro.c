#include <stdio.h>
#include <string.h>

int main() {
    char pecas[3][10];
    char colunas[3];
    int linhas[3];

    char reiColuna;
    int reiLinha;

    // Entrada das peças
    for (int i = 0; i < 3; i++) {
        printf("Digite o nome da peca %d (Torre, Bispo ou Cavalo): ", i + 1);
        scanf("%s", pecas[i]);

        printf("Digite a posicao da peca %d (ex: D4): ", i + 1);
        scanf(" %c%d", &colunas[i], &linhas[i]);
    }

    // Entrada do rei
    printf("Digite a posicao do rei (ex: E6): ");
    scanf(" %c%d", &reiColuna, &reiLinha);

    printf("\nResultado:\n");

    int ameacou = 0;

    for (int i = 0; i < 3; i++) {
        int deltaColuna = colunas[i] - reiColuna;
        int deltaLinha = linhas[i] - reiLinha;
        int absCol = deltaColuna < 0 ? -deltaColuna : deltaColuna;
        int absLin = deltaLinha < 0 ? -deltaLinha : deltaLinha;

        if (strcmp(pecas[i], "Torre") == 0) {
            if (colunas[i] == reiColuna || linhas[i] == reiLinha) {
                printf("%s em %c%d ameaca o rei.\n", pecas[i], colunas[i], linhas[i]);
                ameacou = 1;
            }
        } else if (strcmp(pecas[i], "Bispo") == 0) {
            if (absCol == absLin) {
                printf("%s em %c%d ameaca o rei.\n", pecas[i], colunas[i], linhas[i]);
                ameacou = 1;
            }
        } else if (strcmp(pecas[i], "Cavalo") == 0) {
            if ((absCol == 2 && absLin == 1) || (absCol == 1 && absLin == 2)) {
                printf("%s em %c%d ameaca o rei.\n", pecas[i], colunas[i], linhas[i]);
                ameacou = 1;
            }
        }
    }

    if (!ameacou) {
        printf("Nenhuma peca ameaca o rei em %c%d.\n", reiColuna, reiLinha);
    }

    return 0;
}
