#include <iostream>
#include<cstring>
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


ll combinatoria(int a, int b, int c, int d, int e) {
    ll ans;
    ans= a*b*c*d*d*e*e;


    return ans;



}

int main() {


    int a,b,c,d,e;
    while (cin>>a>>b>>c>>d>>e && (a>=1 && b>=1 && c>=1 && d>=1 && e>=1  )) {
        ll ans;


        ans=combinatoria(a,b,c,d,e);
        cout<<ans<<endl;
    }


    return 0;
}