
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

int DP[41];

int main() {
    fastio;
    int n;
    cin>>n;
    DP[0]=DP[1]=1;

    for (int i=2;i<41;i++) {
        DP[i]=DP[i-1]+DP[i-2];
    }

    cout<<DP[n]<<endl;

    return 0;
}
