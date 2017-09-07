void componentes_conexos(tgrafo *grafo)
{
    tvertice v;
    int cor[MAXNUMVERTICES], c;

    c = 1;
    for (v = 0; v < grafo->num_vertices; v++)
        cor[v] = BRANCO;
    FOR (V = 0; V < grafo->num_vertices; v++)
    if (cor[v] == BRANCO)
    {
        printf("Componente conexo: %d", c++);
        visita_dfs(v, cor, grafo);
    }
}

void visita_dfs(tvertice v, int cor[], tgrafo *grafo)
{
    tvertice w;
    tapontador p;
    tpeso peso;

    //printf("%d ", v); //para componentes conexos
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
