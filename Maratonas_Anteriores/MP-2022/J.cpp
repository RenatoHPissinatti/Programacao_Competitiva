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

int pontcarta(int c) {
    if (c >= 11) {
        return 10;
    }
    return c;
}

int main() {
    fastio;
    int n ;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int somajoao = 0;
    int somamaria = 0;
    map<int, int> cartas;
    for (int i = 1; i <= 9; i++) {
        cartas[i] = 4;
    }

    cartas[10] = 16;
    cartas[a]--;
    cartas[b]--;
    somajoao += pontcarta(a) + pontcarta(b);
    cin >> a >> b;
    cartas[a]--;
    cartas[b]--;
    somamaria += pontcarta(a) + pontcarta(b);
    for (int i = 0; i < n ; i++) {
        cin >> a;
        cartas[a]--;
        somajoao+=pontcarta(a);
        somamaria+=pontcarta(a);
    }
    int res = -1;

    for (int i = 1; i <= 10; i++) {
        int tempsm = somamaria + i;
        int tempsj = somajoao + i;
        if (tempsm <= 23 && cartas[i] >= 1) {
            if (tempsj > 23 || tempsm == 23) {
                res = i;
                break;
            }
        }
    }
    cout << res <<'\n';
    return 0;
}
