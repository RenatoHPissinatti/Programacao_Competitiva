//
// Created by Usuario on 26/06/2026.
//
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define vii vector<pii>

const int UNVISITED = -1;
const int VISITED = 1;

vector<vi> AL;
int numSCC, dfsNumberCounter;
vi dfs_num, dfs_low, visited;
stack<int> St;

void tarjanSCC (int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter;
    ++dfsNumberCounter;
    St.push(u);
    visited[u] = 1;
    for (int v : AL[u]) {
        if (dfs_num[v] == UNVISITED) tarjanSCC(v);

        if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_num[u] == dfs_low[u]) {
        ++numSCC;
        while (true) {
            int v = St.top();
            St.pop();
            visited[v] = 0;
            if (v == u) break;
        }
    }
}

const int INF = 1e9;
const ll LINF = LLONG_MAX/4;
const int MOD = 1000000007;

int main() {
    fastio;
    int n, m;
    while (cin >> n >> m && (n != 0 && m != 0)) {
        AL.assign(n, vi());
        dfs_low.assign(n, 0); dfs_num.assign(n, UNVISITED); visited.assign(n,0);
        numSCC = dfsNumberCounter = 0;
        for (int i = 0; i < m; ++i) {
            int v, w, p;
            cin >> v >> w >> p;
            --v; -- w;
            AL[v].push_back(w);
            if (p == 2) AL[w].push_back(v);
        }
        for (int u = 0; u < n; ++u) {
            if (dfs_num[u] == UNVISITED)
                tarjanSCC (u);
        }
        cout << (numSCC > 1 ? '0' : '1') << '\n';
    }
    return 0;
}
