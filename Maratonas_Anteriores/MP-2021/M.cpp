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

vector<vector<int>> AL;
vector<bool> vivo;
int son = 2;
int n;
bool first = true;
void hierarchy(int king) {
    if (vivo[king] == false) {
        for (int v : AL[king]) {
            hierarchy(v);
        }
        return;
    }
    if (!first && n >= 0) cout << king << '\n';
    first = false;
    while (n-- > 0) {
        int op, u;
        cin >> op >> u;
        if (op == 1) {
            AL[u].push_back(son);
            ++son;
        } else {
            vivo[u] = false;
            if (u == king) {
                for (int v : AL[king]) {
                        hierarchy(v);
                }
                return;
            }
            cout << king << '\n';
        }
    }
}



int main() {
    fastio;
    cin >> n;
    AL.assign(n+2, vector<int>());
    vivo.assign(n+2, true);
    hierarchy(1);

    return 0;
}
