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

void embarca(queue<int>& d, int& parada) {
    parada = max(parada, d.front() + 10);
    d.pop();
}

void embarcaposparada(queue<int>& d, int& parada) {
    parada = max(parada + 10, d.front() + 10);
    d.pop();
}

int main() {
    fastio;
    int n;
    cin >> n;
    vector<pair<int, int>> entrada(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        entrada[i] = { a, b};
    }
    sort(all(entrada));
    queue<int> desce0;
    queue<int> desce1;
    for (auto [t, desce] : entrada) {
        if (desce == 0) {
            desce0.push(t);
        }
        else {
            desce1.push(t);
        }
    }

    int parada = 0;
    bool descef1 = false;
    if (desce1.empty()) {
        embarca(desce0, parada);
    }
    else {
        if (desce0.empty()) {
            embarca(desce1, parada);
        }
        else {
            if (desce1.front() < desce0.front()) {
                descef1 = true;
                embarca(desce1, parada);
            }
            else {
                descef1 = false;
                embarca(desce0, parada);
            }
        }
    }

    while (!desce1.empty() || !desce0.empty()) {
        if (desce1.empty()) {
            if (descef1) {
                embarcaposparada(desce0, parada);
            }
            else {
                embarca(desce0, parada);
            }
            descef1 = false;
        }
        else {
            if (desce0.empty()) {
                if (descef1) {
                    embarca(desce1, parada);
                }
                else {
                    embarcaposparada(desce1, parada);
                }
                descef1 = true;
            }
            else {
                if (descef1) {
                    if (parada > desce1.front()) {
                        embarca(desce1, parada);
                        descef1 = true;
                    }
                    else {
                        if (desce1.front() < desce0.front()) {
                            descef1 = true;
                            embarcaposparada(desce1, parada);
                        }
                        else {
                            descef1 = false;
                            embarcaposparada(desce0, parada);
                        }
                    }
                }
                else {
                    if (parada > desce0.front()) {
                        embarca(desce0, parada);
                        descef1 = false;
                    }
                    else {
                        if (desce1.front() < desce0.front()) {
                            descef1 = true;
                            embarcaposparada(desce1, parada);
                        }
                        else {
                            descef1 = false;
                            embarcaposparada(desce0, parada);
                        }
                    }
                }
            }
        }
    }
    cout << parada << '\n';

    return 0;
}
