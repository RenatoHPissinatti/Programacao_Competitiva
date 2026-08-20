//
// Created by Usuario on 20/08/2026.
//

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

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res*a)%MOD;
        }
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}
int main() {
    fastio;
    ll n;
    cin >> n;
    map<ll, ll> freqentrada;
    for (int i = 0; i< n; i++) {
        int val;
        cin >> val;
        freqentrada[val]++;
    }
    ll MAX_N = 1000000;
    vector<bool> numdiffpfarr(MAX_N+1, false);
    vector<int> v(MAX_N+1, 0);
    for (int i = 2; i < MAX_N; i++) {
        if (!numdiffpfarr[i]) {
            for (ll j = i; j <= MAX_N; j+=i) {
                numdiffpfarr[j] = true;
                if (freqentrada[j]>= 1) {
                    v[i] ++;
                }
            }
        }
    }
    vector<bool> numdiffpfarr2(MAX_N+1, false);
    for (ll i = 2; i <= MAX_N; i++) {
        if (!numdiffpfarr2[i]) {
            numdiffpfarr2[i] = true;
            for (ll j = i+i; j <= MAX_N; j+=i) {
                numdiffpfarr2[j] = true;
                if (v[j] > 0 && v[i] > 0) {
                    v[j]--;
                }
                v[j] += v[i];

            }
        }
    }

    int q;
    cin >> q;


    for (int i = 0; i < q; i++) {
        ll res = 1;
        ll qi;
        cin >> qi;
        ll fora = v[qi];
        ll exp = n-fora;
        if (freqentrada[1] == 0) {
            exp++;
        }
        res = binpow(2, exp);
        cout << res << '\n';
    }

    return 0;
}
