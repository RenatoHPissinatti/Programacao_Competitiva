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
        vector<int> b(n+2);
        ll sumb = 0;
        for (int i = 0; i < n + 2; i++) {
            cin >> b[i];
            sumb+=b[i];
        }
        sort(all(b));
        //caso que o x é o n+1

        ll sumA = 0;
        int idxSum = -1;
        int idxx = -1;
        ll x = 0;
        if (sumb - b[n+1] - b[n] == b[n]) {
            sumA = b[n];
            idxSum = n;
            x = b[n+1];
            idxx = n+1;
        }

        else {
            if (sumb - b[n+1] - b[n] == b[n+1]) { //caso que o x é o n
                sumA = b[n+1];
                idxSum = n+1;
                x = b[n];
                idxx = n;
            }

            else {
                //caso que o x está antes desses 2
                x = -1;
                sumA = b[n+1];
                idxSum = n+1;
                for (int i = 0; i < n+1; i++) {
                    if (sumb - sumA - b[i] == sumA) {
                        x = b[i];
                        idxx = i;
                        break;
                    }
                }
            }
        }

        if (idxSum == -1 || idxx == -1) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n + 2; i++) {
            if (i != idxx && i != idxSum) {
                cout << b[i] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
