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

const double EPS = 1e-9;
const double PI = acos(-1.0);

struct point {
    double x, y;

    point() {
        x = y = 0.0;
    }

    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator < (const point &other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }

    bool operator == (const point &other) const {
        return fabs(x - other.x) < EPS &&
               fabs(y - other.y) < EPS;
    }
};

struct vec {
    double x, y;

    vec(double _x, double _y) : x(_x), y(_y) {}
};

// Converte dois pontos a e b no vetor a -> b
vec toVec(const point &a, const point &b) {
    return vec(b.x - a.x, b.y - a.y);
}

// Multiplica um vetor por escalar
vec scale(const vec &v, double s) {
    return vec(v.x * s, v.y * s);
}

// Move o ponto p pelo vetor v
point translate(const point &p, const vec &v) {
    return point(p.x + v.x, p.y + v.y);
}

// Distância Euclidiana entre dois pontos
double dist(const point &p1, const point &p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// Produto escalar
double dot(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}

// Norma ao quadrado
double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}

// Produto vetorial 2D
double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

// Retorna true se p -> q -> r faz curva à esquerda
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > EPS;
}

// Retorna true se p, q, r são collineares
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// Ângulo a-o-b, em radianos
double angle(const point &a, const point &o, const point &b) {
    vec oa = toVec(o, a);
    vec ob = toVec(o, b);

    double value = dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob));

    // Proteção contra erro de precisão:
    value = max(-1.0, min(1.0, value));

    return acos(value);
}

// Retorna true se p está no segmento fechado ab
bool onSegment(point a, point b, point p) {
    if (!collinear(a, b, p))
        return false;

    return min(a.x, b.x) - EPS <= p.x && p.x <= max(a.x, b.x) + EPS &&
           min(a.y, b.y) - EPS <= p.y && p.y <= max(a.y, b.y) + EPS;
}

/*
    Retorna:
     1  -> ponto dentro do polígono
     0  -> ponto em uma aresta ou vértice do polígono
    -1  -> ponto fora do polígono

    IMPORTANTE:
    O vetor P deve estar "fechado":
    P[0] == P.back()

    Exemplo:
    vector<point> P = {
        {0, 0}, {4, 0}, {4, 4}, {0, 4}, {0, 0}
    };
*/
int insidePolygon(point pt, const vector<point> &P) {
    int n = (int)P.size();

    // Evita caso degenerado: ponto ou linha
    if (n <= 3)
        return -1;

    // Primeiro verifica se pt está em algum vértice ou aresta
    for (int i = 0; i < n - 1; ++i) {
        if (onSegment(P[i], P[i + 1], pt))
            return 0;
    }

    // Winding number: soma de ângulos
    double sum = 0.0;

    for (int i = 0; i < n - 1; ++i) {
        if (ccw(pt, P[i], P[i + 1]))
            sum += angle(P[i], pt, P[i + 1]);
        else
            sum -= angle(P[i], pt, P[i + 1]);
    }

    if (fabs(sum) > PI)
        return 1;

    return -1;
}

struct polarVec {
    double r;      // módulo do vetor
    double theta;  // ângulo em radianos, no intervalo [-pi, pi]
};

polarVec toPositivePolar(const vec &v) {
    double r = hypot(v.x, v.y);
    double theta = atan2(v.y, v.x);

    if (theta < 0)
        theta += 2.0 * PI;

    return {r, theta};
}

vector<polarVec> edgesToPositivePolarVectors(const vector<point> &P) {
    vector<polarVec> ans;

    for (int i = 0; i + 1 < (int)P.size(); ++i) {
        vec e = toVec(P[i], P[i + 1]);
        ans.push_back(toPositivePolar(e));
    }

    return ans;
}

vector<vector<int>> buildAdj(int n, const vector<pair<int, int>> &edges) {
    vector<vector<int>> adj(n);

    for (auto &[u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

double edgeAngle(int u, int v, const vector<point> &P) {
    vec e = toVec(P[u], P[v]);
    return toPositivePolar(e).theta;
}

void sortAdjByPolarAngle(vector<vector<int>> &adj, const vector<point> &P) {
    int n = adj.size();

    for (int u = 0; u < n; ++u) {
        sort(adj[u].begin(), adj[u].end(), [&](int a, int b) {
            double angA = edgeAngle(u, a, P);
            double angB = edgeAngle(u, b, P);

            if (fabs(angA - angB) > EPS)
                return angA < angB;

            // desempate em caso de pontos quase collineares na mesma direção
            return dist(P[u], P[a]) < dist(P[u], P[b]);
        });
    }
}

long long keyEdge(int u, int v) {
    return (1LL * u << 32) ^ v;
}

double signedArea2(const vector<int> &face, const vector<point> &P) {
    double ans = 0.0;
    int n = face.size();

    for (int i = 0; i < n; ++i) {
        point a = P[face[i]];
        point b = P[face[(i + 1) % n]];

        ans += a.x * b.y - b.x * a.y;
    }

    return ans;
}

vector<vector<int>> findFaces(
    const vector<point> &P,
    const vector<pair<int, int>> &edges
) {
    int n = P.size();

    vector<vector<int>> adj = buildAdj(n, edges);

    sortAdjByPolarAngle(adj, P);

    unordered_map<long long, int> pos;

    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i];
            pos[keyEdge(u, v)] = i;
        }
    }

    vector<vector<char>> used(n);

    for (int u = 0; u < n; ++u) {
        used[u].assign(adj[u].size(), false);
    }

    vector<vector<int>> faces;

    for (int startU = 0; startU < n; ++startU) {
        for (int startI = 0; startI < (int)adj[startU].size(); ++startI) {
            if (used[startU][startI])
                continue;

            vector<int> face;

            int u = startU;
            int i = startI;

            while (!used[u][i]) {
                used[u][i] = true;

                int v = adj[u][i];

                face.push_back(u);

                // Agora estamos em v.
                // Precisamos encontrar a posição de u na adj[v].
                int revPos = pos[keyEdge(v, u)];

                // Próxima aresta em ordem polar
                int nextPos = (revPos + 1) % adj[v].size();

                u = v;
                i = nextPos;
            }

            double area2 = signedArea2(face, P);

            // Com essa convenção, faces internas tendem a ter área positiva.
            // A face externa tende a ter área negativa.
            if (area2 > EPS) {
                faces.push_back(face);
            }
        }
    }

    return faces;
}



int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    int x, y;
    vector<point> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vertices[i] = point(x, y);
    }
    vector<pair<int, int>> arestas(m);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        arestas[i] = {x, y};
    }

    vector<vector<int>> poligonosidx = findFaces(vertices, arestas);
    vector<vector<point>> poligonos(poligonosidx.size());
    for (int i = 0; i < poligonosidx.size(); i++) {
        for (int idxponto : poligonosidx[i]) {
            poligonos[i].push_back(vertices[idxponto]);
        }
        if (*poligonosidx[i].begin() != *prev(poligonosidx[i].end())) {
            poligonos[i].push_back(vertices[*poligonosidx[i].begin()]);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        bool flag = false;
        for (vector<point>& poligono : poligonos) {
            int res = insidePolygon(point(x,y), poligono);
            if (res >= 0) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << 'P';
        }
        else {
            cout << 'G';
        }
    }
    cout << '\n';
    return 0;
}
