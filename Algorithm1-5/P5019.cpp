#include <iostream>
using namespace std;

long long ans = 0;
int x[100005], n;

inline void Count(int, int);

int main () {
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    Count(1, n);
    cout << ans << endl;

    return 0;
}

inline void Count(int from, int to) {
    if(from > n || to > n || from < 1 || to < 1 || from > to) {
        return;
    } else {
        int mint = from;
        for(int i = from; i <= to; ++i) {
            if(x[mint] > x[i]) mint = i;
        }

        ans += x[mint];

        int m = x[mint];
        for(int i = from; i <= to; ++i) {
            x[i] -= m;
        }
        
        Count(from, mint - 1);
        Count(mint + 1, to);
    }
}