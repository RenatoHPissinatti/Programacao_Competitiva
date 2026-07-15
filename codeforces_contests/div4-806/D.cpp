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
        map<string, bool> isInVec;
        vector<string> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> s;
            vec[i] = s;
            isInVec[s] = true;
        }
        for (int i = 0; i < n; i++) {
            s = vec[i];
            int r = s.size();
            bool flag = false;
            for (int l = 0; l < s.size() - 1; l++) {
                string s1 = s.substr(0, l + 1);
                string s2 = s.substr(l+1, r - l);
                if (isInVec[s1] == true && isInVec[s2] == true) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                cout << '1';
            }
            else {
                cout << '0';
            }
        }
        cout << '\n';
    }


    return 0;
}
