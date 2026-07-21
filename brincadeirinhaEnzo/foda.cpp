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
    ll epochs = 30000000;
    vector<ll> freqPremio(400, 0);
    random_device rd;
    mt19937 gen(rd());
    for (ll i = 0; i < epochs; i++) {
        unordered_map<int,bool> diasPassados;
        ll posi = 1;
        while (true) {
            uniform_int_distribution<int> distrib(1, 365);
            int numero_sorteado = distrib(gen);
            if (diasPassados[numero_sorteado]) {
                freqPremio[posi]++;
                break;
            }
            diasPassados[numero_sorteado] = true;
            posi++;
        }
    }

    for (int i = 0; i < 100; i++) {
        cout << i << ": " <<  freqPremio[i] << endl;
    }
    return 0;
}
