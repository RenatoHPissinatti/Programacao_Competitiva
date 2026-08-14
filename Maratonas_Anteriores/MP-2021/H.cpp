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

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    map<int, multiset<int>> cores;
    vector<int> entradacores(n);
    for (int i = 0; i < n; i++) {
        int bloco, cor;
        cin >>  bloco >> cor;
        cores[cor].insert(bloco);
        entradacores[i] = cor;
    }
    vector<int> res(n);
    bool flag = true;
    for (int i = 0; i < n; i++) {
        res[i] = *cores[entradacores[i]].begin();
        cores[entradacores[i]].erase(cores[entradacores[i]].begin());
        if (i > 0 && res[i] < res[i-1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << 'Y';
    }
    else {
        cout << 'N';
    }
    cout << '\n';

    return 0;
}
