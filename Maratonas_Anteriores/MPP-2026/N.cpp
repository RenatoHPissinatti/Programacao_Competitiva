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
    cin >> n;
    vector<ll> pedras(n+2);
    for (int i = 0; i < n+2; i++) {
        cin >> pedras[i];
    }
    sort(all(pedras));
    ll S = pedras[n + 1];
    ll somaTotal = 0;
    vector<ll> res(n);
    int nxt = 0;
    for (int i = n; i >= 2; i--) {
        ll pedra = pedras[i];
        res[nxt] = S - pedra;
        nxt++;
        somaTotal += (S - pedra);
    }
    ll M = S - somaTotal;
    res[nxt] = M;

    cout << S << ' ' << M << '\n';
    for (int val : res) {
        cout << val << ' ';
    }
    cout << '\n';
    return 0;
}
