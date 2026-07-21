
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

int DP[27][27][352];

int solve(int length, int last, int sum) {


    if (sum==0 && length == 0) return 1;

    if (sum<=0 || length<=0|| last <= 0) return 0;



    int &ans=DP[length][last][sum];

    if (ans!=-1) return ans;

    ans=0;

    for (int i=last;i>=1;i--) {
        ans=ans+solve(length-1,i-1,sum-i);
    }


    return ans;




}


int main() {
    fastio;

    int l, s;
    int case_num = 1;


    while (cin >> l >> s && (l != 0 || s != 0)) {
        memset(DP, -1, sizeof DP);


        int resposta=0;

        if (l <= 26 && s <= 351) {
            resposta = solve(l, 26, s);
        }

        cout << "Case " << case_num++ << ": " << resposta << "\n";

    }

    return 0;





}