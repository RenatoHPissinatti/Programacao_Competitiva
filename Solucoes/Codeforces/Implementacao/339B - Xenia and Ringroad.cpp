//
// Created by Usuario on 15/09/2026.
//
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

const int INF = 1e9;
const ll LINF = LLONG_MAX/4;
const int MOD = 1000000007;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> tasks(m);
    for (int i = 0; i < m; ++i) {
        int task; cin >> task;
        tasks[i] = task;
    }
    ll steps = tasks[0] - 1;
    for (int i = 0; i < m - 1; ++i) {
        if (tasks[i+1] > tasks[i]) {
            steps += tasks[i+1] - tasks[i];
        } else if (tasks[i+1] < tasks[i]) {
            steps += (n - tasks[i]) + tasks[i+1];
        }
    }

    cout << steps << '\n';
    return 0;
}
