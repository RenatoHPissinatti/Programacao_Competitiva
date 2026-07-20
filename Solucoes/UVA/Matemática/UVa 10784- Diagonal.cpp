#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define vii vector<pii>

ll DP[1000001];
using namespace std;


ll combinatoria(ll a) {
    ll ans;

    long double delta = 9.0 + 8.0 * (long double)a;
    ans = ceil((3.0 + sqrt(delta)) / 2.0);


    return ans;



}

int main() {


    ll a;
    int caso=1;
    while (cin>>a && a>=1) {
        ll ans;


        ans=combinatoria(a);
        cout << "Case " << caso++ << ": " << ans << "\n";
    }


    return 0;
}