#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista * prox;
}; typedef struct lista TLSE;

TLSE * inicializa_lista(void)
{
    return NULL;
}

TLSE * insere_inicio_lista(TLSE *l, int n)
{
    TLSE * novo = (TLSE *) malloc(sizeof(TLSE));
    novo->info = n;
    novo->prox = l;
    return novo;
}

TLSE * insere_final_lista(TLSE *l, int n)
{
    if(!l)
        return insere_inicio_lista(l,n);

    TLSE * p = l;

    while(p->prox)
        p = p->prox;

    p->prox = (TLSE *) malloc(sizeof(TLSE));

    p->prox->info = n;
    p->prox->prox = NULL;

    return l;
}

TLSE * insere_ordenado_lista(TLSE *l, int n)
{
    if (!l || l->info > n)
        return insere_inicio_lista(l,n);

    TLSE * p = l, * ant = NULL; // 1 2 4

    while(p && p->info < n)
    {
        ant = p;
        p = p-> prox;
    }


    TLSE * novo = (TLSE *) malloc(sizeof(TLSE));
    novo->info = n;

    ant->prox = novo;
    novo->prox = p;

    return l;
}

TLSE * retira_elemento_lista(TLSE *l, int n)
{
    if(!l)
        return NULL;

    TLSE * p = l, * ant = NULL;
    while(p && p->info != n)
    {
        ant = p;
        p = p->prox;
    }

    if(!p)
        return l;

    if(!ant)
        return l->prox;
    else ant->prox = p->prox;

    free(p);

    return l;
}

void imprime_lista(TLSE *l)
{
    if(l) {
        TLSE * p = l;

        printf("[");

        while(p)
        {
            if(p->info == ' ')
                printf(" _ ");
            else
                printf(" %c ",p->info);
            p = p->prox;
        }

        printf("]");
    } else
        printf("[ ]");

}

void libera_lista(TLSE *l)
{
    TLSE * p = l, * t;
    while (p)
    {
        t = p;
        p = p->prox;
        free(t);
    }
}
