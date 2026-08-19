//
// Created by Usuario on 18/08/2026.
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
vector<vector<int>> grid;
vector<vector<pair<int,int>>> AL;
int res = 0;

struct state {
    int cur;
    int watual;
};

void solve(int o, int n, vector<vector<bool>>& tirada) {
    queue<state> q;
    state val = {o, 0};
    vector<int> menorpreco(n + 1, INF);
    menorpreco[o] = 0;
    q.push(val);
    while (!q.empty()) {
        state atual = q.front();
        int cur = atual.cur;
        q.pop();
        bool quebro = false;
        for (auto [v, w] : AL[atual.cur]) {
            int proxw = atual.watual + w;
            if (cur != o && proxw == grid[o][v] && !tirada[o][v]) {
                res++;
                tirada[o][v] = true;
                tirada[v][o] = true;
            }
            else if (cur != o && proxw < grid[o][v]) {
                res = -1;
                quebro = true;
                break;
            }
            if (menorpreco[v] > proxw) {
                q.push({v, proxw});
                menorpreco[v] = proxw;
            }
        }
        if (quebro) break;
    }
}


int main() {
    fastio;
    int n; cin >> n;
    grid.assign(n, vector<int>(n));
    AL.assign(n, vector<pair<int,int>>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val; cin >> val;
            grid[i][j] = val;
            if (i != j)
                AL[i].emplace_back(j, val);
        }
    }
    bool no_answer = false;
    int ans = 0;
    vector<vector<bool>> tirada(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        int val = res;
        solve(i, n, tirada);
        if (res == -1) {
            cout << -1 << '\n';
            return 0;
        }
        val = res;
    }

    cout << res << '\n';

    return 0;
}
