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
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        if (s.size() > 10) {
            cout << s[0] << s.size() - 2 << *(s.end()-1);
        } else cout << s;

        cout << '\n';
    }
    return 0;
}
