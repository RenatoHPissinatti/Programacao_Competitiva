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
    int n;
    cin >> n;
    int maior = 0;
    int bobo;
    cin >> bobo;
    maior = bobo;
    for (int i = 1; i < n; i++) {
        int val;
        cin >> val;
        maior = max(maior, val);
    }
    if (maior == bobo) {
        cout << 'S' << '\n';
    }
    else {
        cout << 'N' << '\n';
    }
    return 0;
}