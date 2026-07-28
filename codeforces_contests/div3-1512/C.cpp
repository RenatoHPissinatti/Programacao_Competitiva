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
        int zeros, uns;
        cin >> zeros >> uns;
        string s;
        cin >> s;
        int n = static_cast<int>(s.size());
        bool impossible = false;
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                if (s[i] == '0') {
                    if (s[n-i-1] == '?') {
                        s[n-i-1] = '0';
                    }
                    else {
                        if (s[n-i-1] != '0') {
                            impossible = true;
                            break;
                        }
                    }
                }
                if (s[i] == '1') {
                    if (s[n-i-1] == '?') {
                        s[n-i-1] = '1';
                    }
                    else {
                        if (s[n-i-1] != '1') {
                            impossible = true;
                            break;
                        }
                    }
                }
            }
        }
        if (impossible) {
            cout << -1 << '\n';
            continue;
        }
        for (char c : s) {
            if (c == '0') {
                zeros--;
            }
            else if (c == '1') {
                uns--;
            }
            if (zeros < 0 || uns < 0) {
                impossible = true;
                break;
            }
        }
        if (impossible) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                if (zeros > uns) {
                    s[i] = '0';
                    s[n-i-1] = '0';
                    if (i == n-i-1) {
                        zeros--;
                    }
                    else {
                        zeros-=2;
                    }
                }
                else {
                    s[i] = '1';
                    s[n-i-1] = '1';
                    if (i == n-i-1) {
                        uns--;
                    }
                    else {
                        uns-=2;
                    }
                }
            }
            if (zeros < 0 || uns < 0) {
                impossible = true;
                break;
            }
        }
        if (zeros != 0 || uns != 0) {
            cout << -1 << '\n';
        }
        else {
            cout << s << '\n';
        }
    }

    return 0;
}
