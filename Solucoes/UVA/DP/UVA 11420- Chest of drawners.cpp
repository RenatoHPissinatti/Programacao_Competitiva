
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

ll DP[70][70][2];

ll solve(int pos, int seguros  , int lock) {


    if (pos==0 && seguros == 0) return 1;

    if (pos< 0 || seguros < 0|| lock < 0) return 0;




    ll &ans=DP[pos][seguros][lock];

    if (ans!=-1) return ans;

    ans=0;


    if (lock==0) {
        ans=ans+solve(pos-1,seguros-1,0);
    }
    else {
        ans=ans+solve(pos-1,seguros,0);
    }
    ans=ans+solve(pos-1,seguros,1);




    return ans;




}


int main() {
    fastio;

    int l, s;
    int case_num = 1;

    memset(DP, -1, sizeof DP);

    while (cin >> l >> s && (l >= 0 || s >= 0)) {



        ll resposta=0;

        if (l <= 65 && s <= 65) {
            resposta = solve(l, s, 0);
        }

        cout <<  resposta << "\n";

    }

    return 0;





}