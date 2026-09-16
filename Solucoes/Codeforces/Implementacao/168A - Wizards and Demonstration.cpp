//
// Created by Usuario on 15/09/2026.
//
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

const int INF = 1e9;
const ll LINF = LLONG_MAX/4;
const int MOD = 1000000007;

int main() {
    fastio;
    int n, x, y;
    cin >> n >> x >> y;
    double needed = ceil(n*double(y)/100.0);
    if (needed <= x) cout << "0\n";
    else {
        cout << needed - x << '\n';
    }
    return 0;
}
