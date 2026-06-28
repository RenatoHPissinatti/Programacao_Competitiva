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

    int n;
    cin >> n;

    char espaco = 32;
    char barra = 47;
    char contrabarra = 92;
    char traco = 95;
    for (int i = 0; i < n; i++) {
        cout << espaco;
    }
    for (int i = 0; i < n+1; i++) {
        cout << traco;
    }
    cout << '\n';
    int efora = n-1;
    int edentro = n + 1;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < efora; j++) {
            cout << espaco;
        }
        efora--;
        cout << barra;
        for (int j = 0; j < edentro; j++) {
            cout << espaco;
        }
        edentro += 2;
        cout << contrabarra << '\n';
    }
    cout << barra;
    for (int i = 0; i < n; i++) {
        cout << traco;
    }
    for (int i = 0; i < edentro - n; i++) {
        cout << espaco;
    }
    cout << contrabarra;
    for (int i = 0; i < n+1; i++) {
        cout << traco;
    }
    cout << '\n';
    efora = n+1;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < efora; j++) {
            cout << espaco;
        }
        efora++;
        cout << contrabarra;
        for (int j = 0; j < edentro; j++) {
            cout << espaco;
        }
        edentro -= 2;
        cout << barra << '\n';
    }

    for (int i = 0; i < efora; i++) {
        cout << espaco;
    }
    cout << contrabarra;
    for (int i = 0; i < edentro; i++) {
        cout << traco;
    }
    cout << barra;
    cout << '\n';





    return 0;
}
