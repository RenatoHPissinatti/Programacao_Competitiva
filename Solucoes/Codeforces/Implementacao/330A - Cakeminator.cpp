//
// Created by Usuario on 10/09/2026.
//
//
// Created by Usuario on 09/09/2026.
//
//
// Created by Usuario on 09/09/2026.
//
//
// Created by Usuario on 09/09/2026.
//
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

const int INF = 1e9;
const ll LINF = LLONG_MAX/4;
const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    map<int, bool> isS_i;
    map<int, bool> isS_j;
    map<pair<int,int>, bool> isS_ij;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            grid[i][j] = c;
            if (c == 'S') {
                isS_i[i] = true;
                isS_j[j] = true;
            }
        }
    }
    int ans = 0;
    int qtd = 0;
    for (int i = 0; i < n; ++i) {
        if (!isS_i[i]) {
            ans += m;
            qtd++;
        }
    }
    for (int j = 0; j < m; ++j) {
        if (!isS_j[j]) {
            ans += n - qtd;
        }
    }

    cout << ans << '\n';


    return 0;
}
