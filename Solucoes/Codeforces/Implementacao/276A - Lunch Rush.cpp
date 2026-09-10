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
    ll n, k;
    ll maxV = -LINF;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int f, t;
        cin >> f >> t;
        maxV = max(maxV, (t < k ? f : f - (t - k)));
    }
    cout << maxV << '\n';
    return 0;
}
