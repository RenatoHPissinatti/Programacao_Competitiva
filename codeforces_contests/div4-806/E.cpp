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
    string s;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matriz(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) {
                if (s[j] == '1') {
                    matriz[i][j] = 1;
                }
                else {
                    matriz[i][j] = 0;
                }
            }
        }
        ll count = 0;
        int nivel = 0;
        for (int tam = n; tam > 1; tam-=2, nivel++) {
            for (int idx = 0; idx < tam; idx++) {
                int i, j, i2, j2, i3, j3, i4, j4;
                i = 0; j = idx;
                i2 = j; j2 = tam-1;
                i3 = tam-1; j3 = tam-1-j;
                i4 = tam-1-j; j4 = i;
                i+=nivel; j+=nivel;
                i2+=nivel; j2+=nivel;
                i3+=nivel; j3+=nivel;
                i4+=nivel; j4+=nivel;
                int zeros = 0;
                int ums = 0;
                if (matriz[i][j] == 0) {
                    zeros++;
                }
                else {
                    ums++;
                }
                if (matriz[i2][j2] == 0) {
                    zeros++;
                }
                else {
                    ums++;
                }
                if (matriz[i3][j3] == 0) {
                    zeros++;
                }
                else {
                    ums++;
                }
                if (matriz[i4][j4] == 0) {
                    zeros++;
                }
                else {
                    ums++;
                }
                if (zeros > ums) {
                    count += ums;
                    matriz[i][j] = 0;
                    matriz[i2][j2] = 0;
                    matriz[i3][j3] = 0;
                    matriz[i4][j4] = 0;
                }
                else {
                    count += zeros;
                    matriz[i][j] = 1;
                    matriz[i2][j2] = 1;
                    matriz[i3][j3] = 1;
                    matriz[i4][j4] = 1;
                }
            }
        }
        cout << count << '\n';
    }


    return 0;
}
