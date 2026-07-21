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
        int n;
        cin >> n;
        unordered_map<int,ll> freqnums;
        map<int,ll> freqprimos;
        set<int> entrada;
        map<int, int> freqEntrada;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (num > n) continue;
            freqEntrada[num]++;
            entrada.insert(num);
        }
        for (int num : entrada) {
            int j = 1;
            while (num*j <= n) {
                freqnums[num*j]+= freqEntrada[num];
                j++;
            }
        }
        ll maior = 0;
        for (auto &[num, freq] : freqnums) {
            maior = max(freq, maior);
        }
        cout << maior << '\n';
    }

    return 0;
}
