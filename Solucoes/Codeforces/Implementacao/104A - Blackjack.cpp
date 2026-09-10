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
    if (n <= 10) cout << 0;
    else {
        n -= 10;
        if (n < 10 || n == 11) {
            cout << 4;
        } else if (n == 10) {
            cout << 15;
        } else {
            cout << 0;
        }
    }

    return 0;
}
