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
map<ll, int> divisivel;
bool busca(ll temp, vector<ll>& fibo) {
    if (divisivel[temp] == -1) {
        return false;
    }
    if (divisivel[temp] != 0) {
        return true;
    }
    bool flag = true;
    while (temp > 1) {
        ll maiordiv = 1;
        for (int i = fibo.size()-1; i >=1; i--) {
            ll val = fibo[i];
            if (temp%val == 0 && busca(temp/val, fibo)) {
                maiordiv = val;
                divisivel[temp] = 1;
                break;
            }
        }

        if (maiordiv == 1) {
            divisivel[temp] = -1;
            flag = false;
            break;
        }
        temp /= maiordiv;
    }
    return flag;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> fibo;
    fibo.push_back(1);
    fibo.push_back(2);
    fibo.push_back(3);
    ll temp = n;
    ll atual = 3;
    ll idx = 2;
    while (atual <= temp) {
        atual = fibo[idx-1] + fibo[idx];
        fibo.push_back(atual);
        idx++;
    }
    bool flag = true;
    vector<ll> res;
    while (temp > 1) {
        ll maiordiv = 1;
        ll maiordividx = 0;
        for (int i = fibo.size()-1; i >= 1; i--) {
            ll val = fibo[i];
            if (temp%val == 0 && busca(temp/val, fibo)) {
                maiordiv = val;
                maiordividx = i;
                break;
            }
        }
        if (maiordiv == 1) {
            flag = false;
            break;
        }
        temp /= maiordiv;
        res.push_back(maiordividx);
    }
    if (!flag) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (ll r : res) {
        for (int i = 0; i < r; i++) {
            cout << 'A';
        }
        cout << 'B';
    }

    return 0;
}