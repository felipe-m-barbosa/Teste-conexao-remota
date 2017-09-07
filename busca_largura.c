#define BRANCO 0
#define CINZA 1
#define PRETO 2

void busca_largura(tgrafo *grafo)
{
    tvertice v;
    int cor[MAXNUMVERTICES];

    for (v = 0; v < grafo->num_vertices; v++)
        cor[v] = BRANCO;
    for (v = 0; v < grafo->num_vertices; v++)
        if (cor[v] == BRANCO)
            visita_bfs(v, cor, grafo);
}

void visita_bfs(tvertice v, int cor[], tgrafo *grafo)
{
    tvertice w;
    tapontador p;
    tpeso peso;
    std::queue<tvertice> q;

    cor[v] = CINZA;
    q.push(v);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        p = primeiro_adj(v, grafo);
        while (p != NULO)
        {
            recupera_adj(v, p, &w, &peso, grafo);
            if (cor[w] == BRANCO)
            {
                cor[w] = CINZA;
                q.push(w);
            }
            p = proximo_adj(v, p, grafo);
        }
        cor[v] = PRETO;
    }
}
