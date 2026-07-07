//
// Created by Usuario on 30/06/2026.
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
const int INF = 1e9;
const ll LINF = LLONG_MAX/4;
const int MOD = 1000000007;

const int UNVISITED = -1;
const int VISITED = 1;

vector<vi> AL;
vector<vi> AL_T;
vi dfs_num;
vi S;
int numSCC;

void kosaraju(int u) {
    dfs_num[u] = VISITED;

    for (int v : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            kosaraju(v);
        }
    }
    S.push_back(u);
}

int main() {
    fastio;
    int t; cin >> t;
    for (int test = 1; test <= t; test++) {
        int n, m;
        cin >> n >> m;
        AL.assign(n, vi());
        AL_T.assign(n, vi());
        dfs_num.assign(n, UNVISITED);

        S.clear();

        for (int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            --a; --b;
            AL[a].push_back(b);
            AL_T[b].push_back(a);
        }

        for (int i = 0; i < n; ++i) {
            if (dfs_num[i] == UNVISITED)
                kosaraju(i);
        }

        dfs_num.assign(n, UNVISITED);
        numSCC = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (dfs_num[S[i]] == UNVISITED) {
                ++numSCC;
                kosaraju(S[i]);
            }
        }

        cout << "Case " << test << ": " << numSCC;
        cout << '\n';
    }
    return 0;
}
