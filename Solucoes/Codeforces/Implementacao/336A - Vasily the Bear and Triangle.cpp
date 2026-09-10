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
    ll x, y;
    cin >> x >> y;

    ll total = abs(x) + abs(y);

    if (x < 0) {
        if (y < 0) {
            cout << -total << " 0 0 " << -total;
        } else {
            cout << -total << " 0 0 " << total;
        }
    } else {
        if (y < 0) {
            cout << "0 " << total << " " << -total  << " 0";
        } else {
            cout << "0 " << total << " " << total  << " 0";
        }
    }
    return 0;
}
