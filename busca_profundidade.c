#define BRANCO 0
#define CINZA 1
#define PRETO 2

void busca_profundidade(tgrafo *grafo)
{
    tvertice v;
    int cor[MAXNUMVERTICES];

    for (v = 0; v < grafo->num_vertices; v++)
        cor[v] = BRANCO;
    for (v = 0; v < grafo->num_vertices; v++)
        if (cor[v] == BRANCO)
            visita_dfs(v, cor, grafo);
}

void visita_dfs(tvertice v, int cor[], tgrafo *grafo)
{
    tvertice w;
    tapontador p;
    tpeso peso;

    cor[v] = CINZA;
    p = primeiro_adj(v, grafo);
    while (p != NULO)
    {
        recupera_adj(v, p, &w, &peso, grafo);
        if (cor[w] == BRANCO)
                visita_dfs(w, cor, grafo);
        p = proximo_adj(v, p, grafo);
    }
    cor[v] = PRETO;
}
