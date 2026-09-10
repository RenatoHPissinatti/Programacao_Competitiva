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
    string a; cin >> a;
    string b; cin >> b;
    a = a + b;
    string ans;
    for (int i = 0; i < a.size()/2; ++i) {
        char x = a[i];
        char y = a[i + (a.size()/2)];
        ans.push_back((x != y ? '1' : '0'));
    }
    cout << ans << '\n';
    return 0;
}
