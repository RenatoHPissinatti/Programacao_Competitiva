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
        unordered_set<int> primosdivisores;
        int temp = n;
        int divisor = 2;
        while (temp > 1 && divisor <= n) {
            while (temp%divisor == 0) {
                primosdivisores.insert(divisor);
                temp /= divisor;
            }
            if (divisor == 2) {
                divisor++;
            }
            else {
                divisor+=2;
            }

        }
        unordered_set<int> setAtual;
        setAtual.insert(n);
        int res = 0;
        while (!setAtual.empty()) {
            res++;
            unordered_set<int> novoSet;
            for (int val : setAtual) {
                for (int div : primosdivisores) {
                    if (val%div == 0) {
                        int conta = val/div;
                        if (primosdivisores.find(conta) == primosdivisores.end() && conta != 1) novoSet.insert(conta);
                    }
                }
            }
            setAtual.swap(novoSet);
        }

        if (primosdivisores.find(n) == primosdivisores.end()) {
            res += primosdivisores.size();
        }
        cout << res << '\n';
    }

    return 0;
}
