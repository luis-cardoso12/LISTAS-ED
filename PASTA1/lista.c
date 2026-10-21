#include <stdlib.h>
#include "lista.h"

void initL(Linear *L) {
    L->n = 0;
}

int appendL(Linear *L, Ferramenta f) {
    if (L->n == MAX) return 0;
    L->dados[L->n++] = f;
    return 1;
}

int insertL(Linear *L, int p, Ferramenta f) {
    if (L->n == MAX || p < 0 || p > L->n) return 0;

    for (int i = L->n; i > p; i--)
        L->dados[i] = L->dados[i - 1];

    L->dados[p] = f;
    L->n++;
    return 1;
}

int popL(Linear *L, int p, Ferramenta *f) {
    if (p < 0 || p >= L->n) return 0;

    *f = L->dados[p];

    for (int i = p; i < L->n - 1; i++)
        L->dados[i] = L->dados[i + 1];

    L->n--;
    return 1;
}

int removeL(Linear *L, int codigo) {
    for (int i = 0; i < L->n; i++)
        if (L->dados[i].codigo == codigo) {
            Ferramenta f;
            return popL(L, i, &f);
        }
    return 0;
}

void initD(Dinamica *L) {
    L->inicio = NULL;
    L->n = 0;
}

int appendD(Dinamica *L, Ferramenta f) {
    return insertD(L, L->n, f);
}

int insertD(Dinamica *L, int p, Ferramenta f) {
    if (p < 0 || p > L->n) return 0;

    No *novo = malloc(sizeof(No));
    if (!novo) return 0;

    novo->dado = f;

    if (p == 0) {
        novo->prox = L->inicio;
        L->inicio = novo;
    } else {
        No *a = L->inicio;

        for (int i = 0; i < p - 1; i++)
            a = a->prox;

        novo->prox = a->prox;
        a->prox = novo;
    }

    L->n++;
    return 1;
}

int popD(Dinamica *L, int p, Ferramenta *f) {
    if (p < 0 || p >= L->n) return 0;

    No *a = L->inicio;

    if (p == 0) {
        L->inicio = a->prox;
    } else {
        for (int i = 0; i < p - 1; i++)
            a = a->prox;

        No *rem = a->prox;
        a->prox = rem->prox;
        a = rem;
    }

    *f = a->dado;
    free(a);
    L->n--;
    return 1;
}

int removeD(Dinamica *L, int codigo) {
    No *a = L->inicio;
    int p = 0;

    while (a) {
        if (a->dado.codigo == codigo) {
            Ferramenta f;
            return popD(L, p, &f);
        }
        a = a->prox;
        p++;
    }
    return 0;
}

void limparD(Dinamica *L) {
    Ferramenta f;

    while (L->n > 0)
        popD(L, 0, &f);
}
