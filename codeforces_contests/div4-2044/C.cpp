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
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int total = 2*m;
        vector<int> seats(2, m);
        seats[0] = max(0, seats[0] - a);
        seats[1] = max(0, seats[1] - b);
        int sum = 0;
        if (seats[0] >= c) {
            seats[0] -= c;
            c = 0;
        }
        else {
            c -= seats[0];
            seats[0] = 0;
        }
        if (seats[1] >= c) {
            seats[1] -= c;
        }
        else {
            c -= seats[1];
            seats[1] = 0;
        }
        total -= seats[0];
        total -= seats[1];
        cout<< total << '\n';
    }

    return 0;
}
