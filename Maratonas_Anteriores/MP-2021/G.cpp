//
// Created by Usuario on 11/08/2026.
//
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
    ll q; cin >> q;

    if ( __builtin_popcount(q) ==1) {
        while (q!=1) {
            cout<<"AB";
            q=q/2;
        }
    }else {
        ll i=0;
        ll p=0;
        while (q!=1) {
            p+=q%2;
            q=q/2;
            i++;
        }
        ll c=i/2;
        if (c>=p){
            for (ll l=0;l<i;l++) {
                if (l%2==0 && p!=0) {
                    cout<<"AA";
                }
                else {
                    cout <<"AB";
                }
            }
        }
        else {
            cout<<"IMPOSSIBLE";

        }

    }
    return 0;
}
