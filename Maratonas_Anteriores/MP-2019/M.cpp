//
// Created by Usuario on 04/08/2026.
//
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

bool conseguenotempo (ll t, ll vel, ll pessoas, vector<ll>& pipocas) {
    ll pipocastotais = t*vel;
    ll pessoaAtual = t*vel;
    for (int i = 0; i < pipocas.size(); i++) {
        if (pipocas[i] <= pessoaAtual) {
            pessoaAtual -= pipocas[i];
        }
        else {
            pessoas--;
            if (pessoas <= 0) {
                return false;
            }
            pessoaAtual = pipocastotais;
            if (pipocas[i] <= pessoaAtual) {
                pessoaAtual -= pipocas[i];
            }
            else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    fastio;
    ll n, c, t;
    cin >> n >> c >> t;
    ll somatotal = 0;
    vector<ll> pipocas(n);
    for (int i = 0; i < n;i++) {
        ll val;
        cin >> val;
        pipocas[i] = val;
        somatotal +=val;
    }
    ll menort = 1;
    ll maiort = (somatotal + t - 1)/t;
    ll atual = (maiort + menort)/2;
    while (atual != maiort && atual != menort) {
        if (conseguenotempo(atual, t, c, pipocas)) {
            maiort = atual;
            atual = (menort + atual)/2;
        }
        else {
            menort = atual;
            atual = (maiort + atual)/2;
        }
    }
    if (conseguenotempo(atual, t, c, pipocas)) {
        cout << atual << '\n';
    }
    else {
        cout << maiort << '\n';
    }

    return 0;

}