vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
    dfs_num[u] = dfsNumberCounter++;
    dfs_low[u] = dfs_num[u];

    for (auto &[v, w] : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfsRoot) ++rootChildren; // Caso especial (conta quantos filhos a raiz tem)

            articulationPointAndBridge(v);

            // Se o dfs_low[v] for maior que o dfs_num[u] quer dizer que eu sou obrigado a passar por u para chegar em v
            if (dfs_low[v] >= dfs_num[u])   // Para articulation point
                articulation_vertex[u] = 1; // guarda essa informação primeiro
            if (dfs_low[v] > dfs_num[u])
                printf(" (%d, %d) é uma ponte \n", u, v);

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {                    // Se for um ciclo não trivial
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);   // Atualizamos
        }
    }
}

// inside int main()
dfs_num.assign(V, UNVISITED);
dfs_low.assign(V, 0);
dfs_parent.assign(V, -1);
articulation_vertex.assign(V, 0);
dfsNumberCounter = 0;
printf("Pontes: \n");
for (int u = 0; u < V; ++u) {
    if (dfs_num[u] == UNVISITED) {
        dfsRoot = u; rootChildren = 0;
        articulationPointAndBridge(u);
        articulation_vertex[dfsRoot] = (rootChildren > 1); // Caso especial
    }
}

printf("Articulation Points: \n");
for (int u = 0; u < V; ++u) {
    if (articulation_vertex[u]) {
        printf("Vertex: %d\n", u);
    }
}