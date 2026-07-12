//
// Created by Usuario on 12/07/2026.
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

class UnionFind {
private:
    vector<int> p, rank, setSize;
    int numSets;
public:
    UnionFind (int n) {
        p.assign(n, 0); for (int i = 0; i < n; ++i) p[i] = i;
        rank.assign(n,0);
        setSize.assign(n, 1);
        numSets = n;
    }

    int findSet (int i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }
    bool isSameSet (int i, int j) { return (findSet(i) == findSet(j)); }

    void unionSet (int i, int j) {
        if (isSameSet (i, j)) return;

        int x = findSet(i);
        int y = findSet(j);
        if (rank[x] > rank[y]) swap (x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];

    }
};

int main() {
    fastio;
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<tuple<int, int, int>> EL(m);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            EL[i] = {w, u, v};
        }

        sort(EL.begin(), EL.end());
        UnionFind UF(n);

        vector<int> heaviest;
        for (auto [w, u, v] : EL) {
            if (UF.isSameSet(u, v)) {
                heaviest.push_back(w);
            }
            UF.unionSet(u, v);
        }

        if (!heaviest.empty()) {
            for (int i = 0; i < heaviest.size(); ++i) {
                if (i == 0) cout << heaviest[i];
                else cout << " " << heaviest[i];
            }
        } else cout << "forest";
        cout << '\n';
    }

    return 0;
}
