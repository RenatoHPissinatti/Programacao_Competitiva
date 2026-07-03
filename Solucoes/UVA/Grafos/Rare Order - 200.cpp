//
// Created by Usuario on 03/07/2026.
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

map<char, vector<char>> AL;
deque<char> ans;
map<char, int> visited;
void toposort (char u) {
    visited[u] = VISITED;
    for (char v : AL[u]) {
        if (visited[v] == UNVISITED) {
            toposort(v);
        }
    }
    ans.push_front(u);
}

int main() {
    vector<string> pool;
    string word;
    while (cin >> word && word != "#") {
        pool.push_back(word);
        for (char c : word) {
            if (!visited[c]) {
                visited[c] = UNVISITED;
            }
        }
    }

    for (int i = 0; i + 1 < pool.size(); ++i) {
        string a = pool[i];
        string b = pool[i+1];

        size_t idx = 0;
        size_t limit = min(a.length(), b.length());
        while (idx < limit && a[idx] == b[idx]) ++idx;

        if (idx < limit) AL[a[idx]].push_back(b[idx]);
    }

    for (auto it : visited) {
        char u = it.first;
        if (visited[u] == UNVISITED) {
            toposort(u);
        }
    }

    for (char c : ans) cout << c;
    cout << '\n';

    return 0;
}
