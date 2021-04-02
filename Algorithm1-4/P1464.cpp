#include <iostream>
#include <string>
using namespace std;

long ans[10001] = {1};
inline int GetPos(int, int, int);
inline int GetInput(string, string, string);

int main () {
    ios::sync_with_stdio(0);

    for(int i = 0; i <= 20; ++i) {
        for(int j = 0; j <= 20; ++j) {
            for(int k = 0; k <= 20; ++k) {
                ans[i * 21 * 21 + j * 21 + k] = ans[GetPos(i, j, k)];
            }
        }
    }
    // cout << "YES" << endl;

    string a, b, c;
    int pos;
    while(cin >> a >> b >> c) {
        pos = GetInput(a, b, c);
        if(pos == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans[pos] << endl;
    }


    return 0;
}

inline int GetPos(int a, int b, int c) {
    if(a == 0 || b == 0 || c == 0) {
        return 0;
    } else if (a > 20 || b > 20 || c > 20) {
        return 20 * 21 * 21 + 20 * 21 + 21;
    } else if (a < b && b < c) {
        ans[10000] = ans[a * 21 * 21 + 21 * b + c - 1] + ans[a * 21 * 21 + (b - 1) * 21 + c - 1] - ans[a * 21 * 21 + (b - 1) * 21 + c];
        return 10000;
    } else {
        ans[10000] = ans[(a - 1) * 21 * 21 + b * 21 + c] + ans[(a - 1) * 21 * 21 + (b - 1) * 21 + c] + ans[(a - 1) * 21 * 21 + b * 21 + (c - 1)] - ans[(a - 1) * 21 * 21 + (b - 1) * 21 + c - 1];
        return 10000;
    }
}

inline int GetInput(string a, string b, string c) {
    if(a == "-1" && b == "-1" && c == "-1") {
        return -1;          // End of Input
    } else if (a[0] == '-' || b[0] == '-' || c[0] == '-') {
        return 0;
    } else if (a.size() > 2 || b.size() > 2 || c.size() > 2){
        return 20 * 21 * 21 + 20 * 21 + 20;
    } else {
        int x, y, z;
        x = y = z = 0;
        for(int i = 0; i < a.size(); ++i) {
            x *= 10;
            x += a[i] - '0';
        }
        for(int i = 0; i < b.size(); ++i) {
            y *= 10;
            y += b[i] - '0';
        }
        for(int i = 0; i < c.size(); ++i) {
            z *= 10;
            z += c[i] - '0';
        }
        if(x > 20 || y > 20 || z > 20) return 20 * 21 * 21 + 20 * 21 + 20;
        else return x * 21 * 21 + y * 21 + z;
    }
}