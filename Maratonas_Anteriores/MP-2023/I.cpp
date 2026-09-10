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
    int n; cin >> n;
    ll si = 0;
    ll sp = 0;
    ll res = 0;
    for (int i  = 0; i < n; i++) {
        int val;
        cin >> val;
        ll siAtual = 0;
        ll spAtual = 0;
        if (val == 1) {
            siAtual++;
            siAtual += sp;
            spAtual += si;
        }
        else {
            spAtual++;
            spAtual += sp;
            siAtual += si;
        }
        res += siAtual;
        si = siAtual;
        sp = spAtual;
    }


    cout << res << '\n';
    return 0;
}
