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
    int n; cin >> n;
    vector<vector<int>> bags(n, vector<int>(n));
    int count = 1;
    for (int j = 0; j < n; ++j) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                bags[i][j] = count++;
            }
        } else {
            for (int i = n-1; i >= 0; --i) {
                bags[i][j] = count++;
            }
        }

    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << bags[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
