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
    int t;
    cin >> t;
    while (t--) {
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        vector<bool> used(n+1);
        int qntdnums = r-l+1;
        vector<int> maiorsoma(n + 1);
        vector<int> menorsoma(n + 1);
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = 1; j <= i; j++) {
                sum += j;
            }
            menorsoma[i] = sum;
            sum = 0;
            for (int j = n; j > n - i; j--) {
                sum += j;
            }
            maiorsoma[i] = sum;
        }
        if (menorsoma[qntdnums] > s || maiorsoma[qntdnums] < s) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> res(qntdnums);
        int sumAtual = 0;
        for (int i = 1; i <= qntdnums; i++) {
            res[i-1] = i;
            sumAtual += i;
        }
        int aumento = 0;
        int maxsum = ((n+1)*n)/2;
        int j = 0;
        for (; aumento < n - res[qntdnums-1]; aumento++) {
            sumAtual = sumAtual + aumento*qntdnums;
            j = 0;
            for (int i = sumAtual; i <= maxsum && j <= n - res[qntdnums-1]; i++, j++) {
                if (i == s) {
                    sumAtual = i;
                    break;
                }
            }
            if (sumAtual == s) break;
        }
        res[qntdnums-1] += j;
        set<int> res1;
        for (int val : res) {
            res1.insert(val+aumento);
        }

        int countvalue = 1;
        int i = 1;
        while (i < l) {
            while (res1.find(countvalue) != res1.end()) {
                countvalue++;
            }
            cout << countvalue << ' ';
            countvalue++;
            i++;
        }
        i = r+1;
        for (int value : res1) {
            cout << value << ' ';
        }
        while (i <= n) {
            while (res1.find(countvalue) != res1.end()) {
                countvalue++;
            }
            cout << countvalue << ' ';
            countvalue++;
            i++;
        }
        cout << '\n';
    }

    return 0;
}
