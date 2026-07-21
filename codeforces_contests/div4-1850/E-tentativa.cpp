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
        ll n;
        ll C;
        cin >> n >> C;
        ll c = 0;
        ll ssum = 0;
        ll sqsum = 0;
        ll s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            ssum += s;
            sqsum += s*s;
            c+=s*s;
        }
        ll w = 1;
        ll l = 1;
        ll r = sqrt(C);
        C = C - sqsum;
        while (true) {
            ll divisor = (w*n + ssum);
            if (4*w == C/divisor && C%divisor == 0) {
                break;
            }
            if (4*w > C/divisor) {
                r = w;
                w = (l + r)/2;
            }
            else {
                l = w;
                w = (l + r)/2;
            }
        }


        cout << w << '\n';
    }
    return 0;
}
