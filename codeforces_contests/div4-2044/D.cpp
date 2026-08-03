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
        vector<int> a(n);
        unordered_set<int> numeros;
        vector<int> b;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (numeros.insert(a[i]).second == true) {
                b.push_back(a[i]);
            }
        }
        for (int val : b) {
            cout << val << ' ';
        }

        for (int i = 1; i <= n; i++) {
            if (numeros.find(i) == numeros.end()) {
                cout << i << ' ';
            }
        }
        cout << '\n';

    }

    return 0;
}
