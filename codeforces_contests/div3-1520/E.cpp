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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a;
        string s;
        cin >> s;
        ll sumOv = 0;
        ll count = 0;
        int i = 0;
        while (s[i] == '.') {
            i++;
        }
        bool ovelha = true;
        for (; i < n; i++) {
            if (s[i] == '*') {
                sumOv++;
                if (!ovelha) a.push_back(count);
                count = 0;
                ovelha = true;
            }
            else {
                if (ovelha) {
                    a.push_back(sumOv);
                    ovelha = false;
                }
                count++;
            }
        }

        count = 0;
        for (i = 1; i < a.size(); i+=2) {
            ll menor = min(a[i-1], sumOv - a[i-1]);
            count+= a[i]*menor;
        }
        cout << count << '\n';
    }
    return 0;
}
