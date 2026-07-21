
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

ll solve(int level) {









    ll &ans=DP[level];

    if (ans!=-1) return ans;

    ans=0;

    ans+=DP[level-2]+DP[level-1];




    return ans;




}


int main() {
    fastio;

    int l, s;
    int case_num = 1;

    memset(DP, -1, sizeof DP);

    while (cin >> l  && (l > 0)) {



        ll resposta=0;

        if (l <= 85 ) {
            l--;
            DP[0]=1;
            DP[1]=1;
            resposta = solve(l);
        }

        cout <<  resposta << "\n";

    }

    return 0;





}