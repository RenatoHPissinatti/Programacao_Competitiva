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
    string s;
    cin >> s;
    int menor = 1;
    vector<int> seq;
    bool charAtualehR = (s[0] == 'R');
    int seqR = 0;
    int seqL = 0;
    char last = 'b';
    for (char c : s) {
        if (c == 'R') {
            seqR++;
            if (seqL > 0) {
                seq.push_back(seqL);
                seqL = 0;
            }
        }
        else {
            seqL++;
            if (seqR > 0) {
                seq.push_back(seqR);
                seqR = 0;
            }
        }
    }
    if (seqR > 0) {
        seq.push_back(seqR);
    }
    if (seqL > 0) {
        seq.push_back(seqL);
    }
    vector<bool> visited (n+1, false);
    vector<int> res(n+1);
    for (int i = 1; i <= n; i++) {
        res[i] = i;
    }

    for (int i = 0; i < seq.size(); i++) {
        int sequencia = seq[i];
        if (charAtualehR) {
            charAtualehR = !charAtualehR;
            menor += sequencia;
        }
        else {
            int futuromenor = menor + sequencia;
            int ftsq = sequencia;
            for (int i = 0; i <= ftsq; i++) {
                res[i+menor] = i+menor+sequencia;
                sequencia-=2;
            }
            menor = futuromenor;
            charAtualehR = !charAtualehR;
        }
    }
    for (int i = 1; i <=n; i++) {
        cout << res[i] << '\n';
    }
    return 0;
}
