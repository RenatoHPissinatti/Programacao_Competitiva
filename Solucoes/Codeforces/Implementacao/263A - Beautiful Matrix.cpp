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
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            int v; cin >> v;
            if (v == 1) {
                cout << abs(i - 3) + abs(j - 3);
            }
        }
    }
    return 0;
}
