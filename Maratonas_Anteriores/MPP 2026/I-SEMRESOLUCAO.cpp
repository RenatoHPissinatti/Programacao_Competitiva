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
    cin >> s;
    int tam = s.size();

    // 119, 129, 139, 149, 159, 169, 179, 189, 199

    unordered_map<string, bool> possible;
    possible["119"] = true;
    possible["129"] = true;
    possible["139"] = true;
    possible["149"] = true;
    possible["159"] = true;
    possible["169"] = true;
    possible["179"] = true;
    possible["189"] = true;
    possible["199"] = true;

    int numfaltando = 11 - tam;
    if (numfaltando < 0) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < tam; i++) {

    }


    return 0;
}
