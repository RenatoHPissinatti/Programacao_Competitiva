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
    string s;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll count = 0;
        vector<ll> entrada(n + 1);
        entrada[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> entrada[i];
        }
        vector<ll> dp(n+1, 0);
        for (int i = 1; i <=n; i++) {
            ll num = entrada[i];
            dp[i] = dp[i-1];
            if (num < i) {
                dp[i]++;
                if (num > 0) {
                    count += dp[num-1];
                }
            }
        }
        cout << count << '\n';
    }


    return 0;
}
