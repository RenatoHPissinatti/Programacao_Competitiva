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

    string s1, s2;
    cin >> s1 >> s2;
    int p, q;
    cin >> p >> q;
    // aab, aac ->  aabaac vs aabaac ou aabaabaabaac aacaabaabaab

    if (p == 0 || q == 0) {
        cout << '=' << '\n';
        return 0;
    }
    if (s1 + s2 < s2 + s1) {
        cout << '<' << '\n';
        return 0;
    }
    if (s1 + s2 > s2 + s1) {
        cout << '>' << '\n';
        return 0;
    }
    cout << '=' << '\n';

    return 0;
}
