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
    int n;
    cin >> n;
    vector<int> vet(n);
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, INF));

    for (int tam = 1; tam <= n; tam++) {
        if (tam == 1) {
            for (int i = 0; i < n; i++) {
                dp[i][i] = 1;
            }
            continue;
        }
        for (int l = 0; l <= n - tam; l++) {
            int r = l + tam - 1;
            if (tam == 2) {
                if (vet[l] == vet[r]) {
                    dp[l][r] = 1;
                }
                else {
                    dp[l][r] = 2;
                }
                continue;
            }
            if (vet[l] == vet[r]) {
                dp[l][r] = dp[l+1][r-1];
            }
            else {
                dp[l][r] = dp[l+1][r-1] + 2;
            }

            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
            }
            for (int k = l; k < r-1; k++) {
                int add;
                if (vet[l] == vet[r]) {
                    add = 0;
                }
                else {
                    add = 2;
                }
                dp[l][r] = min(dp[l][r], dp[l+1][k] + dp[k+1][r-1] + add);
            }
        }
    }
    cout << dp[0][n-1] << '\n';
    return 0;
}
