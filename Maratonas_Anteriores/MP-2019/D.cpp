//
// Created by Usuario on 04/08/2026.
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

vector<bool> inJail;
map<int, int> p;
vector<int> qtd;
vector<int> jails;
vector<vector<int>> AL;

void dfsSub() {
    while (!jails.empty()) {
        int u = jails.back();
        jails.pop_back();

        deque<int> q;
        q.push_back(u);
        while (!q.empty()) {
            int cur = q.front();
            q.pop_front();
            for (auto v : AL[cur]) {
                --qtd[v];
                q.push_back(v);
            }
        }

    }
}

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    qtd.assign(n+1, 0);
    inJail.assign(n+1, false);
    AL.assign(n+1, vector<int>());

    for (int i = 2; i <= n; ++i) {
        int pai; cin >> pai;
        p[i] = pai;
        qtd[i] = qtd[p[i]] + 1;
        AL[pai].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < k; ++i) {
        // pegar o máximo valor
        int maxVal = 0;
        int idxMaxVal = 1;
        for (int j = 1; j <= n; ++j) {
            if (!inJail[j]) {
                if (qtd[j] > maxVal) {
                    maxVal = qtd[j];
                    idxMaxVal = j;
                }
            }
        }
        ans += maxVal;
        jails.clear();
        while (idxMaxVal != 1) {
            if (inJail[idxMaxVal] == true) break;
            inJail[idxMaxVal] = true;
            qtd[idxMaxVal] = 0;
            jails.push_back(idxMaxVal);
            idxMaxVal = p[idxMaxVal];
        }

        dfsSub();
    }

    cout << ++ans << '\n';

    return 0;

}