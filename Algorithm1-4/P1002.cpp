#include <iostream>
using namespace std;
long long ans =  0;
int a, b, c, d;
bool map[25][25];

inline void Count(int n, int m);

int main () {
    ios::sync_with_stdio(0);

    cin >> a >> b >> c >> d;

    for(int i = 0; i <= b; ++i) {
        map[a + 1][i] = true;
    }
    for(int i = 0; i <= a; ++i) {
        map[i][b + 1] = true;
    }

    if(c + 2 <= a && d + 1 <= b) map[c + 2][d + 1] = true;
    if(c + 2 <= a && d - 1 >= 0) map[c + 2][d - 1] = true;
    if(c + 1 <= a && d + 2 <= b) map[c + 1][d + 2] = true;
    if(c + 1 <= a && d - 2 >= 0) map[c + 1][d - 2] = true;
    if(c - 1 >= 0 && d - 2 >= 0) map[c - 1][d - 2] = true;
    if(c - 1 >= 0 && d + 2 <= b) map[c - 1][d + 2] = true;
    if(c - 2 >= 0 && d - 1 >= 0) map[c - 2][d - 1] = true;
    if(c - 2 >= 0 && d + 1 <= b) map[c - 2][d + 1] = true;
    map[c][d] = true;

    Count(0, 0);
    cout << ans << endl;

    return 0;
}

inline void Count(int n, int m) {
    if(n == a && m == b) {
        ans++;
        return;
    }
    else if (n > a || m > b) return;
    else if(map[n][m] == true) return;
    else {
        Count(n + 1, m);
        Count(n, m + 1);
    }
}