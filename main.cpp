#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

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

vi a;
int parity;
vi height;

const int or_op = 1;
const int xor_op = 0;

class SegmentTree {
private:
    int n;
    vi A, st, lazy;

    ll l(ll p) {return p << 1;}
    ll r(ll p) {return (p << 1) + 1;}

    int conquer (int a, int b, int op) {
        if (op == or_op) {
            return a | b;
        }
        return a ^ b;
    }

    void build(ll p, int L, int R, int h) {
        if (L == R) {
            st[p] = a[L];
            height[p] = 0;
        } else {
            int m = (L+R)/2;
            build(l(p), L, m, h+1);
            build(r(p), m + 1, R, h+1);

            height[p] = height[l(p)] + 1;
            if (height[p] % 2 == 1) {
                st[p] = conquer(st[l(p)], st[r(p)], or_op);
            } else st[p] = conquer(st[l(p)], st[r(p)], xor_op);

        }
    }

    void update(ll p, int L, int R,int i, int val) {
        if (L == R) {
            st[p] = val;
            return;
        }

        int m = (L+R)/2;
        if (i <= m) update(l(p), L, m, i, val);
        else update(r(p), m + 1, R, i, val);

        if (height[p] % 2 == 1) {
            st[p] = conquer(st[l(p)], st[r(p)], or_op);
        } else st[p] = conquer(st[l(p)], st[r(p)], xor_op);
    }

public:
    SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}

    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1, 0);
    }

    void update(int i, int val) {
        update(1, 0, n - 1, i, val);
    }

    int result() {
        return st[1];
    }

};


int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    parity = n % 2;

    a.resize(1<<n);
    height.resize(4*(1<<n));
    for (auto & i : a) cin >> i;

    SegmentTree st(a);
    for (int i = 0; i < m; ++i) {
        int p; int b;
        cin >> p >> b;
        --p;
        st.update(p, b);
        cout << st.result() << '\n';
    }

    return 0;
}