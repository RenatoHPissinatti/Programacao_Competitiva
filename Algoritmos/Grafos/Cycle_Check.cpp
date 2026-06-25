void (int u) {
    dfs_num[u] = EXPLORED;
    for (auto &[v,w] : AL[u]) {
        if (dfs_num[v] == UNVISITED) { // EXPLORED -> UNVISITED;
            cout << "É UM CAMINHO"
            dfs_parent[v] = u;
            cycleCheck(v);
        } else if (dfs_num[v] == EXPLORED) {
            if (v == dfs_parent[u]) {
                cout << "É BIDIRECIONAL";
            } else {
                cout << "TEM CICLO";
            }
        } else if (dfs_num[v] == VISITED){
            cout << "ARESTA DE AVANÇO" // raro
        }
    }
    dfs_num[u] = VISITED;
}