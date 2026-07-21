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
        int n = 8;
        vector<string> tab(n);
        string res;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (char c : s) {
                if (c != '.') {
                    res += c;
                    break;
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}
