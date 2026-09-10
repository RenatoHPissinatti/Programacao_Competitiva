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

ll _sieve_size;
bitset<1000001> bs;
vector<ll> p; // compact list of primes
void sieve(ll upperbound) { // range = [0..upperbound]
    _sieve_size = upperbound+1; // to include upperbound
    bs.set(); // all 1s
    bs[0] = bs[1] = 0; // except index 0+1
    for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
        // cross out multiples of i starting from i*i
        for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
        p.push_back(i); // add prime i to the list
    }
}
bool isPrime(ll N) { // good enough prime test
    if (N < _sieve_size) return bs[N]; // O(1) for small primes
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        if (N%p[i] == 0)
            return false;
    return true; // slow if N = large prime
}

int numPF(ll N) {
    int ans = 0;
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i)
        while (N%p[i] == 0) { N /= p[i]; ++ans; }
    return ans + (N != 1);
}


int main() {
    ll MAX_N = 1000000;
    fastio;
    sieve(MAX_N);
    ll n;
    cin >> n;
    vector<ll> freqentrada(MAX_N+1, 0);
    vector<ll> entrada(n);
    for (int i = 0; i< n; i++) {
        int val;
        cin >> val;
        freqentrada[val]++;
        entrada[i] = val;
    }

    vector<bool> numdiffpfarr(MAX_N+1, false);
    vector<int> v(MAX_N+1, 0);
    for (int i = 2; i <= MAX_N; i++) {
        if (!numdiffpfarr[i]) {
            for (ll j = i; j <= MAX_N; j+=i) {
                numdiffpfarr[j] = true;
                if (freqentrada[j]>= 1) {
                    v[i] += freqentrada[j];
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
                v[j] += v[i];
            }
        }
    }

    vector<ll> qntm(MAX_N+1, 0);
    for (ll val = 1; val <= MAX_N; val++) {
        for (ll i = val; i <= MAX_N; i+=val) {
                qntm[val] += freqentrada[i];
        }
    }

    int q;
    cin >> q;


    for (int i1 = 0; i1 < q; i1++) {
        ll res = 1;
        ll qi;

        cin >> qi;
        ll fora = v[qi];
        ll N = qi;
        vector<ll> primos;

        for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i) {
            if (N%p[i] == 0) {
                primos.push_back(p[i]);
            }
            while (N%p[i] == 0) {
                N /= p[i];
            }
        }
        if (N != 1) {
            primos.push_back(N);
        }

        int tamprimos = primos.size();
        if (tamprimos > 1) {
            ll final = (1ll << (tamprimos)) - 1ll;
            int maxbit = primos.size();
            for (int bm = 1ll; bm <= final; bm++) {
                int bitsvisto = 0;
                ll number = 1;
                for (int bit = 0; bit < maxbit; bit++) {
                    if (((1 << bit) & bm) != 0) {
                        bitsvisto++;
                        number *= primos[bit];
                    }
                }
                if (bitsvisto > 1) {
                    if (bitsvisto%2 == 0) {
                        fora -= qntm[number];
                    }
                    else {
                        fora += qntm[number];
                    }
                }
            }
        }


        ll exp = n-fora;

        res = binpow(2, exp);
        cout << res << '\n';
    }

    return 0;
}
