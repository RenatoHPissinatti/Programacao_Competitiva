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
    int n; cin >> n;
    int ans = 0;
    char last;
    cin >> last;
    for (int i = 1; i < n; ++i) {
        char cur; cin >> cur;
        if (last == cur) ++ans;
        last = cur;
    }

    cout << ans << '\n';
    return 0;
}
