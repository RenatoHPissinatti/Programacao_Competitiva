#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

const int INF = 1e9 + 7;
const int LOG = 20;
const int MAXA = 100005;

int n, m;
vector<vector<int>> adj;
int p[100005];
int age_val[100005];
int up[100005][LOG];

// Arrays para planificar a árvore
int in_time[100005], out_time[100005];
int timer_in = 0;

// DFS para calcular a tabela do Binary Lifting e o timer da Subárvore
void dfs(int u, int p_u) {
    in_time[u] = ++timer_in;
    up[u][0] = p_u; // Chefe direto (pulo de 2^0)

    // Constrói os saltos de 2^i
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }

    for (int v : adj[u]) {
        if (v != p_u) {
            dfs(v, u);
        }
    }
    out_time[u] = timer_in;
}

// Binary Lifting: Encontra o mais alto ancestral que ainda obedece ao limite R
int get_top(int u, int R) {
    for (int i = LOG - 1; i >= 0; i--) {
        // Se o ancestral não é a origem 0 e a idade dele é <= R, damos o salto!
        if (up[u][i] != 0 && age_val[up[u][i]] <= R) {
            u = up[u][i];
        }
    }
    return u;
}

// Estrutura clássica de BIT (Fenwick Tree) para Range Update e Point Query
struct BIT {
    int size;
    vector<int> tree;
    BIT(int n) : size(n), tree(n + 1, 0) {}

    // Adiciona valor em um índice
    void add(int i, int delta) {
        for (; i <= size; i += i & -i) tree[i] += delta;
    }

    // Soma acumulada até o índice i
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

vector<int> add_party[MAXA + 5];
vector<int> query_node[MAXA + 5];
int ans[100005];

int main() {
    fastio; // Otimização vital para Maratona

    if (!(cin >> n >> m)) return 0;

    adj.assign(n + 1, vector<int>());

    for (int i = 1; i <= n; i++) {
        cin >> age_val[i] >> p[i];
        if (p[i] == i) {
            p[i] = 0; // O grande chefe não tem manager, aponta pro 0
        } else {
            adj[p[i]].push_back(i);
        }
    }

    // Proteção extrema: Definir a idade do nível '0' como infinita.
    // Isso impede que o get_top dê um salto para além do CEO e saia do escopo.
    age_val[0] = INF;

    dfs(1, 0);

    for (int i = 0; i < m; i++) {
        int o, l, r;
        cin >> o >> l >> r;

        // Acha quem é a raiz do convite dessa festa
        int top = get_top(o, r);

        // Registra que quando a Sweep Line bater na idade 'l', essa festa deve ativar
        add_party[l].push_back(top);
    }

    // Agendando as perguntas: "Quando varrer pela minha idade, cheque quantas festas ativaram no meu Topo"
    for (int i = 1; i <= n; i++) {
        query_node[age_val[i]].push_back(i);
    }

    BIT bit(n + 5);

    // Linha de varredura das idades menores (1) para as maiores (100.000)
    for (int x = 1; x <= MAXA; x++) {

        // 1º - Processa as festas abrindo agora
        for (int top : add_party[x]) {
            // Range Update via Fenwick (Difference Array conceitual)
            bit.add(in_time[top], 1);           // +1 do in_time pra frente
            bit.add(out_time[top] + 1, -1);     // Cancela o +1 após o out_time da subárvore
        }

        // 2º - Lê as respostas para os nós cujo limiar de idade acabou de passar
        for (int u : query_node[x]) {
            ans[u] = bit.query(in_time[u]);
        }
    }

    // Imprime o resultado e ganha o balão
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}