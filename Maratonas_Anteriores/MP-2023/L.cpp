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

vector<int> cansativas;
vector<int> revigorantes;
ll d;
int main() {
    fastio;
    string s;
    cin >> s;
    int k, n;
    cin >> k;
    n = s.size();
    map<int, multiset<char>> maposo;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        maposo[i%k].insert(c);
    }
    string res;
    for (int i = 0; i < n; i++) {
        res += *maposo[i%k].begin();
        maposo[i%k].erase(maposo[i%k].begin());
    }
    cout << res << '\n';
    return 0;
}
