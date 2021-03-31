#include <iostream>
#include <algorithm>
using namespace std;

int ans[5000005];

int main () {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> ans[i];
    }
    sort(ans, ans + n);
    cout << ans[m] << endl;
    return 0;
}