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

    int n, m;
    cin >> n;
    int horas = 5;
    int minutos = 0;
    int prox;

    int sumTotal = 0;

    for (int i = 0; i < n; i++) {
        cin >> prox;

        minutos += prox;
        horas += minutos/60;
        minutos %= 60;
        sumTotal+=prox;
        if (horas > 7 && horas < 10 || horas > 17 && horas < 20 || horas == 7 && minutos > 0 || horas == 17 && minutos > 0) {
            sumTotal += 180;
            horas +=3;
        }
    }

    cout << sumTotal << '\n';

    return 0;
}
