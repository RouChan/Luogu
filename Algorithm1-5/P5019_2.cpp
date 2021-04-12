#include <iostream>
using namespace std;
int x[100005];

int main () {
    ios::sync_with_stdio(0);
    long ans = 0;
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for(int i = 2; i <= n; ++i) {
        if(x[i] > x[i - 1]) ans += x[i] - x[i - 1];
    }

    ans += x[1];
    cout << ans << endl;

    return 0;
}