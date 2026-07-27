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

pair<int, int> bestgame(vector<vector<int>>tabuleiro, vector<int>& finalGames, bool j, vector<pair<int, int>>zeroPos) {
    pair<int,int> bestgameja = {0, 0};
    pair<int, int> tbg = {0, 0};
    bool flag = false;
    for (auto [zi, zj] : zeroPos) {
        pair<int, int> cima1 = {zi-2, zj-2};
        pair<int, int> cima2 = {zi-1, zj-1};
        pair<int, int> dir2 = {zi-2, zj+2};
        pair<int, int> dir1 = {zi-1, zj+1};
        pair<int, int> bxo2 = {zi+2, zj+2};
        pair<int, int> bxo1 = {zi+1, zj+1};
        pair<int, int> esq2 = {zi+2, zj-2};
        pair<int, int> esq1 = {zi+1, zj-1};
    }
    return bestgameja;
}

int main() {
    fastio;
    vector<vector<int>> tabuleiro(5, vector<int>(9, 0));
    int meio = 4;

    for (int i = 0; i < 5; i++) {
        int valorAgora = meio - i;
        for (int j = 0; j <= i; j++) {
            cin >> tabuleiro[i][valorAgora];
            valorAgora+=2;
        }
    }
    return 0;
}
