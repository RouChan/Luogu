#include <iostream>
using namespace std;

int ans[5000005];

void Swap(int i, int j);
int QuickSort(int i, int j);

int main () {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; ++i) {
        cin >> ans[i];
    }

    int i = 0, j = n - 1;

    while(1) {
        int t = QuickSort(i, j);

        if(t == k) {
            cout << ans[k] << endl;
            break;
        } else if (t < k) {
            if(t == i) t++;
            i = t;
        } else {
            if(t == j) t--;
            j = t;
        }
    }

    // cout << QuickSort(0, n - 1);

    return 0;
}

void Swap(int i, int j) {
    int t = ans[i];
    ans[i] = ans[j];
    ans[j] = t;
}

int QuickSort(int i, int j) {       // ij为下标
    while(i != j) {
        for(; i < j; j--) {
            if(ans[j] < ans[i]) {
                Swap(i, j);
                break;
            }
        }
        for(; i < j; ++i) {
            if(ans[i] > ans[j]) {
                Swap(i, j);
                break;
            }
        }
    }
    return i;
}