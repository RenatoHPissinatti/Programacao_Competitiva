#include <bits/stdc++.h>

#include <utility>
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

ll tiraquanto(ll val) {
    ll count =0;
    while (val > 0) {
        count+= val%10;
        val/=10;
    }
    return count;
}
struct orienta {
    ll somapolen = -1;
    int op_number = -1;
};
struct resqpd {
    int ops;
    ll a;
    ll b;
};

resqpd quantasopde(ll a, ll b, map<ll, orienta>& orientacao) {
    int count = 0;
    while (orientacao[a].somapolen == -1 && a >= b) {
        count++;
        a -= tiraquanto(a);
    }
    if (a < b) {
        return {count, a, b};
    }
    int tempb = b;
    int opb = 0;
    while (orientacao[tempb].somapolen == -1) {
        tempb -= tiraquanto(tempb);
        opb++;
    }
    count+= orientacao[a].op_number - orientacao[tempb].op_number - opb;
    int opn_tempb = orientacao[tempb].op_number;
    int opn_tempa = orientacao[a].op_number;
    count = max(0, count);
    resqpd ret = { count, a, b};
    return ret;
}



int main() {
    fastio;
    int n, dia;
    cin >> n >> dia;
    multiset<ll> flores;
    map<ll, orienta> orientacao;
    vector<int> optonumber(39320);
    ll number = 999999;
    int operations = 0;
    while (number != 0) {
        int flor = tiraquanto(number);
        orientacao[number] = {flor, 39319 - operations};
        optonumber[39319 - operations] = number;
        operations++;
        number = number - flor;
    }
    orientacao[0] = {0, 0};
    for (int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        flores.insert(val);
    }

    while (true) {
        resqpd res = quantasopde(*prev(flores.end()), *prev(prev(flores.end())), orientacao);
        if (res.ops > dia) {
            break;
        }
        dia -= res.ops;
        flores.erase(prev(flores.end()));
        flores.insert(res.a);
    }

    int count = 0;
    ll a = *prev(flores.end());
    while (orientacao[a].somapolen == -1 && count < dia) {
        count++;
        a -= tiraquanto(a);
    }
    if (count < dia) {
        cout << tiraquanto(a) << '\n';
    }
    else {
        cout << tiraquanto(optonumber[orientacao[a].op_number + dia]) << '\n';
    }



    return 0;
}