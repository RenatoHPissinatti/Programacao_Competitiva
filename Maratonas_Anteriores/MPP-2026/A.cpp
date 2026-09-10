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

struct balada {
    int ticket;
    int musica;
    int nextMusicaIndex;

    bool operator <( const balada& other ) const {
        return ticket < other.ticket;
    }
};

int main() {
    fastio;
    int n, q;
    cin >> n >> q;
    int a, b;
    vector<balada> baladas(n);

    cin >> a >> b;
    baladas[0] = {a, b, 0};
    vector<int> nextmusica = {0};
    int musicaAtual = b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        if (b != musicaAtual) {
            musicaAtual = b;
            nextmusica.push_back(i);
        }
        baladas[i] = { a, b, static_cast<int>(nextmusica.size()) -1};
    }

    auto comp = [](const balada& bal, const int value) {
        return bal.ticket > value;
    };

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        ll index = lower_bound(baladas.begin(), baladas.end(), a, comp) - baladas.begin();
        if (index == n) {
            cout << -1 << '\n';
            continue;
        }

        if (baladas[index].musica != b) {
            cout << index + 1 << '\n';
        }
        else {
            index = baladas[index].nextMusicaIndex;
            index++;
            if (index >= nextmusica.size()) {
                cout << -1 << '\n';
            }
            else {
                cout << nextmusica[index] + 1 << '\n';
            }
        }
    }
    return 0;
}
