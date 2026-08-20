
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
    int BITMAX = 32;
    vector<int> freq(BITMAX+1, 0);
    for (int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        for (int j = 0; j <= BITMAX; j++) {
            if ((val & (1ll<<j)) != 0) {
                freq[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ll res = 0;
        for (int j = BITMAX; j >= 0; j--) {
            if (freq[j] >= 1) {
                freq[j]--;
                res += (1ll << j);
            }
        }
        cout << res << ' ';
    }

    cout << '\n';
    return 0;
}
