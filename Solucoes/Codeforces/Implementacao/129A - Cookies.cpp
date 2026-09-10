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
    int even = 0, odd = 0;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        if (v % 2 == 0) ++even;
        else ++odd;
    }
    if (odd % 2 == 0) cout << even << '\n';
    else cout << odd << '\n';
    return 0;
}
