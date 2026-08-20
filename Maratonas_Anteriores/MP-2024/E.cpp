
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
    int menor = INF;
    pair<int, int> ijmenor = {INF, INF};
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (val < menor) {
                menor = val;
                ijmenor = {i, j};
            }
        }
    }
    int ans = 0;
    if (ijmenor.first == 0) {
        if (ijmenor.second == 0) {
            ans = 0;
        }
        else if (ijmenor.second == n-1) {
            ans = 1;
        }
    }
    else {
        if (ijmenor.first == n-1) {
            if (ijmenor.second == n-1) {
                ans = 2;
            }
            else if (ijmenor.second == 0) {
                ans = 3;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
