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

vector<int> cansativas;
vector<int> revigorantes;
ll d;
int main() {
    fastio;
    int c, r;
    cin >> d >> c >> r;
    cansativas.resize(c);
    revigorantes.resize(r);
    for (int &i : cansativas) cin >> i;
    for (int &i : revigorantes) cin >> i;

    int c_idx = 0;
    int r_idx = 0;
    int ans = 0;
    for (int i = 0; i < c + r; ++i) {
        if (c_idx == c) {
            ans += r - r_idx;
            break;
        }
        if (d >= cansativas[c_idx]) {
            d -= cansativas[c_idx];
            ++ans;
            ++c_idx;
        } else if (r_idx < r){
            d += revigorantes[r_idx];
            ++ans;
            ++r_idx;
        }
    }

    cout << ans << '\n';

    return 0;
}
