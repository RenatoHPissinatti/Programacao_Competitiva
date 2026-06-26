// ======================================================================
// ======================== KOSARAJU'S ALGORITHM ========================
// ======================================================================

void kosaraju (int u, int pass) { // pass = 1 (original), 2 (transposto)
    dfs_num[u] = VISITED;
    vii &neighbor = (pass == 1) ? AL[u] : AL_T[u];

    for (auto &[v, w] : neighbor) {
        if (dfs_num[v] == UNVISITED) {
            kosaraju(v, pass);
        }
    }
    S.push_back(u);
}

// inside int main ()
    S.clear();
    dfs_num.assign(N, UNVISITED);
    for (int u = 0; iu < N; ++u) {
        if (dfs_num[u] == UNVISITED) {
            kosaraju(u, 1);
        }
    }
    numSCC = 0;
    dfs_num.assign(N, UNVISITED);
    for (int i = N - 1; i >= 0; --i) {
        if (dfs_num[S[i]] == UNVISITED) {
            ++numSCC;
            kosaraju(S[i], 2);
        }
    }

// ======================================================================
// ========================= TARJAN'S ALGORITHM =========================
// ======================================================================

int dfsNumberCounter, numSCC;
vi dfs_num, dfs_low, visited;
stack<int> St;

void tarjanSCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter;
	dfsNumberCounter++;
	St.push(u);
	visited[u] = 1;
	for (auto &[v,w] : AL[u]) {
		if (dfs_num[v] == UNVISITED) {
			tarjanSCC(v);
		}
		if (visited[v]) {
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
	}
	if (dfs_num[u] == dfs_low[u]) {
		++numSCC;
		while(true) {
			int v = St.top();
			St.pop();
			visited[v] = 0;
			if (v == u) break;
		}
	}
}

// inside int main()
	dfs_num.assign(V, UNVISITED);
	dfs_low.assign(V, 0);
	visited.assign(V, 0);
	while (!St.empty()) St.pop();
	dfsNumberCounter = numSCC = 0;
	for (int u = 0; u < V; ++u) {
	    if (dfs_num[u] == UNVISITED)
			tarjanSCC (u);
	}
