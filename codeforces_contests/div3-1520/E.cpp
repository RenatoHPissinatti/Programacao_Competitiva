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

struct dpr {
    ll qnt;
    ll sum;
};

int main() {
    fastio;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> ovelhas;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '*') {
                ovelhas.push_back(i);
            }
        }
        vector<ll> dpi (n + 2, 0);
        vector<dpr> dpesq (n + 2, {0, 0});
        vector<dpr> dpdir (n+2, {0, 0});

        for (int i = 0; i < n; i++) {
            dpi[i+1] = dpesq[i].sum;
            if (i > 0) {
                dpesq[i + 1].sum =
            }
            if (i < n-1) {

            }
        }
    }

    return 0;
}
