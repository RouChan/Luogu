#include <iostream>
using namespace std;

long x[100005], n, m;

bool IsLegal(long s);

int main () {
    ios::sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    long i = 1, j = 1000000000, ans = 0;
    while(i != j) {
        long mid = (i + j) / 2;
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

bool IsLegal(long s) {
    long tmp = 0, count = 0;
    for(int i = 1; i <= n; ++i) {
        if(x[i] > s) return false;

        tmp += x[i];
        if(tmp > s) {
            tmp = x[i];
            count++;
        } 
    }

    if(count <= m - 1)  return true;
    else            return false;
}