#include <iostream>
using namespace std;

int l, n, k;
int x[100005];

bool IsLegal(int s);

int main () {
    ios::sync_with_stdio(0);
    cin >> l >> n >> k;

    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    int i = 1, j = 10000000, ans = 0;
    while(i <= j) {
        int mid = (i + j) / 2;
        if(IsLegal(mid)) {
            ans = mid;
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}

bool IsLegal(int s) {
    int count = 0;
    for(int i = 1; i <= n; ++i) {
        count += (x[i] - x[i - 1] - 1) / s;
    }
    if(count <= k)  return true;
    else            return false;
}