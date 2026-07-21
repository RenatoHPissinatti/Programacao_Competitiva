#include <iostream>
#include <vector>

using namespace std;

void crivoEratostenes(int n, std::vector<bool>& primo) {


    primo[0] = primo[1] = false;


    for (int p = 2; p * p <= n; p++) {

        if (primo[p]) {

            for (int i = p * p; i <= n; i += p)
                primo[i] = false;
        }
    }


}

int main() {
    int n = 1299709;

    vector<bool> primo(n + 1, true);

    crivoEratostenes(n,primo);

    int a;
    while (cin>>a && a!=0) {
        if (primo[a]) {
            cout<<0<<endl;
        }
        else {
            int c,d;
            c=a;
            d=a;
            while (!primo[c]) {
                c--;
            }
            while (!primo[d]) {
                d++;
            }

            int res;
            res=d-c;
            cout<<res<<endl;
        }
    }
    return 0;
}