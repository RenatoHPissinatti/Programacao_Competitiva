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
    int a, b, t;
    cin >> a >> b >>t;
    int aaa = lcm(a, b);
    if (t > 0 && lcm(a,b) <= t) {
        cout << "yes" << '\n';
    }
    else {
        cout << "no" << '\n';
    }

    return 0;
}
