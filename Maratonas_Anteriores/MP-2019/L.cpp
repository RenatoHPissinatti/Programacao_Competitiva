//
// Created by Usuario on 04/08/2026.
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

const int UNVISITED = -1;
const int VISITED = 1;

int main() {
    fastio;
    ll n;
    cin >> n ;
    ll a;
    a=__builtin_popcountll(n);


    ll d= 1LL<<a;
    cout<<d<<"\n";

    return 0;

}