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

        vector<int> entrada(n);
        unordered_map<int, int> contando;
        for (int i = 0; i < n; i++) {
            cin >> entrada[i];
        }
        ll count = 0;
        for (int i = 0; i < n; i++) {
            int idx = i + 1;
            int ai = entrada[i];
            count += contando[ai - i];
            contando[ai-i]++;
        }
        cout << count << '\n';


    }

    return 0;
}
