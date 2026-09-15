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
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    for (int i = n; i > n - k; --i) {
        ans.push_back(i);
    }
    for (int i = 1; i <= n - k; ++i) {
        ans.push_back(i);
    }
    for (int i : ans) cout << i << ' ';

    return 0;
}
