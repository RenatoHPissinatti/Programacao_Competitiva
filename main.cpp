#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

const int INF = 1e9;
const ll LINF = LLONG_MAX/4;
const int MOD = 1000000007;
ll n, k;
vector<ll> a;

bool ok (ll mid, ll k_case) {
    bool find = false;
    for (ll i = n - 1ll; i >= 0ll; --i) {
        if (!find) {
            if (mid - a[i] <= 0ll) continue;
            find = true;
        }

        if (!(k_case >= mid - a[i])) return false;

        k_case = max(0ll, k_case-1ll);
    }
    return true;
}

int main() {
    fastio;
    cin >> n >> k;
    a.resize(n);
    ll lo = LINF, hi = 0ll;
    for (ll &i : a) {
        cin >> i;
        if (i < lo) lo = i;
        if (i > hi) hi = i;
    }

    hi += k;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1ll)/2ll;
        if (ok(mid, k)) lo = mid;
        else hi = mid - 1ll;
    }
    cout << lo << '\n';

    return 0;
}
