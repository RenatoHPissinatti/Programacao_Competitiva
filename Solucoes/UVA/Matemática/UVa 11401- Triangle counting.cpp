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


ll combinatoria(int n) {

    ll &ans= DP[n];



    if (ans!=-1) return ans;

    ans=0;
    if (n%2==0) {
        ll b=n/2;
        b--;
        ans+= b*b;
    }
    else {
        ll c= n/2;
        ll b=c-1;
        ans+=c*b;

    }



    ans+=combinatoria(n-1);

    return ans;



}

int main() {

    memset(DP, -1, sizeof DP);
    DP[3]=0;
    DP[4]=1;
    int a;
    while (cin>>a && a>=3) {
        ll ans;


        ans=combinatoria(a);
        cout<<ans<<endl;
    }


    return 0;
}