// 注意数据范围
#include <iostream>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    long long ans1 = 0, ans2 = 0;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(i == j) {
                ans1 += (n - i + 1) * (m - i + 1);
            } else {
                ans2 += (n - i + 1) * (m - j + 1);
            }
        } 
    }

    cout << ans1 << " " << ans2 << endl;

    return 0;
}