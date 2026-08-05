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
    int n;
    cin >> n;
    vector<pair<int, int>> beacons(n);
    vector<int> position(1000001, -1);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        beacons[i] = {a, b};
        position[a] = b;
    }
    sort(all(beacons));
    vector<int> dp(1000001, 0);
    if (position[0] != -1) {
        dp[0] = 1;
    }
    for (int i = 1; i <= 1000000; i++) {
        if (position[i] == -1) {
            dp[i] = dp[i-1];
        }
        else {
            if (i - position[i] - 1 < 0) {
                dp[i] = 1;
            }
            else {
                int posianterior = i - position[i] - 1;
                dp[i] = dp[posianterior] + 1;
            }

        }
    }


    int maior = 0;
    for (int val : dp) {
        maior = max(maior, val);
    }
    cout << n - maior << '\n';




    return 0;
}
