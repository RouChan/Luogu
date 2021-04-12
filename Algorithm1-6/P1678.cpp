#include <iostream>
#include <algorithm>
using namespace std;

int school[100005];
long long ans = 0;

int main () {
    ios::sync_with_stdio(0);
    // freopen("/Users/yu_ruchen/Downloads/P1678_3.in", "r", stdin);

    int m, n;
    cin >> m >> n;

    for(int i = 0; i < m; ++i) {
        cin >> school[i];
    }
    sort(school, school + m);

    for(int i = 1; i <= n; ++i) {
        int grade;
        cin >> grade;
        int p = lower_bound(school, school + m, grade) - school;
        if(p == m) {
            ans += grade - school[m - 1];
        } else if(p > 0) {
            ans += (school[p] - grade > grade - school[p - 1] ? grade - school[p - 1] : school[p] - grade);
        } else {
            ans += school[p] - grade;
        }
    }

    cout << ans << endl;
    

    return 0;
}