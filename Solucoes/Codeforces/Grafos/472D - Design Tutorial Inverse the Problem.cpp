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

vector<vector<pair<int,int>>> AL;

class UnionFind {
private:
    vector<int> p, rank;
public:
    UnionFind(int n) {
        p.assign(n, 0); for (int i = 0; i < n; ++i) p[i] = i;
        rank.assign(n, 0);
    }
    int findSet(int i) { return p[i] == i ? i : (p[i] = findSet(p[i]));}
    bool isSameSet(int i, int j) {return findSet(i) == findSet(j); }
    void UnionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
    }
};

class LCA {
private:
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
public:
    LCA(int n, int root) {
        height.resize(n);
        euler.reserve(2*n);
        first.resize(n);
        visited.assign(n, false);
        dfs(root);
        int m = euler.size();
        segtree.resize(m*4);
        build(1, 0, m-1);
    }

    void dfs(int u, int h = 0) {
        visited[u] = true;
        height[u] = h;
        first[u] = euler.size();
        euler.push_back(u);
        for (auto v : AL[u]) {
            if (!visited[v.first]) {
                dfs(v.first, h + v.second);
                euler.push_back(u);
            }
        }
    }
    void build(int u, int b, int e) {
        if (b == e) segtree[u] = euler[b];
        else {
            int mid = (b+e)/2;
            build(u << 1, b, mid);
            build(u << 1 | 1, mid + 1, e);
            int l = segtree[u << 1], r = segtree[u << 1 | 1];
            segtree[u] = min(height[l], height[r]);
        }
    }

    int query(int u, int b, int e, int L, int R) {
        if (b > R || e < L) return -1;
        if (b >= L && e <= R) return segtree[u];

        int mid = (b+e)/2;
        int l = query(u << 1, b, mid, L, R);
        int r = query(u << 1 | 1, mid + 1, e, L, R);
        if (l == -1) return segtree[r];
        if (r == -1) return segtree[l];

        return min(height[l], height[r]);
    }

    int lca(int u, int v) {
        int l = first[u], r = first[v];
        if (l > r) swap(l, r);
        return query(1, 0, euler.size() - 1, l, r);
    }

    int dist (int u, int v) {
        return height[u] + height[v] - 2*height[lca(u, v)];
    }
};

int main() {
    fastio;
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int> (n));
    vector<tuple<int,int,int>> EL;
    bool no_answer = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            if (i == j) {
                if (x != 0) {
                    no_answer = true;
                    break;
                }
            } else {
                grid[i][j] = x;
                EL.emplace_back(x, i, j);

            }
        }
        if (no_answer) break;
    }

    sort(EL.begin(), EL.end());
    UnionFind UF(n);
    int num_taken = 0;
    AL.assign(n, vector<pair<int,int>>());
    for (auto &[w, u, v] : EL) {
        if (UF.isSameSet(u, v)) continue;
        AL[u].emplace_back(v, w);
        UF.UnionSet(u, v);
        ++num_taken;
        if (num_taken == n - 1) break;
    }

    LCA lca(n, 0);
    for (int u = 0; u < n; ++u) {
        for (auto v : AL[u]) {
            if (lca.dist(u, v.first) != grid[u][v.first]) no_answer = true;
        }
    }

    if (no_answer) cout << "NO";
    else cout << "YES";
    return 0;
}
