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
        vector<string> matriz(n);
        for (int i = 0; i < n;i++) {
            cin >> matriz[i];
        }
        vector<pair<int, int>> pontos;
        for (int i = 0; i < n; i++) {
            string s = matriz[i];
            for (int j = 0; j < n; j++) {
                char c = s[j];
                if (c == '*') {
                    pontos.emplace_back(i, j);
                }
            }
        }
        auto &[i1, j1] = pontos[0];
        auto &[i2, j2] = pontos[1];
        int resi1, resi2, resj1, resj2;
        if (i1 == i2) {
            resi1 = i1;
            resi2 = i2;
            resj1 = j1;
            resj2 = j2;
            if (i1 > 0) {
                resi1--;
                resi2--;
            }
            else {
                resi1++;
                resi2++;
            }
        }
        else {
            if (j1 == j2) { // 0, 1; 1, 1
                resi1 = i1; // 0
                resi2 = i2; // 1
                resj1 = j1;
                resj2 = j2;
                if (j1 > 0) {
                    resj1--;
                    resj2--;
                }
                else {
                    resj1++;
                    resj2++;
                }
            }
            else {
                resi1 = i1;
                resj1 = j2;
                resi2 = i2;
                resj2 = j1;
            }
        }
        matriz[resi1][resj1] = '*';
        matriz[resi2][resj2] = '*';
        for (string s : matriz) {
            cout << s << '\n';
        }
    }

    return 0;
}
