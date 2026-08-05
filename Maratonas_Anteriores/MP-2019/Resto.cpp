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

int main() {
    fastio;
    int n, m, b, p;
    while (cin >> n >> m >> b >> p) {
        vector<vector<pair<int, int>>> AL(n);
        for (int i = 0; i < m; ++i) {
            int u, v, t;
            cin >> u >> v >> t;
            AL[u].emplace_back(v, t);
        }
        vector<int> banks(b);
        for (int &i : banks) cin >> i;
        vector<int> policies(p);
        for (int &i : policies) cin >> i;

        for (auto policy : policies) {

            int qtd_bank = 0;
            bool not_found = false;
            int min_dist = INF;

            int s = policy;
            priority_queue<pii, vii, greater<pii>> pq;
            pq.emplace(0, s);
            vi dist(n, INF); dist[s] = 0;

            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                for (auto &[v, w] : AL[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.emplace(dist[v], v);
                    }
                }
            }

            for (auto bank : banks) {
                if (dist[bank] != INF) {
                    ++qtd_bank;
                } else {
                    not_found = true;
                }
                min_dist = min(min_dist, dist[bank]);
            }
            cout << qtd_bank << " ";
            if (not_found) {
                cout << "*" << '\n';
            } else cout << min_dist << '\n';
            
            for (auto bank : banks) {
                if (dist[bank] == min_dist) {
                    cout << bank << " ";
                }
            }
        }

    }

}