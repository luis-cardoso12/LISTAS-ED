#ifndef LISTA_H
#define LISTA_H

#include "ferramenta.h"

#define MAX 1000

typedef struct {
    Ferramenta dados[MAX];
    int n;
} Linear;

typedef struct No {
    Ferramenta dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    int n;
} Dinamica;

void initL(Linear *L);
int appendL(Linear *L, Ferramenta f);
int insertL(Linear *L, int p, Ferramenta f);
int popL(Linear *L, int p, Ferramenta *f);
int removeL(Linear *L, int codigo);

void initD(Dinamica *L);
int appendD(Dinamica *L, Ferramenta f);
int insertD(Dinamica *L, int p, Ferramenta f);
int popD(Dinamica *L, int p, Ferramenta *f);
int removeD(Dinamica *L, int codigo);
void limparD(Dinamica *L);

void salvarL(Linear *L);
void carregarL(Linear *L);
void salvarD(Dinamica *L);
void carregarD(Dinamica *L);

#endif
