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

const int INF = 1000000000;
const ll LINF = LLONG_MAX/4;
const int MOD = 1000000007;

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int custo1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] - b[i] < 0) {
                custo1 = INF;
                break;
            }
            custo1 += a[i] - b[i];
        }
        sort(all(a));
        sort(all(b));
        int custo2 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] - b[i] < 0) {
                custo2 = INF;
                break;
            }
            custo2 += a[i] - b[i];
        }
        if (custo2 < 1e9) {
            custo2 += c;
        }
        int res = min(custo1, custo2);
        if (res >= 1e9 - 1) {
            res = -1;
        }
        cout << res << '\n';
    }

    return 0;
}
