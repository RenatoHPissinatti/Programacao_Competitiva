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
    string s;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> wheels(n);
        for (int i = 0; i < n; i++) {
            cin >> wheels[i];
        }
        for (int i = 0; i < n; i++) {
            int num = wheels[i];
            int num2;
            cin >> num2;
            cin >> s;
            for (char c : s) {
                if (c == 'D') {
                    num++;
                    if (num > 9) {
                        num = 0;
                    }
                }
                else {
                    num--;
                    if (num < 0) {
                        num = 9;
                    }
                }
            }
            cout << num << ' ';
        }
        cout << '\n';
    }


    return 0;
}
