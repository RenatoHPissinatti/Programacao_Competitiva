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

vector<vector<int>> AL;
vector<bool> vivo;
vector<int> p;
bool has_found;
int rei_atual;

void novo_rei(int rei) {
    if (has_found) return;
    if (vivo[rei]) {
        has_found = true;
        rei_atual = rei;
        return;
    }

    for (int filho : AL[rei]) {
        if (vivo[filho]) {
            has_found = true;
            rei_atual = filho;
            return;
        }
        return novo_rei(filho);
    }
    for (int irmao : AL[p[rei]]) {
        if (vivo[irmao]) {
            has_found = true;
            rei_atual = irmao;
            return;
        }
    }
    return novo_rei(p[rei]);
}

int main() {
    fastio;
    int q; cin >> q;
    AL.assign(q+1, vector<int>());
    vivo.assign(q+1, true);
    p.assign(q+1, 0);

    int f = 2;
    rei_atual = 1;
    for (int i = 0; i < q; ++i) {
        int t, x; cin >> t >> x;
        if (t == 1) {
            AL[x].push_back(f);
            p[f] = x;
            ++f;
        } else {
            has_found = false;
            vivo[x] = false;
            novo_rei(rei_atual);
            cout << rei_atual << '\n';
        }
    }
    return 0;
}
