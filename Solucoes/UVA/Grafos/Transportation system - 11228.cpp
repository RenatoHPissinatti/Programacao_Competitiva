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
    size_t numSets;
public:
    UnionFind(size_t n) {
        p.assign(n, 0);
        for (int i = 0; i < n; ++i) p[i] = i;
        rank.assign(n,0);
        setSize.assign(n, 1);
        numSets = n;
    }

    int findSet (int i) { return (p[i] == i ? i : (p[i] = findSet(p[i]))); }
    bool isSameSet (int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (isSameSet(i,j)) return;
        int x = findSet(i);
        int y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        --numSets;
    }
};

int main() {
    fastio;
    int t; cin >> t;
    int testCase = 1;
    while (testCase <= t) {
        int n, r;
        cin >> n >> r;
        vector<tuple<double,int,int>> EL;
        vector<pair<int,int>> coordenates(n);
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            coordenates[i] = {x, y};
            for (int j = i - 1; j >= 0; j--) {
                int a = abs(coordenates[i].first - coordenates[j].first);
                int b = abs(coordenates[i].second - coordenates[j].second);
                double dist = sqrt(a*a + b*b);
                EL.emplace_back(dist, i, j);
            }
        }
        double roads = 0;
        double railroads = 0;
        int countries = 1;
        sort(EL.begin(), EL.end());
        UnionFind UF(n);
        for (auto &[w, u, v] : EL) {
            if (UF.isSameSet(u, v)) continue;

            if (w > r) {
                railroads += w;
                ++countries;
            }
            else roads += w;

            UF.unionSet(u, v);
        }
        cout << "Case #" << testCase << ": " << countries << " " << round(roads) << " " << round(railroads) << '\n';
        ++testCase;
    }

    return 0;
}