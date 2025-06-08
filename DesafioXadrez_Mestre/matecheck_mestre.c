#include <stdio.h>
#include <string.h>

#define MAX_PECAS 10

// Função para verificar se uma peça ameaça o rei
int ameacaRei(char peca[], char pColuna, int pLinha, char rColuna, int rLinha) {
    int deltaC = pColuna - rColuna;
    int deltaL = pLinha - rLinha;
    int absC = deltaC < 0 ? -deltaC : deltaC;
    int absL = deltaL < 0 ? -deltaL : deltaL;

    if (strcmp(peca, "Torre") == 0)
        return (pColuna == rColuna || pLinha == rLinha);

    if (strcmp(peca, "Bispo") == 0)
        return (absC == absL);

    if (strcmp(peca, "Cavalo") == 0)
        return ((absC == 2 && absL == 1) || (absC == 1 && absL == 2));

    return 0;
}

// Função principal
int main() {
    char pecas[MAX_PECAS][10];
    char colunas[MAX_PECAS];
    int linhas[MAX_PECAS];
    int total = 0;

    char reiColuna;
    int reiLinha;

    // Entrada das peças
    while (total < MAX_PECAS) {
        printf("Digite o nome da peca %d (ou 'fim' para encerrar): ", total + 1);
        scanf("%s", pecas[total]);

        if (strcmp(pecas[total], "fim") == 0)
            break;

        printf("Digite a posicao da peca %d (ex: D4): ", total + 1);
        scanf(" %c%d", &colunas[total], &linhas[total]);
        total++;
    }

    // Entrada da posição do rei
    printf("Digite a posicao do rei (ex: E6): ");
    scanf(" %c%d", &reiColuna, &reiLinha);

    // Verificação das ameaças
    int ameacou = 0;
    printf("\nResultado:\n");
    for (int i = 0; i < total; i++) {
        if (ameacaRei(pecas[i], colunas[i], linhas[i], reiColuna, reiLinha)) {
            printf("%s em %c%d ameaca o rei.\n", pecas[i], colunas[i], linhas[i]);
            ameacou = 1;
        }
    }

    if (!ameacou)
        printf("Nenhuma peca ameaca o rei em %c%d.\n", reiColuna, reiLinha);

    return 0;
}
