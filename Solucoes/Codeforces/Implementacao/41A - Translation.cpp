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
    string s, rev;
    cin >> s >> rev;
    size_t t = s.size();
    if (t != rev.size()) {
        cout << "NO\n";
        return 0;
    }
    for (size_t i = 0; i < t; ++i) {
        if (s[i] != rev[t - i - 1]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
