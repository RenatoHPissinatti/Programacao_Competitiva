//
// Created by Usuario on 10/09/2026.
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
    n = ((1 + n)*n)/2;

    m = m % n;
    if (m == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int count = 1;
    int last_m = m;
    while (m > 0) {
        last_m = m;
        m -= count;
        ++count;
    }

    cout << (m < 0 ? last_m : m) << '\n';

    return 0;
}
