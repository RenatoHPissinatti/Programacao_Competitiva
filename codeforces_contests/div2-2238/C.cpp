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


void dfs(int u, vector<vector<int>>& adj, int h, vector<int>& hn) { //soma dos filhos e retorna altura max
    hn[u] = h;
    for (int v : adj[u]) {
        dfs(v, adj, h+1, hn);
    }
}


int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        for (int i = 2; i <= n; i++) {
            int v;
            cin >> v;
            adj[v].push_back(i);
        }
        vector<int> alturas(n+1, 0);
        dfs(1, adj, 0, alturas);
        for (int i = n; i >= 0; i--) {

        }
    }

    return 0;
}
