#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

const int INF = 1e9;
const ll LINF = LLONG_MAX/4;
const int MOD = 1000000007;
int comp (int a, int b) {
    return a > b;
}
int main() {
    int n, t;
    cin >> n >> t;
    vector<char> a(n);
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        a[i] = c;
    }

    for (int i = 0; i < n; ++i) {
        int count = i;
        if (a[i] == 'G') {
            for (int j = 0; j < t; ++j) {
                if (count < 1 || a[count-1] == 'G') break;
                swap(a[count], a[count-1]);
                --count;
            }
        }
    }
    for (char c : a) cout << c;
    cout << '\n';

    return 0;
}
