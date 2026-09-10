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

void possibleStrings(string& sentrada, set<string>& numeros, unordered_map<string, bool>& possible) {
    vector<map<string, bool>> visited(13);
    queue<string> fila;
    fila.push(sentrada);

    while (!fila.empty()) {
        string s = fila.front();
        fila.pop();
        map<string, bool>& visitedProx = visited[s.size() + 1];
        ll tam = s.size();
        if (visitedProx.empty()) {
            map<string, bool> emptymap;
            visited[tam] = emptymap;
        }
        if (s.size() == 11) {
            string ddd = "";
            ddd+=s[0];
            ddd+=s[1];
            ddd+=s[2];

            if (possible[ddd]) {
                numeros.insert(s);
            }
            else {
                possible.erase(ddd);
            }
            continue;
        }
        for (int i = 0; i <= s.size(); i++) {
            string newS = s;
            newS.insert(next(newS.begin(), i), '1');
            if (!visitedProx[newS]) fila.push(newS);
            newS[i] = '9';
            if (!visitedProx[newS]) fila.push(newS);
        }
    }
}


int main() {
    fastio;
    string s;

    cin >> s;
    int tam = s.size();

    // 119, 129, 139, 149, 159, 169, 179, 189, 199
    set<string> numeros;
    unordered_map<string, bool> possible;
    possible["119"] = true;
    possible["129"] = true;
    possible["139"] = true;
    possible["149"] = true;
    possible["159"] = true;
    possible["169"] = true;
    possible["179"] = true;
    possible["189"] = true;
    possible["199"] = true;

    int numfaltando = 11 - tam;
    if (numfaltando < 0) {
        cout << 0 << '\n';
        return 0;
    }
    possibleStrings(s, numeros, possible);
    cout << numeros.size() << '\n';
    for (string ns : numeros) {
        cout << ns << '\n';
    }

    return 0;
}
