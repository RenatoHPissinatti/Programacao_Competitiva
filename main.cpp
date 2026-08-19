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
vector<int> likes;
vector<int> ans;

void dfs(int u, int l, int qtd_likes) {

    for (int v : AL[u]) {
        if (likes[v] > l) {
            ans[v] = qtd_likes + 1;
            dfs(v, likes[v], qtd_likes + 1);
        } else {
            ans[v] = qtd_likes;
            dfs(v, min(likes[u], likes[v]), qtd_likes);
        }
    }
}

int main() {
    fastio;
    int n; cin >> n;
    vector<int> p(n+1, 0);
    AL.assign(n+1, vector<int>());
    for (int i = 2; i <= n; ++i) {
        int pai; cin >> pai;
        p[i] = pai;
        AL[pai].push_back(i);
    }
    likes.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        int like; cin >> like;
        likes[i] = like;
    }
    ans.assign(n+1, 1);
    dfs(1, likes[1], 1);

    for (int i = 2; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
