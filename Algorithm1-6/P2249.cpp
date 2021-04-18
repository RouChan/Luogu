#include <iostream>
#include <map>
using namespace std;
long ans = 0;
typedef long long LL;
LL a[200001];
map<LL, LL> m;

int main () {
    ios::sync_with_stdio(0);

    int n, c;
    cin >> n >> c;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        m[a[i]]++;
        a[i] -= c;
    }

    for(int i = 1; i <= n; ++i) {
        ans += m[a[i]];
    }
    cout << ans << endl;

    return 0;
}