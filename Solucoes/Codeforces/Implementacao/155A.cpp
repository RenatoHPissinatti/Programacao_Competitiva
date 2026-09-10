#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

const int INF = 1e9;
const ll LINF = LLONG_MAX/4;
const int MOD = 1000000007;

int main() {
    int n; cin >> n;

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    if (n == 2) {
        int a; cin >> a;
        int b; cin >> b;
        if (a == b) {
            cout << 0;
        } else cout << 1;
        return 0;
    }

    vector<int> a(n);
    int minV = INF, maxV = -1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x < minV) {
            ++ans; minV = x;
        }
        if (x > maxV) {
            ++ans; maxV = x;
        }
    }

    cout << ans - 2 << '\n';
    return 0;
}
