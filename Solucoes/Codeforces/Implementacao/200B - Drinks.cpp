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
    double n; cin >> n;
    double total = n*100;
    double orange = 0;
    for (int i = 0; i < n; ++i) {
        double p; cin >> p;
        orange += p;
    }
    cout << fixed << setprecision(12);
    cout << (orange/total)*100 << '\n';
    return 0;
}
