#include <iostream>
#include <math.h>
using namespace std;

int x[25];
int pos[25];
long Count = 0;

inline void PickNum(int, int, int, int);
inline void IsPrime(int);

int main () {
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    PickNum(0, n - 1, k, 0);
    cout << Count << endl;

    return 0;
}

inline void PickNum(int from, int to, int num, int flag) {
    if(num == 0) {
        int m = 0;
        for(int i = 0; i < flag; ++i) {
            m += x[pos[i]];
        }
        IsPrime(m);

        return ;
    }

    for(int i = from; to - i + 1 >= num; ++i) {
        pos[flag] = i;
        PickNum(i + 1, to, num - 1, flag + 1);
    }
}

inline void IsPrime(int x) {
    int max = sqrt(x);
    for(int i = 2; i <= max; ++i) {
        if(x % i == 0) return ;
    }
    Count++;
    return ;
}