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
    int n, c;
    cin >> n >> c;
    map<string, int> palavras;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int idx = -1;
        for (int j = 0; j < c; j++) {
            if (s[j] == '*') {
                idx = j;
            }
        }
        for (int posialfa = 0; posialfa < 26; posialfa++) {
            string novastr = s;
            char letra = 'a' + posialfa;
            novastr[idx] = letra;
            palavras[novastr]++;
        }
    }
    string res;
    int maiorfreq = 0;
    for (auto& [str, freq] : palavras) {
        if (freq == maiorfreq && str < res || freq > maiorfreq) {
            res = str;
            maiorfreq = freq;
        }
    }

    cout << res << ' ' << maiorfreq << '\n';

    return 0;
}
