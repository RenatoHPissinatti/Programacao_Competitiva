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
    ll n;
    cin>>n;
    vector<ll> DP(100001, -1);
    vector<ll> vec;
    ll count1=0;
    for (ll i=0;i<n;i++) {
        ll a;
        cin>>a;
        if (a==1) {
            count1++;
        }
        vec.push_back(a);
    }
    for (ll i=1;i<=n;i++) {
        if (i==1) {
            DP[0]=0;
            DP[1]=count1;
            continue;
        }
        ll count4=0;
        ll count3=0;
        for (ll j=0;j<=n-i;j++) {


            if (j==0) {

                for (ll k=0;k<i;k++) {
                    count3+=vec[k];
                }
                if (count3%2!=0) {
                    count4++;
                }
                continue;
            }
            if (vec[j-1]==1) {
                count3--;
            }
            if (vec[(n-i)+j]==1) {
                count3++;
            }
            if (count3%2!=0) {
                count4++;
            }


        }
        DP[i]=DP[i-1]+count4;
    }
    cout << DP[n]<< '\n';
    return 0;
}
//
// Created by Usuario on 18/08/2026.
//
