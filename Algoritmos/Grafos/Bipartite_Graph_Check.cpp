// inside int main ()

int s = 0;
queue<int> q;
q.push(s);

vi color(n, INF);
color[s] = 0;

bool isBipartite = true;

while(!q.empty() && isBipartite) {
    int u = q.front();
    q.pop();

    for (auto &v : AL[u]) {
        if (color[v] == INF) {
            color[v] = 1 - color[u];
            q.push(v);
        } else if (color[v] == color[u]) {
            isBipartite = false;
            break;
        }
    }
}