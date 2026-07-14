//
// Created by Usuario on 13/07/2026.
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

const int UNVISITED = -1;
const int VISITED = 1;

vector<tuple<int, int, int>> EL;
vector<vector<pair<int,int>>> AL;
vector<int> dfs_num;

class UnionFind {
private:
    vector<int> p, rank, setSize;
    int numSets;
public:
    UnionFind (int n) {
        p.assign(n, 0);
        for (int i = 0; i < n; ++i) p[i] = i;
        rank.assign(n, 0);
        setSize.assign(n, 1);
        numSets = n;
    }

    int findSet(int i) { return (p[i] == i ? i : (p[i] = findSet(p[i]))); }
    bool isSameSet (int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;

        int x = findSet(i);
        int y = findSet(j);
        if (x > y) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        rank[y] += rank[x];
    }
};

int path(int u, int target, int maxEdge) {
    if (u == target) return maxEdge;
    dfs_num[u] = VISITED;
    for (auto &[v, w] : AL[u]) {
        if (dfs_num[v] == UNVISITED) {
            int result = path(v, target, max(w, maxEdge));

            if (result != -1) return result;
        }
    }

    return -1;
}

int main() {
    fastio;
    int c, s, q;
    int testCase = 1;
    bool firstCase = true;
    while (cin >> c >> s >> q && (c != 0 || s != 0 || q != 0)) {
        if (!firstCase) cout << '\n';

        EL.assign(s, {0,0,0});
        AL.assign(c, vector<pair<int,int>>());

        for (int i = 0; i < s; ++i) {
            int c1, c2, d;
            cin >> c1 >> c2 >> d;
            --c1; --c2;
            EL[i] = {d, c1, c2};
        }

        sort(EL.begin(), EL.end());

        UnionFind UF(c);
        int num_taken = 0;
        for (int i = 0; i < s; ++i) {
            auto [w, u, v] = EL[i];
            if (UF.isSameSet(u, v)) continue;

            UF.unionSet(u, v);
            ++num_taken;
            AL[u].emplace_back(v, w);
            AL[v].emplace_back(u, w);
            if (num_taken == c - 1) break;
        }
        cout << "Case #" << testCase << '\n';
        for (int i = 0; i < q; ++i) {
            dfs_num.assign(c, UNVISITED);
            int c1, c2;
            cin >> c1 >> c2;
            --c1; --c2;
            int ans = path(c1,c2, -1);
            if (ans == -1) cout << "no path\n";
            else cout << ans << '\n';
        }

        ++testCase;
        firstCase = false;
    }
    return 0;
}