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


int dfs(int u, vector<vector<int>>& adj, vector<int>& secondDeep) { //soma dos filhos e retorna altura max
    int maiorH = 0;
    int secondMaiorH = -1;
    for (int v : adj[u]) {
        int next = dfs(v, adj, secondDeep);
        if (next >= maiorH) {
            secondMaiorH = maiorH;
            maiorH = next;
        }
        else {
            if (next > secondMaiorH) {
                secondMaiorH = next;
            }
        }
    }
    secondDeep[u] = secondMaiorH;
    return maiorH + 1;
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
        vector<int> secondMaior(n+1, 0);
        dfs(1, adj, secondMaior);
        ll somaTotal = 0;
        for (int i = 1; i <= n ; i++) {
            if (secondMaior[i] != -1) {
                somaTotal+=secondMaior[i];
            }
        }
        somaTotal+=n;
        cout << somaTotal << '\n';
    }

    return 0;
}
