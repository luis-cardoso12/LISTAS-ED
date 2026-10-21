#include <stdio.h>
#include "lista.h"

void salvarL(Linear *L) {
    FILE *arq = fopen("linear.bin", "wb");
    if (!arq) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    fwrite(&L->n, sizeof(int), 1, arq);
    fwrite(L->dados, sizeof(Ferramenta), L->n, arq);
    fclose(arq);
    printf("Lista linear salva.\n");
}

void carregarL(Linear *L) {
    FILE *arq = fopen("linear.bin", "rb");
    if (!arq) {
        printf("Arquivo nao encontrado.\n");
        return;
    }

    int n;
    if (fread(&n, sizeof(int), 1, arq) != 1 ||
        n < 0 || n > MAX) {
        printf("Arquivo invalido.\n");
        fclose(arq);
        return;
    }

    Ferramenta temp[MAX];

    if (fread(temp, sizeof(Ferramenta), n, arq) != (size_t)n) {
        printf("Erro na leitura.\n");
        fclose(arq);
        return;
    }

    fclose(arq);

    for (int i = 0; i < n; i++)
        L->dados[i] = temp[i];

    L->n = n;
    printf("Lista linear carregada.\n");
}

void salvarD(Dinamica *L) {
    FILE *arq = fopen("dinamica.bin", "wb");
    if (!arq) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    fwrite(&L->n, sizeof(int), 1, arq);

    for (No *a = L->inicio; a; a = a->prox)
        fwrite(&a->dado, sizeof(Ferramenta), 1, arq);

    fclose(arq);
    printf("Lista dinamica salva.\n");
}

void carregarD(Dinamica *L) {
    FILE *arq = fopen("dinamica.bin", "rb");
    if (!arq) {
        printf("Arquivo nao encontrado.\n");
        return;
    }

    int n;
    if (fread(&n, sizeof(int), 1, arq) != 1 ||
        n < 0 || n > 100000) {
        printf("Arquivo invalido.\n");
        fclose(arq);
        return;
    }

    Dinamica temp;
    initD(&temp);
    int ok = 1;

    for (int i = 0; i < n; i++) {
        Ferramenta f;

        if (fread(&f, sizeof(Ferramenta), 1, arq) != 1 ||
            !appendD(&temp, f)) {
            ok = 0;
            break;
        }
    }

    fclose(arq);

    if (!ok) {
        limparD(&temp);
        printf("Erro na leitura.\n");
        return;
    }

    limparD(L);
    *L = temp;
    printf("Lista dinamica carregada.\n");
}
