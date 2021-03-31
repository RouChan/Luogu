#include <iostream>
#include <string>
using namespace std;

int map[55][3];        // W, B, R

inline int Sub(int x, int y, int z, int n);

int main () {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        for(int j = 0; j < m; ++j) {
            if(str[j] == 'W') {
                map[i][0]++;
            } else if (str[j] == 'R') {
                map[i][2]++;
            } else if (str[j] == 'B') {
                map[i][1]++;
            }
        } 
    }

    int ans = n * m;
    for(int x = 1; x <= n - 2; ++x) {
        for(int y = 1; y <= n - x - 1; ++y) {
            int t = Sub(x, y , n - x - y, n);
            if(ans > t) ans = t;
        }
    }

    cout << ans << endl;

    return 0;
}

inline int Sub(int x, int y, int z, int n) {
    int ans = 0;
    for(int i = 1; i <= x; ++i) {
        ans += map[i][1] + map[i][2];
    }

    for(int i = 1; i <= y; ++i) {
        ans += map[x + i][0] + map[x + i][2];
    }

    for(int i = 1; i <= z; ++i) {
        ans += map[x + y + i][0] + map[x + y + i][1];
    }

    return ans;
}