#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

struct grafo {
    char letra;
    TLSE * vizinhos;
    struct grafo * prox;
}; typedef struct grafo TG;

TG * inicializa_grafo(void)
{
    return NULL;
}

char letra_existe(TG * g, char letra)
{

    if(!g)
        return 0;

    TG * t = g;

    while(t->prox && t->letra != letra )
        t = t->prox;

    if(t->letra == letra)
        return 1;
    else
        return 0;
}

TG * adiciona_letra(TG * g, char letra)
{
    if(letra_existe(g,letra))
        return g;

    TG * novo = (TG *) malloc(sizeof(TG));
    novo->letra = letra;
    novo->prox = g;
    return novo;
}

void imprime_grafo(TG * g)
{
    while(g)
    {
        if(g->letra == ' ')
            printf("_");
        else
            printf("%C",g->letra);

        imprime_lista(g->vizinhos);
        printf("\n");
        g = g->prox;
    }
}

int vizinho_existe(TLSE * l, char vizinho)
{
    if(!l)
        return 0;

    while(l && l->info != vizinho)
        l = l->prox;

    if(l)
        return 1;

    return 0;
}

TG * adiciona_vizinho(TG * g, char letra, char vizinho)
{
    if(!letra_existe(g,letra))
        g = adiciona_letra(g,letra);

    TG * t = g;

    while(t->letra != letra)
        t = t->prox;

    if(!vizinho_existe(t->vizinhos,vizinho))
        t->vizinhos = insere_final_lista(t->vizinhos,vizinho);

    return g;
}

int conta_letras(char m[])
{
    int i = 0;

    while(m[i] != '\0')
        i++;

    return i;
}

void libera_grafo(TG * g)
{
    while(g)
    {
        TG * t = g;
        g = g->prox;

        libera_lista(t->vizinhos);
        free(t);
    }
}