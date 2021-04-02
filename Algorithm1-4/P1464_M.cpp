// 记忆宏
// 超过范围的数字不管
#include <iostream>
using namespace std;

#define Count(x,y,z) (ans[x][y][z] ? ans[x][y][z] : ans[x][y][z] = GetValue(x, y, z))

long long ans[25][25][25];
inline int GetValue(int, int, int);


int main () {
    ios::sync_with_stdio(0);
    int a, b, c;
    while(1) {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        if(a > 20) a = 21;
        if(b > 20) b = 21;
        if(c > 20) c = 21;

        cout << GetValue(a,b,c) << endl;
    }

    return 0;
}

inline int GetValue(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    else if (a > 20 || b > 20 || c > 20) return Count(20, 20, 20);
    else if (a < b && b < c) return Count(a, b, c-1) + Count(a, b-1, c-1) - Count(a, b - 1, c);
    else ans[a][b][c] = Count(a - 1, b, c) + Count(a - 1, b - 1, c) + Count(a - 1, b , c - 1) - Count(a - 1, b - 1, c - 1);
    return ans[a][b][c];
}