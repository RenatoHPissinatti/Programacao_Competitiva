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
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;

        if (s[0] == 'y' || s[0] == 'Y') {
            if (s[1] == 'e' || s[1] == 'E') {
                if (s[2] == 's' || s[2] == 'S') {
                    cout << "YES" << '\n';
                    continue;
                }
            }
        }
        cout << "NO" << '\n';
    }

    return 0;
}
