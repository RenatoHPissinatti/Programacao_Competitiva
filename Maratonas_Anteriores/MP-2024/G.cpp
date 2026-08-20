
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

vector<int> L, name;
vector<vector<int>> AL;
vector<int> p;

void solve (int r) {
    int a = AL[r][0];
    int b = AL[r][1];
    L[r] = a + b;

    name[r] = (a >= b ? a : b);

    solve(p[r]);
}

int main() {
    fastio;
    int n; cin >> n;

    L.assign(n + n-1, 0);
    name.assign(n + n-1, 0);
    AL.assign(n + n-1, vector<int>());
    p.assign(n+ n-1, -1);

    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        L[i] = l;
    }

    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        AL[n + i].push_back(a);
        AL[n + i].push_back(b);
        L[n+i] = L[a] + L[b];
        p[a] = n + 1;
        p[b] = n + 1;
    }

    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int r, q;
        cin >> r >> q;
        L[r] += q;
        solve(p[r]);
        cout << name[n + n-1] << '\n';
    }

    return 0;
}
