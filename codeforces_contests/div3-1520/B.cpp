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

        ll num = 1;
        ll compair = 10;
        ll sum = 1;
        ll count = 0;
        while (num <= n) {
            while (num < compair && num <= n) {
                count++;
                num += sum;
            }

            num = compair + sum;
            sum = num;
            compair *= 10;
        }
        cout << count << '\n';
    }


    return 0;
}
