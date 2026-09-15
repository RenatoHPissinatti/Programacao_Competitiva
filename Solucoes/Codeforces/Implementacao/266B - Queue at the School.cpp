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
    int n, t;
    cin >> n >> t;
    vector<char> a(n);
    for (auto &c : a) cin >> c;
    while (t--) {
        for (int i = 0; i < n; ++i) {
            if (i - 1 >= 0) {
                if (a[i] == 'G' && a[i-1] == 'B') {
                    swap(a[i], a[i-1]);
                    ++i;
                }
            }
        }
    }

    for (auto c : a) cout << c;
    cout << '\n';

    return 0;
}
