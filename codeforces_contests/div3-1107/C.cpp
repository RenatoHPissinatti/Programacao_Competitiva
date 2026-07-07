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

        string s;
        cin >> s;
        map<char, int> count;
        int c = 0;
        for (int i = 0; i < s.size() -1; i++) {
            if (s[i] != s[i+1]) {
                c++;
            }
        }
        if (c == 1) {
            cout << 2 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
    }

    return 0;
}
