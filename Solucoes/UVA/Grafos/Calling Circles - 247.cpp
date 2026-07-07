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


int dfsNumberCounter, numSCC;
vi dfs_num, dfs_low, visited;
vector<vi>  AL;
stack <int> St;

map<string, int> name_id;
vector<string> id_name;

int get_id(const string& name) {
    if (name_id.find(name) == name_id.end()) {
        name_id[name] = id_name.size();
        id_name.push_back(name);
    }
    return name_id[name];
}


void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter;
    dfsNumberCounter++;
    St.push(u);
    visited[u] = 1;
    for (int v : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            tarjanSCC(v);
        }
        if (visited[v]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_low[u] == dfs_num[u]) {
        ++numSCC;
        bool first = true;
        while (true) {
            int v = St.top(); St.pop();
            visited[v] = 0;

            if (!first) cout << ", ";
            first = false;
            cout << id_name[v];

            if (u == v) break;

        }
        cout << '\n';
    }
}

int main() {
    fastio;
    int n, m;
    int count = 1;
    bool first_case = true;
    while (cin >> n >> m && (n != 0 || m != 0)) {

        if (!first_case) cout << '\n';
        first_case = false;

        dfsNumberCounter = 0;
        numSCC = 0;
        dfs_num.assign(n, UNVISITED);
        dfs_low.assign(n, 0);
        visited.assign(n, 0);
        AL.assign(n, vi());
        while (!St.empty()) St.pop();

        id_name.clear();
        name_id.clear();


        for (int i = 0; i < m; ++i) {
            string caller, called;
            cin >> caller >> called;
            int u = get_id(caller);
            int v = get_id(called);

            AL[u].push_back(v);
        }

        cout << "Calling circles for data set " << count++ << ":\n";
        for (int u = 0; u < n; ++u) {
            if (dfs_num[u] == UNVISITED) {
                tarjanSCC(u);
            }
        }
    }
    return 0;
}
