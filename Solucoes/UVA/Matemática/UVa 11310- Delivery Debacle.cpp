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

ll DP[100];
using namespace std;


ll combinatoria(int n) {

    ll &ans= DP[n];



    if (ans!=-1) return ans;

    ans=0;
    ans+=combinatoria(n-1)+(4*combinatoria(n-2))+(2*combinatoria(n-3));

    return ans;



}

int main() {
    int n;
    cin>>n;
    memset(DP, -1, sizeof DP);

    while (n--) {
        ll ans;
        int a;
        cin>>a;
        DP[0]=DP[1]=1;
        DP[2]=5;
        ans=combinatoria(a);
        cout<<ans<<endl;
    }


    return 0;
}