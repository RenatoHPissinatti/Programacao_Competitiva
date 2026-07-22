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
        map<ll, ll> xiguais;
        map<ll, ll> yiguais;
        map<ll, ll> subiguais;
        map<ll, ll> somaiguais;
        ll somaTotal = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            somaTotal += 2*(xiguais[x]);
            xiguais[x]++;
            somaTotal += 2*(yiguais[y]);
            yiguais[y]++;
            somaTotal += 2*(subiguais[x-y]);
            subiguais[x-y]++;
            somaTotal += 2*(somaiguais[x+y]);
            somaiguais[x+y]++;
        }
        cout << somaTotal << '\n';

    }

    return 0;
}
