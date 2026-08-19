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

string codificastring(string s) {
    map<char, int> count;
    for (char c : s) {
        count[c]++;
    }
    string nova;
    for (auto [c, frq] : count) {
        nova += to_string(frq);
        nova += c;
    }
    return nova;
}
int main() {
    fastio;

    int n, m, p;
    cin >> n >> m;
    vector<string> quadro(n);
    for (int i = 0; i < n; i++) {
        cin >> quadro[i];
    }
    cin >> p;
    map<string, bool> palavras;

    for (int i = 0; i < p; i++) {
        string s;
        cin >> s;
        string codi = codificastring(s);
        palavras[codi] = true;
    }
    vector<vector<set<string>>> quadrores(n, vector<set<string>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string s;
            for (int it = i, jt = j; jt < m && jt >=0 && it < n && it >= 0; it++) { //para baixo
                s += quadro[it][jt];
                string scodi = codificastring(s);
                if (palavras[scodi]) {
                    for (int it2 = it; it2 >= i; it2--) {
                        quadrores[it2][jt].insert(scodi);
                    }
                }
            }
            s = "";
            for (int it = i, jt = j; jt < m && jt >=0 && it < n && it >= 0; jt++) { //para direita
                s += quadro[it][jt];
                string scodi = codificastring(s);
                if (palavras[scodi]) {
                    for (int jt2 = jt; jt2 >= j; jt2--) {
                        quadrores[it][jt2].insert(scodi);
                    }
                }
            }
            s = "";
            for (int it = i, jt = j; jt < m && jt >=0 && it < n && it >= 0; jt++, it--) { //para diagonal cima
                s += quadro[it][jt];
                string scodi = codificastring(s);
                if (palavras[scodi]) {
                    for (int jt2 = jt, it2 = it; jt2 >= j && it2 <= i; jt2--, it2++) {
                        quadrores[it2][jt2].insert(scodi);
                    }
                }
            }
            s = "";
            for (int it = i, jt = j; jt < m && jt >=0 && it < n && it >= 0; jt++, it++) { //para diagonal cima
                s += quadro[it][jt];
                string scodi = codificastring(s);
                if (palavras[scodi]) {
                    for (int jt2 = jt, it2 = it; jt2 >= j && it2 >= i; jt2--, it2--) {
                        quadrores[it2][jt2].insert(scodi);
                    }
                }
            }
        }
    }
    ll count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (quadrores[i][j].size() >= 2) {
                count++;
            }
        }
    }
    cout << count << '\n';

    return 0;
}