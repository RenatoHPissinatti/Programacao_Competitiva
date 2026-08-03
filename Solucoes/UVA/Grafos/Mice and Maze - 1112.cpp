//
// Created by Usuario on 03/08/2026.
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

vector<vector<pair<int,int>>> AL;


int main() {
    fastio;
    int t; cin >> t;
    bool first = true;
    while (t--) {

        int n, e, T, m;
        cin >> n >> e >> T >> m;
        AL.assign(n+1, vector<pair<int,int>>());

        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            AL[a].emplace_back(b,c);
        }
        int ans = 0;
        for (int s = 1; s <= n; ++s) {
            if (s == e) {
                ++ans;
                continue;
            }
            vector<int> dist(n+1, INF); dist[s] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.emplace(0,s);

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
            if (dist[e] <= T) ++ans;
        }
        if (!first) cout << '\n';
        cout << ans << '\n';

        first = false;
    }

}