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
const double EPS = 1e-9;


void d(int number,vector<int>& possiveisRes) {
    for (int divisor = 1; divisor <= number; divisor++) {
        for (int multiplo = divisor;multiplo <= number;multiplo += divisor) {
            possiveisRes[multiplo] += divisor;
        }
    }

}



int main() {
    fastio;

    int t;
    cin >> t;
    queue<int> cs;
    int maior = 0;
    while (t--) {
        int c;
        cin >> c;
        cs.push(c);
        maior = max(maior, c);
    }
    vector<int> possiveisRes(maior+1, 0);
    unordered_map<int, int> res;
    d(maior, possiveisRes);
    for (int i = 1; i <= maior; i++) {
        if (res[possiveisRes[i]] == 0) {
            res[possiveisRes[i]] = i;
        }
    }
    while (!cs.empty()) {
        int c = cs.front();
        cs.pop();
        ll ans = -1;
        ans = res[c];
        if (ans == 0) {
            ans = -1;
        }

        cout << ans << '\n';
    }

    return 0;
}
