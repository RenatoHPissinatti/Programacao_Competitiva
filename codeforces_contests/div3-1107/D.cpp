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
        vector<int> a(n);
        vector<int> b(n);
        for (int  i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<ll> dp(n);
        dp[0] = b[0] - a[0];
        if (b[0] - a[0] < 0) {
            cout << "NO" << '\n';
            continue;
        }
        bool flag = true;
        for (int i = 1; i < n; i++) {
            int diff = b[i] - a[i];
            dp[i] = diff + dp[i-1];
            if (dp[i] < 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" <<'\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
