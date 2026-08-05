#include <iostream>
#include<cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define vi vector<int>
#define vii vector<pii>


int dp[101];
using namespace std;

struct Gangster {
    int t;
    int p;
    int s;
};

bool compareGangsters(const Gangster& a, const Gangster& b) {
    return a.t < b.t;
}




int main() {
    int n;
    cin>>n;




    while (n--) {
        memset(dp, -1, sizeof dp);
        int N,K,T;
        cin>>N>>K>>T;



        vector<Gangster> g(N);
        int max_total_prosperity = 0;


        for (int i = 0; i < N; i++) cin >> g[i].t;
        for (int i = 0; i < N; i++) cin >> g[i].s;
        for (int i = 0; i < N; i++) cin >> g[i].p;
        sort(g.begin(), g.end(), compareGangsters);

        for (int i=0;i<N;i++) {

            if (g[i].t >= g[i].p) dp[i] = g[i].s;
            for (int j = 0; j < i; j++) {
                if (dp[j] != -1) {
                    int time_diff = g[i].t - g[j].t;
                    int pos_diff = abs(g[i].p - g[j].p);


                    if (time_diff >= pos_diff) {
                        dp[i] = max(dp[i], dp[j] + g[i].s);
                    }
                }
            }


            max_total_prosperity = max(max_total_prosperity, dp[i]);

        }
        cout << max_total_prosperity << "\n";


        if (n > 0) {
            cout << "\n";
        }










    }


    return 0;
}//
// Created by gabri on 28/07/2026.
//