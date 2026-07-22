#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define vii vector<pii>

const int INF = 1e9;
const ll LINF = LLONG_MAX/4;
const int MOD = 1000000007;

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        ll p, q;
        cin >> p >> q;
        int paredesr;
        int tetosr;
        pair<int, int> res = {-1, -1};
        for (int j = 1; j*j <= p/2 + q; j++) {
            if ((p + 2*q -j)%(2*j + 1) != 0) {
                continue;
            }
            ll i = (p + 2*q -j)/(2*j + 1);
            if (p >= abs(i - j) && i >= j) {
                res = {i,j};
                break;
            }
        }
        if (res.first == -1) {
            cout << -1 << '\n';
        }
        else {
            cout << res.first << ' ' << res.second << '\n';
        }
    }

    return 0;
}
