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

    int n, c, k;
    cin >> n >> c >> k;
    vector<int> dias(n);
    for (int i = 0; i < n; i++) {
        cin >> dias[i];
    }
    vector<int> dp(n + 1);
    dp[0] = k + c;

    for (int i = 0; i < n-1; i++) {
        int hoje = dias[i];
        int prox = dias[i+1];
        dp[i + 1] = dp[i] + min((prox-hoje)*c, k + c);
    }
    cout << dp[n-1] << '\n';
    return 0;
}
