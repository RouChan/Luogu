// 采用堆排序，无法满足最坏情况
#include <iostream>
using namespace std;

int ans[5000005];

void Upward(int n);
void Downward(int n, int k);
inline void Swap(int &a, int &b);

int main () {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> ans[i];
    }

    Upward(n);

    for(int i = 1; i <= k; ++i) {
        swap(ans[1], ans[n - i + 1]);
        Downward(n - i, 1);
    }

    cout << ans[1] << endl;
    // for(int i = 1; i <= n; ++i) {
    //     cout << ans[i] << " ";
    // }

    return 0;
}

void Upward(int n) {
    for(int t = n / 2; t > 0; --t) {
        if(ans[t] > ans[2 * t] || (2 * t + 1 <= n && ans[t] > ans[2 * t + 1])) {
            if(ans[2 * t] > ans[2 * t + 1]) {
                swap(ans[t], ans[2 * t + 1]);
                Downward(n, 2 * t + 1);
            } else {
                swap(ans[t], ans[2 * t]);
                Downward(n, 2 * t);
            }
        }
    }
}

void Downward(int n, int k) {
    bool HaveL = (2 * k < n);
    bool HaveR = (2 * k < n); 
    if(HaveL && HaveR) {
        if(ans[k] > ans[2 * k + 1] || ans[k] > ans[2 * k]) {
            if(ans[2 * k + 1] > ans[2 * k]) {
                swap(ans[k], ans[2 * k]);
                Downward(n, 2 * k);
            } else {
                swap(ans[k], ans[2 * k + 1]);
                Downward(n, 2 * k + 1);
            }
        }
    } else if (HaveL && ans[k] > ans[2 * k]) {
        swap(ans[k], ans[2 * k]);
        Downward(n, 2 * k);
    } 
}

inline void Swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
    return ;
}