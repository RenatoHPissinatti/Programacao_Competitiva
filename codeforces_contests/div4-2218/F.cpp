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

void bfs(vector<vector<int>>& adj) {

}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int pares, impares;
        cin >> pares >> impares;
        int n = pares + impares;
        if (n%2 == 0) {
            pares--;
        }
        else {
            impares--;
        }
        if (impares < pares || impares < 0 || pares < 0) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        int nextn = 2;
        for (; pares > 0; pares--) {
            cout << 1 << ' ' << nextn << '\n';
            cout << nextn << ' ';
            nextn++;
            cout << nextn << '\n';
            impares--;
            nextn++;
        }
        for (; impares > 0; impares--) {
            cout << 1 << ' ' << nextn << '\n';
            nextn++;
        }
    }
    return 0;
}
