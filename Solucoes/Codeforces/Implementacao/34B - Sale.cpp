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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        if (a[i] < 0) sum += abs(a[i]);
    }
    cout << sum;

    return 0;
}
