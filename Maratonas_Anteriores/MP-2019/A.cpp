#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

struct Sensor {
    ll x, y, r;

    Sensor() {
        x = y = r = 0;
    }

    Sensor(ll _x, ll _y, ll _r) : x(_x), y(_y), r(_r) {}
};

struct Parede {
    ll x;

    Parede(ll _x) : x(_x) {}
};

struct Chao {
    ll y;

    Chao(ll _y) : y(_y) {}
};

bool conectam(const Sensor& s1, const Sensor& s2) {
    ll dx = s1.x - s2.x;
    ll dy = s1.y - s2.y;
    ll somaRaios = s1.r + s2.r;

    return dx * dx + dy * dy <= somaRaios * somaRaios;
}

// Visita toda a componente e reúne suas paredes.
void dfs(
    int u,
    const vector<vector<int>>& adj,
    const vector<set<ll>>& sets,
    vector<bool>& visitado,
    set<ll>& paredesComponente
) {
    visitado[u] = true;

    // Adiciona as paredes tocadas pelo sensor u.
    for (ll parede : sets[u]) {
        paredesComponente.insert(parede);
    }

    for (int v : adj[u]) {
        if (!visitado[v]) {
            dfs(v, adj, sets, visitado, paredesComponente);
        }
    }
}

int main() {
    fastio;

    ll m, n;
    int k;
    cin >> m >> n >> k;

    Parede paredeL(0);
    Parede paredeR(m);
    Chao chao(0);
    Chao teto(n);

    // A = teto
    // B = parede esquerda
    // C = parede direita
    // D = chão
    ll A = k + 1;
    ll B = A + 1;
    ll C = B + 1;
    ll D = C + 1;

    vector<Sensor> sensores(k);

    for (int i = 0; i < k; i++) {
        ll x, y, r;
        cin >> x >> y >> r;

        sensores[i] = Sensor(x, y, r);
    }

    /*
        sets[i] contém apenas as paredes que
        o próprio sensor i toca diretamente.
    */
    vector<set<ll>> sets(k);

    for (int i = 0; i < k; i++) {
        Sensor sensor = sensores[i];

        // Atenção: é sensor.r, e não a variável r da leitura.

        if (sensor.x - sensor.r <= paredeL.x) {
            sets[i].insert(B);
        }

        if (sensor.x + sensor.r >= paredeR.x) {
            sets[i].insert(C);
        }

        if (sensor.y - sensor.r <= chao.y) {
            sets[i].insert(D);
        }

        if (sensor.y + sensor.r >= teto.y) {
            sets[i].insert(A);
        }
    }

    // Monta o grafo dos sensores que se conectam.
    vector<vector<int>> adj(k);

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (conectam(sensores[i], sensores[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> visitado(k, false);
    bool roubavel = true;

    for (int i = 0; i < k; i++) {
        if (visitado[i]) {
            continue;
        }

        set<ll> paredesComponente;

        dfs(
            i,
            adj,
            sets,
            visitado,
            paredesComponente
        );

        bool tocaA = paredesComponente.find(A) != paredesComponente.end();
        bool tocaB = paredesComponente.find(B) != paredesComponente.end();
        bool tocaC = paredesComponente.find(C) != paredesComponente.end();
        bool tocaD = paredesComponente.find(D) != paredesComponente.end();

        /*
            AC: teto e direita
            AD: teto e chão
            BC: esquerda e direita
            BD: esquerda e chão
        */
        if ((tocaA && tocaC) ||
            (tocaA && tocaD) ||
            (tocaB && tocaC) ||
            (tocaB && tocaD)) {

            roubavel = false;
            break;
        }
    }

    if (roubavel) {
        cout << 'S' << '\n';
    } else {
        cout << 'N' << '\n';
    }

    return 0;
}