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
    vector<int> a(8);
    bool flag = true;
    for (int i = 0; i < 8; ++i) {
        int num; cin >> num;
        if ((num != 0) && (num != 1)) flag = false;
    }

    if (flag) cout << 'S';
    else cout << 'F';
    return 0;
}
