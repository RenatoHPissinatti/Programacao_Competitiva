//
// Created by Usuario on 18/08/2026.
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

struct point {
    int x, y;
    point() : x(0), y(0) {}
    point (int _x, int _y) : x(_x), y(_y) {}
    bool operator == (point other) const {
        if (x == other.x && y == other.y) {
            return true;
        }
        return false;
    }
    bool operator < (point other) const {
        if (y == other.y) {
            return x < other.x;
        }
        return y < other.y;
    }
};


struct vec {
    int x, y;
    vec(int _x, int _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x-a.x, b.y-a.y);
}
int cross(vec a, vec b) {
    return a.x*b.y - a.y*b.x;
}

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) >= 0;
}

vector<point> convexhull(vector<point>& pts) {
    int n = pts.size();
    int k = 0;
    vector<point> h(2*n);
    sort(all(pts));
    for (int i = 0; i < n; i++) {
        while ((k>=2)&& !ccw(h[k-2], h[k-1], pts[i])) k--;
        h[k] = pts[i];
        k++;
    }
    for (int i = n-2, t = k+1; i >=0; i--) {
        while ((k>=t) && !ccw(h[k-2], h[k-1], pts[i])) k--;
        h[k] = pts[i];
        k++;
    }
    h.resize(k);
    return h;
}


int main() {
    fastio;
    int n; cin >> n;

    int x, y;
    vector<point> entrada;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        entrada.push_back(point(x, y));
    }
    vector<point> points = entrada;
    vector<point> ch = convexhull(points);
    map<point, bool> res;
    for (point ponto : ch) {
        res[ponto] = true;
    }
    for (int i = 0; i < n; i++) {
        if (res[entrada[i]]) {
            cout << i+1 << ' ';
        }
    }
    cout << '\n';

    return 0;
}
