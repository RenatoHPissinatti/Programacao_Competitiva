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
const ll LINF = LLONG_MAX / 4;
const int MOD = 1000000007;


//7
// 0 4 2 6 1 5 3

ll contrib(int l, int r, int k, vector<int> &entrada) {
    string s;
    for (int i = l; i < r; i++) {
        int val = entrada[i];
        if (val != k) {
            if (val > k) {
                s.push_back('D');
            }
            else {
                s.push_back('E');
            }
        }
    }
    vector<ll> dp(s.size() + 1);
    dp[0] = 0;
    if (s.size() > 1) {
        if (s[0] != s[1]) {
            dp[1] = 1;
        }
        else {
            dp[1] = 0;
        }
    }
    else {
        dp[1] = 0;
    }
    for (int j = 1; j < s.size() - 1; j++) {
        if (s[j] != s[j + 1]) { dp[j] = max(dp[j - 2] + 1, dp[j - 1]); }
    }
    return dp[s.size() - 1];
}


int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> entrada(n);
    for (int i = 0; i < n; i++) {
        cin >> entrada[i];
    }
    vector<vector<ll> > maioresidx(n, vector<ll>(n));
    for (int i = 1; i <= n; i++) {
        for (int l = 0; l < n - i; l++) {
            int r = l + i;
            for (int k = l; k < r; k++) {
            }
        }
    }


    return 0;
}
