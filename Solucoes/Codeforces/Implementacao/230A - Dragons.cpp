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
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>> dragons(n);
    for (auto &i : dragons) cin >> i.first >> i.second;
    sort(dragons.begin(), dragons.end());
    for (auto [strength, bonus] : dragons) {
        if (strength  >= s) {
            cout << "NO\n";
            return 0;
        }
        s += bonus;
    }
    cout << "YES\n";
    return 0;
}
