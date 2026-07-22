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
        map<int, int> mapafoda;
        pair<int, int> val1;
        pair<int, int> val2;
        int val;
        vector<int> entrada(n);
        for (int i = 0; i < n; i++) {
            cin >> entrada[i];
        }
        int res = 0;
        if (entrada[0] == entrada[1]) {
            for (int i = 0; i < n; i++) {
                if (entrada[i] != entrada[0]) {
                    res = i+1;
                }
            }
        }
        else {
            if (entrada[2] == entrada[0]) {
                res = 2;
            }
            else {
                res = 1;
            }
        }
        cout << res << '\n';

    }

    return 0;
}
