#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int x[10005];

void Swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int main () {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x, x + n);

    long long ans = 0;

    for(int i = 0; i < n - 1; ++i) {
        x[i + 1] += x[i];
        ans += x[i + 1];

        // sort(x + i + 1, x + n);
        for(int t = i + 2; t < n; ++t) {
            if(x[t] >= x[t - 1]) break;
            else Swap(x[t], x[t - 1]);
        }
    }
    cout << ans << endl;

    return 0;
}