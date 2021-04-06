// 采用交叉相乘的方式比较大小，避免精度问题
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Coin {
    double m, v, w;
} x[105];

bool cmp (Coin A, Coin B) {
    return A.w > B.w;
}

int main () {
    ios::sync_with_stdio(0);

    int n, T;
    cin >> n >> T;

    for(int i = 0; i < n; ++i) {
        cin >> x[i].m >> x[i].v;
        x[i].w = x[i].v / x[i].m;
    }

    sort(x, x + n, cmp);

    double t = 0, V = 0;
    for(int i = 0; i < n; ++i) {
        int tmp = (T - t < x[i].m ? T - t : x[i].m);
        t += tmp;
        V += tmp * x[i].w;
    }

    cout << fixed << setprecision(2) << V << endl;

    return 0;
}