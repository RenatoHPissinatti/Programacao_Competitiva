//
// Created by Usuario on 20/07/2026.
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

class UnionFind {
private:
    vector<int> p, rank, setSize;
    vector<vector<int>> elements; // Guarda as ilhas de cada componente
public:
    UnionFind (int n) {
        p.assign(n, 0);
        rank.assign(n,0);
        setSize.assign(n,1);
        elements.assign(n, vector<int>());
        for(int i = 0; i < n; ++i) {
            p[i] = i;
            elements[i].push_back(i);
        }
    }

    int findSet (int i) { return p[i] == i ? i : p[i] = findSet(p[i]); }
    bool isSameSet (int i, int j) {return findSet(i) == findSet(j); }

    void unionSet(int i, int j, double w, vector<double>& minimax_to_0) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);

        // Se um dos grupos tem a capital e o outro não, o gargalo do outro grupo é definido
        int root0 = findSet(0);
        if (x == root0 || y == root0) {
            int other = (root0 == x) ? y : x;
            for (int node : elements[other]) {
                minimax_to_0[node] = w; // A maior aresta para o caminho desse grupo
            }
        }

        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        for (int node : elements[x]) {
            elements[y].push_back(node);
        }
        elements[x].clear();
    }

};

int main() {
    fastio;
    int n;
    int testCase = 1;
    while (cin >> n && n != 0) {
        vector<tuple<int,int,int>> islands(n);
        map<pair<int,int>,pair<int,int>> island_map;
        vector<tuple<double,int,int>> EL;
        for (int i = 0; i < n; ++i) {
            int x, y, m;
            cin >> x >> y >> m;
            islands[i] = {x,y,m};
            island_map[{x,y}] = {i, m};
            for (int j = i - 1; j >= 0; --j) {
                int dist_x, dist_y;
                dist_x = abs(get<0>(islands[j]) - get<0>(islands[i]));
                dist_y = abs(get<1>(islands[j]) - get<1>(islands[i]));
                double dist_t = sqrt(dist_x*dist_x + dist_y*dist_y);
                EL.emplace_back(dist_t, j, i);
            }
        }


        sort(EL.begin(), EL.end());
        int num_taken = 0;
        UnionFind UF(n);

        vector<double> minimax_to_0(n, 0.0);
        for (auto &[w, u, v] : EL) {
            if (UF.isSameSet(u, v)) continue;
            UF.unionSet(u, v, w, minimax_to_0);
            ++num_taken;
            if (num_taken == n - 1) break;
        }

        double total_cost = 0.0;
        double total_pop = 0.0;

        for (int i = 0; i < n; ++i) {
            double pop = get<2>(islands[i]);
            total_pop += pop;
            total_cost += minimax_to_0[i]*pop;
        }
        double avarage = total_cost/total_pop;

        cout << "Island Group: " << testCase++;
        cout << fixed << setprecision(2);
        cout << " Average " << avarage << '\n';
        cout << '\n';
    }

    return 0;
}