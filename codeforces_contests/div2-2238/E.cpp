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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> ndp(n + 1, vector<int>(n + 1, INF));
            for (int f = 0; f <= i; f++) {
                for (int suffix = 0; suffix <= i; suffix++) {
                    if (dp[f][suffix] == INF) continue;

                    if (s[i] != 'T') {
                        int newF = f+1;
                        int newSuffix = suffix + 1;
                        int newMaximum = max(dp[f][suffix], newSuffix);
                        ndp[newF][newSuffix] = min(ndp[newF][newSuffix], newMaximum);
                    }

                    if (s[i] != 'F') {
                        int newF = f;
                        int newSuffix = max(0,suffix - 1);
                        ndp[newF][newSuffix] = min(ndp[newF][newSuffix], dp[f][suffix]);
                    }

                }
            }
            dp.swap(ndp);
        }
        int res = 0;
        for (int f = 0; f <= n; f++) {
            for (int suffix = 0; suffix <= n; suffix++) {
                if (dp[f][suffix] == INF) {
                    continue;
                }
                res = max(res, f - dp[f][suffix]);
            }
        }
        cout << res << '\n';
    }


    return 0;
}
