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


struct pessoa {
    int posi;
    int l, r;
    int id;
    pessoa(int _posi, int _l, int _r, int _id) {
        id = _id;
        posi = _posi;
        l = _l + 1;
        r = _r + _l;
    }
    bool operator < (const pessoa& other) const {
        return posi > other.posi;
    }
};




struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int _n) : n(_n), bit(n + 1, 0) {}

    // a deve estar indexado de 1 até n.
    Fenwick(const vector<long long>& a) {
        n = (int)a.size() - 1;
        bit = a;

        // Construção O(n)
        for (int i = 1; i <= n; i++) {
            int pai = i + (i & -i);

            if (pai <= n) {
                bit[pai] += bit[i];
            }
        }
    }

    // a[i] += delta
    void add(int i, long long delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    // a[1] + ... + a[i]
    long long prefixSum(int i) const {
        long long sum = 0;

        for (; i > 0; i -= i & -i) {
            sum += bit[i];
        }

        return sum;
    }

    // a[l] + ... + a[r]
    long long rangeSum(int l, int r) const {
        if (l > r) return 0;
        return prefixSum(r) - prefixSum(l - 1);
    }

    long long get(int i) const {
        return rangeSum(i, i);
    }

    // Menor posição pos tal que prefixSum(pos) >= k.
    // Exige frequências não negativas.
    int kth(long long k) const {
        if (k <= 0 || k > prefixSum(n)) {
            return n + 1;
        }

        int pos = 0;
        long long accumulated = 0;

        int jump = 1;
        while ((jump << 1) <= n) {
            jump <<= 1;
        }

        for (; jump > 0; jump >>= 1) {
            int next = pos + jump;

            if (next <= n &&
                accumulated + bit[next] < k) {
                pos = next;
                accumulated += bit[next];
                }
        }

        return pos + 1;
    }
};

int main() {
    fastio;
    int y, p;
    cin >> y >> p;
    vector<pair<int, int>> anos(y+1);
    for (int i = 1; i <= y; i++) {
        int val;
        cin>>val;
        anos[i] = {val, i};
    }
    vector<pessoa> consultas;
    vector<int> res(p);
    for (int i = 1; i <= p; i++) {
        int posi, l, r;
        cin >> l >> posi >> r;
        if (anos[l].first >= posi) {
            res[i-1] = 0;
            continue;
        }
        pessoa temp(posi, l, r, i-1);
        consultas.push_back(temp);
    }
    anos.erase(anos.begin());
    sort(all(anos), greater<pair<int,int>>());
    sort(all(consultas));
    Fenwick BIT(y);
    int posiAtual = INF;
    int nextconsulta = 0;
    for (int i = 0; i < y; i++) {
        posiAtual = anos[i].first;
        while (nextconsulta < consultas.size() && consultas[nextconsulta].posi > posiAtual) {
            res[consultas[nextconsulta].id] = BIT.rangeSum(consultas[nextconsulta].l, consultas[nextconsulta].r);
            nextconsulta++;
        }
        if (nextconsulta >= p) {
            break;
        }
        BIT.add(anos[i].second, 1);
    }
    while (nextconsulta < consultas.size() && consultas[nextconsulta].posi >= posiAtual) {
        res[consultas[nextconsulta].id] = BIT.rangeSum(consultas[nextconsulta].l, consultas[nextconsulta].r);
        nextconsulta++;
    }
    for (int r : res) {
        cout << r << '\n';
    }



    return 0;
}