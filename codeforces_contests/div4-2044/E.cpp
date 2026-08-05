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
const double EPS = 1e-9;
int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        ll k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;


        ll count = 0;

        for (ll kn = 1; kn <= 1e9; kn*=k) {
            ll r = min(r1, r2/kn);
            ll l = max(l1, (l2 + kn - 1)/kn);
            if (r >= l) {
                count += r - l + 1ll;
            }
        }
        cout << count << '\n';
    }

    return 0;
}
