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

    int count = 0;
    vector<int>flechas(10e6+2, 0);
    for (int i = 0; i < n; i++) {
        int balao;
        cin >> balao;
        if (flechas[balao] >= 1) {
            flechas[balao]--;
        }
        else {
            count++;
        }
        if (balao - 1 > 0) {
            flechas[balao-1]++;
        }
    }

    cout << count << '\n';

    return 0;
}
