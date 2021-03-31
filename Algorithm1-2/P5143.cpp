#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

struct P {
    int x, y, z;
} Ps[50005];

bool cmp(P a, P b) {
    return a.z < b.z;
}

int main () {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> Ps[i].x >> Ps[i].y >> Ps[i].z;
    }

    sort(Ps + 1, Ps + 1 + n, cmp);

    double ans = 0;

    for(int i = 2; i <= n; ++i) {
        double a = Ps[i].x - Ps[i - 1].x;
        double b = Ps[i].y - Ps[i - 1].y;
        double c = Ps[i].z - Ps[i - 1].z;

        a *= a;
        b *= b;
        c *= c;
        ans += sqrt(a + b + c);
    }

    cout << fixed << setprecision(3) << ans << endl;

    return 0;
}