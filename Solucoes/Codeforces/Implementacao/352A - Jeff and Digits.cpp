//
// Created by Usuario on 14/09/2026.
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
    ll sum = 0;
    ll n_zero = 0;
    ll n_five = 0;
    ll n_max = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        sum += x;
        if (x == 0) ++n_zero;
        else ++n_max;
        if (sum % 9 == 0) n_five = n_max;
    }

    if (n_five && n_zero) {
        for (int i = 0; i < n_five; ++i) cout << '5';
        for (int i = 0; i < n_zero; ++i) cout << '0';
        cout << '\n';
        return 0;
    }
    if (!n_zero) cout << "-1" << '\n';
    else cout << '0' << '\n';
    return 0;
}
