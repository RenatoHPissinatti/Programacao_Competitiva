//
// Created by Usuario on 06/07/2026.
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

map<string, vector<string>> AL;
map<string, int> in_degree;
map<string, int> input_index;

priority_queue<
    pair<int, string>,
    vector<pair<int, string>>,
    greater<pair<int, string>>
    > pq;

int n;

vector<string> ans;

void kahn_algorithm() {
    for (auto v : input_index) {
        string drink = v.first;
        if (in_degree[drink] == 0)
            pq.push({input_index[drink], drink});
    }

    while (!pq.empty()) {
        string u = pq.top().second;
        pq.pop();
        ans.push_back(u);
        for (auto v : AL[u]) {
            --in_degree[v];
            if (in_degree[v] == 0)
                pq.push({input_index[v], v});
        }
    }
}


int main() {
    int t = 1;

    while (cin >> n) {
        AL.clear();
        in_degree.clear();
        input_index.clear();
        while (!pq.empty()) pq.pop();
        ans.clear();

        for (int i = 0; i < n; ++i) {
            string drink; cin >> drink;
            input_index[drink] = i;
        }
        int m; cin >> m;
        for (int i = 0; i < m; ++i) {
            string a,b;
            cin >> a >> b;
            AL[a].push_back(b);
        }

        for (auto u : input_index) {
            string cur = u.first;
            for (auto v : AL[cur]) {
                ++in_degree[v];
            }
        }

        kahn_algorithm();

        cout << "Case #" << t++ << ": Dilbert should drink beverages in this order:";
        for (auto v : ans) cout << " " << v;
        cout << ".\n\n";
    }
    return 0;
}
