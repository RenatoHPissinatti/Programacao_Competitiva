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
    int t, d, m;
    cin >> t >> d >> m;
    int last = 0;
    bool flag = false;
    int atual;
    for (int i = 0; i < m; i++) {
        cin >> atual;
        if (atual - last >= t) {
            flag = true;
        }
        last = atual;
    }
    if (d - last >= t) {
        flag = true;
    }
    if (flag) {
        cout << 'Y' << '\n';
    }
    else {
        cout << 'N' << '\n';
    }
    return 0;
}
