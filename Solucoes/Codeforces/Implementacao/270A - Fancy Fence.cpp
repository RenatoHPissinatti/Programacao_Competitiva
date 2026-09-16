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
    int t; cin >> t;
    while (t--) {
        int S; cin >> S;
        if (360 % (180 - S) == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
