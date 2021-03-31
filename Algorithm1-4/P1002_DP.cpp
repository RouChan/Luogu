#include <iostream>
using namespace std;
int a, b, c, d;
long long map[25][25];

inline void Count(int n, int m);

int main () {
    ios::sync_with_stdio(0);

    cin >> a >> b >> c >> d;

    for(int i = 0; i <= b; ++i) {
        map[a + 1][i] = -1;
    }
    for(int i = 0; i <= a; ++i) {
        map[i][b + 1] = -1;
    }

    if(c + 2 <= a && d + 1 <= b) map[c + 2][d + 1] = -1;
    if(c + 2 <= a && d - 1 >= 0) map[c + 2][d - 1] = -1;
    if(c + 1 <= a && d + 2 <= b) map[c + 1][d + 2] = -1;
    if(c + 1 <= a && d - 2 >= 0) map[c + 1][d - 2] = -1;
    if(c - 1 >= 0 && d - 2 >= 0) map[c - 1][d - 2] = -1;
    if(c - 1 >= 0 && d + 2 <= b) map[c - 1][d + 2] = -1;
    if(c - 2 >= 0 && d - 1 >= 0) map[c - 2][d - 1] = -1;
    if(c - 2 >= 0 && d + 1 <= b) map[c - 2][d + 1] = -1;
    map[c][d] = -1;

    map[a][b] = 1;


    int t;
    if(a > b) t = b;
    else t = a;

    for(int i = 0; i <= t; ++i) {
        Count(a - i, b - i);
    }
    // map[0]
    cout << map[0][0] << endl;

    // for(int i = 0; i <= a + 1; ++i) {
    //     for(int j = 0; j <= b + 1; ++j) {
    //         cout << map[i][j] << "\t";
    //     }
    //     cout << endl;
    // }

    

    return 0;
}

inline void Count(int n, int m) {
    for(int i = m; i >= 0; --i) {
        if(map[n][i] != -1) {
            if(map[n + 1][i] != -1) map[n][i] += map[n + 1][i];
            if(map[n][i + 1] != -1) map[n][i] += map[n][i + 1];
        }
    }
    for(int i = n - 1; i >= 0; --i) {
        if(map[i][m] != -1) {
            if(map[i + 1][m] != -1) map[i][m] += map[i + 1][m];
            if(map[i][m + 1] != -1) map[i][m] += map[i][m + 1];
        }
    }
}