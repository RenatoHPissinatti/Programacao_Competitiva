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
const ll MOD = 1000000007;

int main() {
    ll MAX_N = 1000000;
    fastio;
    int n;
    cin >> n;
    vector<int> a(n);
    int somatotal = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        somatotal+=a[i];
    }

    if (somatotal%2 == 1) {
        cout << -1 << '\n';
        return 0;
    }
    int metade = somatotal/2;
    vector<vector<bool>> dp(n+1, vector<bool>(metade+1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int soma = 0; soma <=metade; soma++) {
            if (dp[i-1][soma]) {
                dp[i][soma] = true;
            }
            if (soma >= a[i-1] && dp[i-1][soma - a[i-1]]) {
                dp [i][soma] = true;
            }
        }
    }

    if (!dp[n][metade]) {
        cout << -1 << '\n';
        return 0;
    }
    int soma = metade;
    vector<int> idxAlice;
    for (int i = n; i >= 1; i--) {
        if (!dp[i-1][soma]) {
            idxAlice.push_back(i-1);
            soma -= a[i-1];
        }
    }
    int idxA =0;
    reverse(all(idxAlice));
    vector<int> vecAlice;
    vector<int> vecBob;
    for (int i = 0; i < n; i++) {
        if (idxA < idxAlice.size() && i == idxAlice[idxA]) {
            vecAlice.push_back(a[i]);
            idxA++;
        }
        else {
            vecBob.push_back(a[i]);
        }
    }

    idxA = 0;
    int idxB = 0;
    int ka = 0;
    int kb = 0;
    vector<int> res;
    while (idxA < vecAlice.size() || idxB < vecBob.size()) {
        if (ka <= kb) {
            ka += vecAlice[idxA];
            res.push_back(vecAlice[idxA]);
            idxA++;
        }
        else {
            kb += vecBob[idxB];
            res.push_back(vecBob[idxB]);
            idxB++;
        }
    }

    for (int val : res) {
        cout << val << ' ' ;
    }
    cout << '\n';

    return 0;
}
