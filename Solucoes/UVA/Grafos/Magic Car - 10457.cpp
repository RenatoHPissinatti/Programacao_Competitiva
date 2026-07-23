//
// Created by Usuario on 22/07/2026.
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

int minEnergy;
int maxEnergy;
int totalEnergy;

class UnionFind {
private:
    vector<int> p, rank, setSize;
public:
    UnionFind (int n) {
        p.assign(n, 0);
        for (int i = 0; i < n; ++i) p[i] = i;
        rank.assign(n, 0);
        setSize.assign(n, 1);
    }

    int findSet (int i) {return (p[i] == i ? i : (p[i] = findSet(p[i]))); }
    int isSameSet (int i, int j) { return (findSet(i) == findSet(j));}

    void unionSet (int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
    }
};

int main() {
    //fastio;
    int n, m;
    while (cin >> n >> m) {
        vector<tuple<int,int,int>> EL(m);
        for (int i = 0; i < m; ++i) {
            int start, end, speed;
            cin >> start >> end >> speed;
            --start; --end;
            EL[i] = {speed, start, end};
        }

        sort(EL.begin(), EL.end());

        int startEnergy, endEnergy;
        cin >> startEnergy >> endEnergy;
        int k; cin >> k;

        int minVal = 0, maxVal = 0;
        for (int i = 0; i < k; ++i) {
            int s, d; cin >> s >> d;
            --s; --d;
            if (s == d) {
                cout << startEnergy + endEnergy << '\n';
                continue;
            }
            int ans = INF;
            for (int j = 0; j < m; ++j) {
                UnionFind UF(n);
                minVal = get<0>(EL[j]);
                for (int l = j; l < m; ++l) {
                    auto [w, u, v] = EL[l];

                    UF.unionSet(u, v);
                    maxVal = w;

                    if (UF.isSameSet(s, d)) {
                        ans = min(ans, maxVal - minVal);
                        break;
                    }
                }

            }
            cout << startEnergy + ans + endEnergy << '\n';
        }

    }
}