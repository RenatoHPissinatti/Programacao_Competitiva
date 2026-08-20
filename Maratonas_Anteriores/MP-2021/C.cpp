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

const int UNVISITED = -1;
const int VISITED = 1;

int minEnergy;
int maxEnergy;
int totalEnergy;


int main() {
    fastio;
    int b, l;
    cin >> b >> l;
    vector<int> number(l);
    for (int i = 0; i < l; i++) {
        cin >> number[i];
    }
    ll resto = 0;
    bool par = l%2!=0;
    for (int d : number) {
        if (par) {
            resto += d;
        }
        else {
            resto -= d;
        }
        par = !par;
    }
    resto %= (b+1);
    resto += b+1;
    resto %= (b+1);
    if (resto == 0) {
        cout << "0 0\n";
        return 0;
    }
    par = l%2 !=0;
    pair<int, int> res = {-1, -1};
    for (int i = 0; i < l; i++) {
        int d = number[i];
        if (par) {
            if (resto <= d && d + resto >=0) {
                res = {i+1, d-resto};
                break;
            }
        }
        else {
            if (resto + d >= b+1) {
                res = {i+1, d -(b+1 - resto)};
                break;
            }
        }
        par = !par;
    }

    cout << res.first << ' ' << res.second << '\n';


    return 0;
}