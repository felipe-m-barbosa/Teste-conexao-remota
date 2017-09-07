#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXNUMVERTICES 100

typedef struct {
    int vertice;
    int peso;
    struct taresta *prox;
} taresta;

typedef struct {
    int identificacao;
    taresta *aresta;
    tvertice *proxVertice;
} tvertice;

typedef struct {
    tvertice *verticeInicial;
    tvertice *verticeFinal;
    int numVertices;
} tgrafo;

void inicializaGrafo(tgrafo *grafo){
    grafo->verticeInicial = NULL;
    grafo->verticeFinal = NULL;
    grafo->num_vertices = 0;
}

void insereVertice(tgrafo *grafo, tvertice *vertice, int identificacao){
    if(grafo->num_vertices == 0){
        grafo->verticeInicial = vertice;
        grafo->verticeFinal = vertice;
        grafo->verticeInicial->proxVertice = NULL;
        //grafo->verticeFinal->proxVertice = NULL;
        grafo->verticeInicial->aresta = NULL;
        //grafo->verticeFinal->aresta = NULL;
        grafo->verticeInicial->identificacao = identificacao;
        grafo->num_vertices++;
    }
    else{
        //inserindo no começo do grafo
        vertice->proxVertice = grafo->verticeInicial->proxVertice;
        grafo->verticeInicial = vertice;
        //Abaixo insere no fim
        /*grafo->verticeFinal->proxVertice = vertice;
        grafo->verticeFinal = vertice;
        grafo->verticeFinal->proxVertice = NULL;
        grafo->verticeFinal->identificacao = identificacao;
        grafo->verticeFinal->aresta = NULL;
        grafo->num_vertices++;*/
    }
}

void removeVertice(tgrafo *grafo, int identificacao){
    tvertice *verticeAtual = grafo->verticeInicial;
    tvertice *verticeAnterior = NULL;
    int i = 0
    while(verticeAtual->identificacao != identificacao && i <= grafo->num_vertices){
        i++;
        verticeAnterior = verticeAtual;
        verticeAtual = verticeAtual->proxVertice;
    }
    if(verticeAtual->identificacao == identificacao){
        verticeAnterior->proxVertice = verticeAtual->proxVertice;
        //free(verticeAtual);
        //É isso mesmo ???
    }
}

void insereAresta(tgrafo *grafo, int verticeA, int verticeB){
    tvertice *verticeAtual = grafo->verticeInicial;
    int i = 0
    while(verticeAtual->identificacao != verticeA && i <= grafo->num_vertices){
        i++;
        verticeAtual = verticeAtual->proxVertice;
    }
    if(verticeAtual->identificacao == identificacao){
        taresta *novaAresta;
        //Inserindo no começo da lista
        novaAresta->prox = verticeAtual->aresta->prox;
        verticeAtual->aresta = novaAresta;
        /*Inserindo no fim da lista
        if(verticeAtual->aresta == NULL){
            verticeAtual->aresta = novaAresta;
            verticeAtual->aresta->vertice = verticeB;
            verticeAtual->aresta->prox = NULL;
        }else{
            novaAresta->prox = verticeAtual->aresta;
            verticeAtual->aresta = novaAresta;
            verticeAtual->aresta->vertice = verticeB;
        }*/
    }
}

void removeAresta(tgrafo *grafo, int verticeA, int verticeB){
    tvertice *verticeAtual = grafo->verticeInicial;
    taresta *arestaAnterior = NULL;
    taresta *arestaAtual = NULL;
    int i = 0
    while(verticeAtual->identificacao != verticeA && i <= grafo->num_vertices){
        i++;
        verticeAtual = verticeAtual->proxVertice;
    }
    if(verticeAtual->identificacao == verticeA){
        arestaAtual = verticeAtual->aresta;
        while(arestaAtual->vertice != NULL){
            if(arestaAtual->vertice == verticeB){
                    if(verticeAtual->aresta->vertice == verticeB)
                    {
                        verticeAtual->aresta = verticeAtual->aresta->prox;
                    }
                    else
                    {
                        arestaAnterior->prox = arestaAtual->prox;
                    }
                //free(arestatul);
                //é isso ???
                return;
            }
            arestaAnterior = arestaAtual;
            arestaAtual = arestaAtual->prox;
        }
    }
}

void existeAresta(tgrafo *grafo, int verticeA, int verticeB){
    tvertice *verticeAtual = grafo->verticeInicial;
    taresta *arestaAnterior = NULL;
    taresta *arestaAtual = NULL;
    int i = 0
    while(verticeAtual->identificacao != verticeA && i <= grafo->num_vertices){
        i++;
        verticeAtual = verticeAtual->proxVertice;
    }
    if(verticeAtual->identificacao == verticeA){
        arestaAtual = verticeAtual->aresta;
        while(arestaAtual->vertice != NULL){
            if(arestaAtual->vertice == verticeB){
                printf("Existe aresta!!");
                return;
            }
            arestaAtual = arestaAtual->prox;
        }
    }
}
