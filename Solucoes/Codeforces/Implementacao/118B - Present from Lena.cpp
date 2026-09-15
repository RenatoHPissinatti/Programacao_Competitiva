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
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int space = n - i; space > 0; --space) cout << "  ";
        int count = i;
        for (int j = 0; j <= 2*i; ++j) {
            cout << i - abs(count--);
            if (j < 2*i) cout << ' ';
        }

        cout << '\n';
    }
    for (int i = n; i >= 0; --i) {
        for (int space = n - i - 1; space >= 0; --space) cout << "  ";
        int count = i;
        for (int j = 0; j < 2*i + 1; ++j) {
            cout << i - abs(count--);
            if (j < 2*i) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
