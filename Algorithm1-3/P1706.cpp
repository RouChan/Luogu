#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main () {
    ios::sync_with_stdio(false);

    int n, x[10];
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        x[i] = i;
    }

    do{
        for(int i = 1; i <= n; ++i) {
            cout << setw(5) << x[i];
        }
        cout << endl;
    } while(next_permutation(x + 1, x + n + 1));

    return 0;
}