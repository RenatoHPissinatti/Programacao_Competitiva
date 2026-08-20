//
// Created by Usuario on 20/08/2026.
//
//
// Created by Usuario on 18/08/2026.
//
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
vector<int> p;
vector<int> A;

vector<int> L, L_id;

vector<int> likes;
int ans;
void print_u (int u) {
    ++ans;
    if (p[u] == -1) { return; }
    print_u(p[u]);
}

void solve (int u, int k) {

    auto pos = lower_bound(L.begin(), L.begin() + k, A[u]) - L.begin();

    int old_val = L[pos];
    int old_L_id = L_id[pos];
    int old_p = p[u];

    L[pos] = A[u];
    L_id[pos] = u;
    p[u] = pos ? L_id[pos-1] : -1;
    if (pos == k) k = (int)pos + 1;

    for (int v : AL[u]) {
        solve(v, k);
    }
    ans = 0;
    print_u(u);
    likes[u] = ans;

    L[pos] = old_val;
    L_id[pos] = old_L_id;
    p[u] = old_p;
}

int main() {
    fastio;
    int n; cin >> n;
    AL.assign(n+1, vector<int>());
    p.assign(n+1, -1);
    A.resize(n+1);
    A[0] = INF;
    for (int i = 2; i <= n; ++i) {
        int v; cin >> v;
        AL[v].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        int like; cin >> like;
        A[i] = like;
    }

    L.assign(n, 0);
    L_id.assign(n, 0);
    likes.assign(n+1, 1);

    solve(1, 0);

    for (int i = 2; i <= n; ++i) cout << likes[i] << " ";
    cout << '\n';

    return 0;
}
