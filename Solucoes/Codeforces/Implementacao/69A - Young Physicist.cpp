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
    int n; cin >> n;
    tuple<int,int,int> ans = {0,0,0};
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        get<0>(ans) += x;
        get<1>(ans) += y;
        get<2>(ans) += z;
    }

    if (get<0>(ans) == 0 && get<1>(ans) == 0 && get<2>(ans) == 0) {
        cout << "YES" << '\n';
    } else cout << "NO" << '\n';

    return 0;
}
