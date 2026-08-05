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
    char code;
    string s;
    cin >> code;
    cin >> s;
    string sres;
    if (code == 'E') {
        char lastchar = ' ';
        int sumchar = 0;
        for (char c: s) {
            if (c == lastchar) {
                sumchar++;
            }
            else {
                if (sumchar > 0) {
                    sres += to_string(sumchar);
                }
                sres += c;
                sumchar = 1;
                lastchar = c;
            }
        }
        if (sumchar > 0) {
            sres += to_string(sumchar);
        }
        cout << sres << '\n';
    }
    else {
        for (int i = 0; i < s.size(); i+=2) {
            char c = s[i];
            int qnt = s[i+1];
            qnt -= 48;
            for (int j = 0; j < qnt; j++) {
                cout << c;
            }
        }
        cout << '\n';
    }

    return 0;
}
