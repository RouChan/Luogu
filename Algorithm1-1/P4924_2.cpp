#include <iostream>
using namespace std;

const int MAX = 505;
int matrix[MAX][MAX], f[MAX][MAX];

int main () {
    int n, m;
    cin >> n >> m;
    int tmp = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            matrix[i][j] = tmp++;
        }
    }

    for(int i = 0; i < m; ++i) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        if(z == 0) {         // 逆时针
            for(int t = x - r; t <= x + r; ++t) {
                for(int k = y - r; k <= y + r; ++k) {
                    f[x - y + k][y - t + x] = matrix[t][k];
                }
            }
            for(int t = x - r; t <= x + r; ++t) {
                for(int k = y - r; k <= y + r; ++k) {
                    matrix[t][k] = f[t][k];
                }
            }
        } else {        // 顺时针
            for(int t = x - r; t <= x + r; ++t) {
                for(int k = y - r; k <= y + r; ++k) {
                    f[x + y - k][y + t - x] = matrix[t][k];
                }
            }
            for(int t = x - r; t <= x + r; ++t) {
                for(int k = y - r; k <= y + r; ++k) {
                    matrix[t][k] = f[t][k];
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}