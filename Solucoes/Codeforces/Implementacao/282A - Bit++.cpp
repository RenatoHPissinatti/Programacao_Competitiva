//
// Created by Usuario on 10/09/2026.
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
    int count = 0;
    for (int i = 0; i < n; ++i) {
        string instruction;
        cin >> instruction;
        if (instruction[1] == '+') ++count;
        else --count;
    }

    cout << count << '\n';
    return 0;
}
