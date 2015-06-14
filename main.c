#include <stdio.h>
#include <stdlib.h>

#include "grafo.c"


int main(int argc, char *argv[]) {

    TG * testeGrafo = (TG *) malloc(sizeof(TG));
    testeGrafo = inicializa_grafo();

    char mensagem[256];

    printf("Entre com a mensagem: ");
    scanf("%[^\n]", &mensagem);

    printf("Mensagem original: %s\n", mensagem);
    printf("Tamanho da mensagem: %d caracteres\n", conta_letras(mensagem));

    int i, numero_letras = conta_letras(mensagem);

    for(i = 1; i < numero_letras; i++)
    {
       testeGrafo = adiciona_vizinho(testeGrafo,mensagem[i-1],mensagem[i]);
    }

    imprime_grafo(testeGrafo);

    libera_grafo(testeGrafo);

    testeGrafo = inicializa_grafo();
    free(testeGrafo);

    return 0;

}