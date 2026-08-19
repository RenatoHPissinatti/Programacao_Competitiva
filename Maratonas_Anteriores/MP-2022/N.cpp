#include <bits/stdc++.h>

#include <utility>
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

void check(multiset<ll>& msetj, multiset<ll>& possij, int j, ll& somaAtual) {
    if (msetj.size() != j) {
        msetj.insert(*prev(possij.end()));
        somaAtual += *prev(possij.end());
        possij.erase(prev(possij.end()));
    }
    if (!possij.empty() && *prev(possij.end()) > *msetj.begin()) {
        ll pj = *prev(possij.end());
        ll mj = *msetj.begin();
        somaAtual -= mj;
        somaAtual += pj;
        msetj.erase(msetj.begin());
        possij.erase(prev(possij.end()));
        msetj.insert(pj);
        possij.insert(mj);
    }
}
void addthis(ll valor, multiset<ll>& msetj, multiset<ll>& possij, int j, ll& somaAtual) {
    possij.insert(valor);
    check(msetj, possij, j, somaAtual);
}

void erasethis(ll valor, multiset<ll>& msetj, multiset<ll>& possij, int j, ll& somaAtual) {
    auto it = msetj.find(valor);
    if (it != msetj.end()) {
        somaAtual -= *it;
        msetj.erase(it);
    }
    else {
        it = possij.find(valor);
        if (it != possij.end()) {
            possij.erase(it);
        }
    }
}




int main() {
    fastio;
    int n;
    cin >> n;
    vector<ll> A(n);
    vector<ll> B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    int l, k;
    cin >> k >> l;
    multiset<ll> msetk;
    multiset<ll> msetl;
    multiset<ll> possik;
    multiset<ll> possil;
    ll somaAtual = 0;
    ll maior = 0;
    for (int i = 0; i < k; i++) {
        addthis(A[i], msetk, possik, k, somaAtual);
        addthis(B[i], msetl, possil, l, somaAtual);
        maior = max(maior, somaAtual);
    }

    for (int i = 0; i < k; i++) {
        int jf = n-i-1;
        int ji = k-i-1;
        erasethis(A[ji], msetk, possik, k, somaAtual);
        addthis(A[jf], msetk, possik, k, somaAtual);
        erasethis(B[ji], msetl, possil, l, somaAtual);
        addthis(B[jf], msetl, possil, l, somaAtual);
        maior = max(maior, somaAtual);
    }

    cout << maior << '\n';

    return 0;
}