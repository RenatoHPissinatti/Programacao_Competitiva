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
        ll n, k;
        cin >> n >> k;
        vector<ll> ordem(n);
        for (int i = 0; i < n; i++) {
            cin >> ordem[i];
        }
        vector<vector<ll>> div2(n, vector<ll>(31, 0));
        for (int i = 0; i < n; i++) {
            div2[i][0] = ordem[i];
        }
        for (int i = 0; i < n; i++) {
            for (int exp = 1; exp <= 30; exp++) {
                div2[i][exp] = div2[i][exp-1]/2;
                if (div2[i][exp] == 0) {
                    break;
                }
            }
        }

        vector<vector<ll>> dp(n+1, vector<ll>(31, (LLONG_MAX/4)*-1));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int exp = 0; exp <= i+1 && exp <= 30; exp++) {
                if (dp[i][exp] ==(LLONG_MAX/4)*-1) continue;


                dp[i+1][exp] = max(dp[i+1][exp], dp[i][exp] + div2[i][exp] - k);
                int proxExp = min(30, exp + 1);
                dp[i+1][proxExp] = max(dp[i+1][exp], dp[i][exp] + div2[i][proxExp]);
            }
        }
        ll maior = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 30; j++) {
                maior = max(maior, dp[i][j]);
            }
        }
        cout << maior << '\n';

    },3,

    return 0;
}
