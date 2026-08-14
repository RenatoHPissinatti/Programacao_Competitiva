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
    string s;
    cin >> s;
    bool seq = false;
    int count = 0;
    int seqcount = 0;
    for (int i = 0; i < n;i++) {
        if (seq) {
            seqcount++;
            if (i+1 >= n || s[i+1] != 'a') {
                count += seqcount;
                seqcount = 0;
                seq = false;
            }
        }
        else {
            if (i+1 < n && s[i] == 'a' && s[i+1] == 'a') {
                seq = true;
                seqcount = 1;
            }
        }
    }
    cout << count << '\n';

    return 0;
}
