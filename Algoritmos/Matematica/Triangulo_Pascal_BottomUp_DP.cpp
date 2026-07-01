
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

const int MEMO=1000;

int DP[MEMO][MEMO];

int pascal(int n, int k) {
    if (!DP[n][k]) {
        if (n==k || k==0) {
            return DP[n][k]=1;
        }
        else {
            return DP[n][k]= pascal(n-1,k-1)+pascal(n-1,k);
        }
    }
    else {
        return DP[n][k];
    }

}


