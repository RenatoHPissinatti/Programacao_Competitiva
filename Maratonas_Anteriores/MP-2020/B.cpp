//
// Created by Usuario on 06/08/2026.
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

int main() {
    fastio;
    int n; cin >> n;
    vector<vector<bool>> grid(10, vector<bool>(10, false));
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        int d, l, r, c;
        cin >> d >> l >> r >> c;
        --c; --r;
        if (d == 0) {
            for (int j = c; j < c + l; ++j) {
                if (j >= 10) {
                    ans = false;
                    break;
                }
                if (grid[r][j] == true) {
                    ans = false;
                    break;
                }
                grid[r][j] = true;
            }
        } else {
            for (int j = r; j < r + l; ++j) {
                if (j >= 10) {
                    ans = false;
                    break;
                }
                if (grid[j][c] == true) {
                    ans = false;
                    break;
                }
                grid[j][c] = true;
            }
        }

        if (!ans) break;
    }

    if (ans) cout << 'Y';
    else cout << 'N';

    return 0;
}