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

    int t;
    cin >> t;
    while (t--) {
        int p, q;
        cin >> p >> q;


        for (int i = 1; i < 1e8; i++) {
            int tetos = q;
            int colunas = q;
            int remendos = p;
            int precisatetos = i;
            int precisacolunas = i+1;
            int altura = colunas/precisacolunas;
            int sobraAltura = colunas%precisacolunas;
            if (sobraAltura > 0) {
                if (remendos >= (precisacolunas - sobraAltura)) {
                    altura++;
                    remendos -= (precisacolunas - sobraAltura);
                }
                else {
                    continue;
                }
            }
            int sobratetos = 0;
            int tetosfeitos = (altura + 1)*precisatetos;
            if (tetosfeitos > tetos) {
                if (remendos >= tetosfeitos - tetos) {
                    remendos -= (tetosfeitos - tetos);
                }
            }
            else {
                if (tetosfeitos < tetos) {
                    sobratetos = tetos - tetosfeitos;
                    int faltamcolunas = (sobratetos/i);
                }
            }
        }
    }

    return 0;
}
