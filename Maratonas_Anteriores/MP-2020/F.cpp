//
// Created by Usuario on 06/08/2026.
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

void verificagame(int& gamesE, int& gamesD, int& pontosE, int& pontosD, char& vencedor, bool& esquerdasaca) {
    if ((pontosE >= 5 && pontosE-2 >= pontosD) || pontosE == 10) {
        pontosE = pontosD = 0;
        esquerdasaca = true;
        gamesE++;
    }
    if ((pontosD >= 5 && pontosD-2 >= pontosE) || pontosD == 10) {
        pontosD = pontosE = 0;
        gamesD++;
        esquerdasaca = false;
    }
    if (gamesE == 2) {
        vencedor = 'E';
    }
    if (gamesD == 2) {
        vencedor = 'D';
    }
}


int main() {
    fastio;
    string s;
    cin >> s;
    // ganha quem alcançar 2 games!!!
    // o game acaba quando alguem fizer 2 pontos de vantagem, tendo 5 pontos ou fizer 10 pontos.
    // saca primeiro o da esquerda e vai alternando;
    // após alguém ganhar um game, quem saca é quem ganhou o ultimo game;

    bool esquerdasaca = true;
    int gamesE = 0;
    int gamesD = 0;
    int pontosE = 0;
    int pontosD = 0;
    char vencedor = 'N';

    for (char c : s) {
        if (c == 'S') {
            if (vencedor != 'N') continue;
            if (esquerdasaca) {
                pontosE++;
                esquerdasaca = true;
            }
            else {
                pontosD++;
                esquerdasaca = false;
            }

        }
        else {
            if (c == 'R') {
                if (vencedor != 'N') continue;
                if (esquerdasaca) {
                    pontosD++;
                    esquerdasaca = false;
                }
                else {
                    pontosE++;
                    esquerdasaca = true;
                }
            }
            else {
                if (vencedor == 'N') {
                    if (esquerdasaca) {
                        printf("%d (%d*) - %d (%d)", gamesE, pontosE, gamesD, pontosD);
                    }
                    else {
                        printf("%d (%d) - %d (%d*)", gamesE, pontosE, gamesD, pontosD);
                    }
                }
                else {
                    if (vencedor == 'E') {
                        printf("%d (winner) - %d", gamesE, gamesD);
                    }
                    else {
                        printf("%d - %d (winner)", gamesE, gamesD);
                    }
                }
                printf("\n");
            }
        }
        verificagame(gamesE, gamesD, pontosE, pontosD, vencedor, esquerdasaca);
    }

    printf("\n");
    return 0;
}