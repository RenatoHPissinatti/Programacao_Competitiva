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
/* "H" prints "Hello, World!",
"Q" prints the source code of the program itself,
"9" prints the lyrics of "99 Bottles of Beer" song,
"+" increments the value stored in the internal accumulator.
*/
int main() {
    string a; cin >> a;
    bool H = false, Q = false, nine = false;
    for (char i : a) {
        if (i == 'H') H = true;
        if (i == 'Q') Q = true;
        if (i == '9') nine = true;
    }

    if (H || Q || nine) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
