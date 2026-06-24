//
// Created by Usuario on 24/06/2026.
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

const int INF = 1e9;
const ll LINF = LLONG_MAX/4;
const int MOD = 1000000007;

string bipartite_graph_check(vector<vi> &AL, int n) {
    bool isBipartite = true;
    vector<int> color(n, INF);
    int s = 0;
    color[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty() && isBipartite) {
        int u = q.front();
        q.pop();
        for (int v : AL[u]) {
            if (color[v] == INF) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                isBipartite = false;
                break;
            }
        }
    }
    if (isBipartite) {
        return "BICOLORABLE.";
    }
    return "NOT BICOLORABLE.";
}

int main() {
    fastio;

    int n;
    while (cin >> n && n != 0) {

        vector<vi> AL(n);
        int l; cin >> l;
        for (int i = 0; i < l; ++i) {
            int a, b;
            cin >> a >> b;
            AL[a].push_back(b);
            AL[b].push_back(a);
        }

        cout << bipartite_graph_check(AL, n) << '\n';
    }

    return 0;
}
