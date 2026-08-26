//
// Created by Usuario on 20/08/2026.
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
int n, m;
vector<vector<int>> AL;
vector<vector<int>> adj;
int commum[101][101];
bool has[101][1000006];
int par[101][101];
bool reach[101][101];

int main() {
    fastio;
    cin >> n >> m;
    AL.assign(n, vector<int>());
    adj.assign(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        int sz; cin >> sz;
        for (int j = 0; j < sz; ++j) {
            int x; cin >> x;
            --x;
            has[i][x] = true;
            AL[i].push_back(x);
        }
    }

    auto get = [&](int i, int j) {
        if (AL[i].size() > AL[j].size()) swap(i, j);

        for (int k : AL[i]) {
            if (has[j][k]) return k;
        }
        return -1;
    };
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int cur = get(i, j);
            commum[i][j] = commum[j][i] = cur;
            if (cur != -1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // Verificar rota de um filme para todos os outro
    for (int ini = 0; ini < n; ++ini) {
        queue<int> q;
        q.push(ini);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int &k : adj[x]) {
                if (!reach[ini][k] && commum[x][k] != -1) {
                    reach[ini][k] = true;
                    par[ini][k] = x;
                    q.push(k);
                }
            }
        }
    }

    auto solve = [&](int a, int b) {
        for (int i = 0; i < n; ++i) {
            if (has[i][a]) {
                for (int j = 0; j < n; ++j) {
                    if (reach[i][j] && has[j][b]) {
                        vector<int> ans;
                        int x = j;
                        ans.push_back(b + 1);
                        while (1) {
                            ans.push_back(x + 1); //filme
                            if (x == i) break;
                            int nxt = par[i][x];
                            ans.push_back(commum[x][nxt] + 1); //ator
                            x = nxt;
                        }
                        ans.push_back(a + 1);
                        reverse(ans.begin(), ans.end());
                        cout << (ans.size() + 1)/2 << '\n';
                        for (auto m : ans) cout << m << " ";
                        cout << '\n';
                        return;
                    }
                }
            }
        }
        cout << "-1\n";
    };
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        solve(a, b);
    }
    return 0;
}
