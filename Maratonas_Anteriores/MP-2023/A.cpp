//
// Created by Usuario on 18/08/2026.
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

vector<vector<pair<int,int>>> AL;

int main() {
    fastio;
    int n, h;
    cin >> n >> h;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val <= h) {
            count++;
        }
    }
    cout << count << '\n';

    return 0;
}
