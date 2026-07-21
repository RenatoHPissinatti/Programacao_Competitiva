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
        int k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(all(a));
        int maiorseq = 1;
        int seqAtual = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i-1] <= k) {
                seqAtual++;
                maiorseq = max(maiorseq, seqAtual);
            }
            else {
                seqAtual = 1;
            }
        }
        int res = n - maiorseq;


        cout << res << '\n';
    }
    return 0;
}
