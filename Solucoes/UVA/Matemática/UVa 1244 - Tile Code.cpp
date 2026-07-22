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
ll DP2[100];
using namespace std;


ll combinatoria(int n) {

    ll &ans= DP[n];





    if (ans!=-1) return ans;

    ans=0;
    ans+=combinatoria(n-1)+2*combinatoria(n-2);

    return ans;



}
ll palindromo(int n) {

    ll &ans= DP2[n];



    if (ans!=-1) return ans;
    ans=0;

    if (n%2==0) {
        ans+=combinatoria(n/2)+2*combinatoria((n/2)-1);
    }
    else {
        ans+=combinatoria((n-1)/2);
    }




    return ans;



}

int main() {
    int n;
    cin>>n;
    memset(DP, -1, sizeof DP);
    memset(DP2, -1, sizeof DP2);

    while (n--) {
        ll ans;
        ll ans1;
        ll ans2;
        int a;
        cin>>a;
        DP[0]=0;
        DP[1]=1;
        DP[2]=3;



        DP2[1]=0;
        DP2[2]=1;
        DP2[3]=1;



        ans1=combinatoria(a);
        ans2=palindromo(a);
        ans=(ans1+ans2)/2;

        cout<<ans<<endl;
    }


    return 0;
}