#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXNUMVERTICES 100

typedef int tpeso;
typedef int tvertice;
typedef int tapontador;

typedef struct grafo {
  tpeso mat[MAXNUMVERTICES][MAXNUMVERTICES];
  int num_vertices;
} tgrafo;

void inicializa_grafo(tgrafo *grafo, int num_vertices)  {
    int i, j;

    grafo->num_vertices = num_vertices;
    for(i = 0;i < grafo->num_vertices; i++){
        for(j = 0;i < grafo->num_vertices; j++){
            grafo->mat[i][j] = 0;
        }
    }
}

void insere_vertice() {

}

void remove_vertice() {

}

void insere_aresta(tvertice v, tvertice u, tpeso peso, tgrafo *grafo) {
    grafo->mat[v][u] = peso;
}

void remove_aresta(tvertice v, tvertice u, tgrafo *grafo) {
    if(grafo->mat[v][u] == 0){
        printf("Aresta inexistente");
    }else{
        grafo->mat[v][u] = 0;
    }
}

int existe_aresta(tvertice v, tvertice u) {
    return grafo->mat[v][u] != 0;
}

