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
        if (n == 2) {
            cout << -1 << '\n';
            continue;
        }
        vector<vector<int>> res (n, vector<int>(n));
        int count = 1;
        for (int i = 0; i < n; i++) {
            res[i][i] = count;
            count++;
        }

        for (int b = 1; b < n; b++) {
            int i = b;
            int j = 0;
            while (i < n) {
                res[i][j] = count;
                count++;
                i++;
                j++;
            }
            i = 0;
            j = b;
            while (j < n) {
                res[i][j] = count;
                count++;
                i++;
                j++;
            }
        }

        for (int i = 0; i< n; i++) {
            for (int j = 0; j < n; j++) {
                cout << res[i][j] << ' ';
            }
            cout << '\n';
        }

    }

    return 0;
}
