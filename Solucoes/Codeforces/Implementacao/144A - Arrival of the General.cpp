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
    int n;
    cin >> n;
    vector<int> a(n);
    int minV = INF, maxV = 0;
    int minI = n - 1, maxI = 0;
    for (int i = 0; i < n; ++i) {
        int h; cin >> h;
        if (h <= minV) {
            minV = h;
            minI = i;
        }

        if (h > maxV) {
            maxV = h;
            maxI = i;
        }
    }

    if (maxI < minI) {
        cout << maxI + ((n - 1) - minI);
    } else {
        cout << (maxI +( (n - 1) - minI))- 1;
    }
    return 0;
}
