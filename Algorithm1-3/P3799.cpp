#include <iostream>
using namespace std;

int a[5005];

int main () {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    long long count = 0;

    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        a[t]++;
    }

    for(int i = 1; i <= 5000; ++i) {
        if(a[i] > 2) {
            count += (a[i] * (a[i] - 1) * (a[i] - 2) / 6) * a[0];   // 0+3边

            if(i % 2 == 0) {
                for(int j = 1; j < i / 2; ++j) {
                    count += (a[i] * (a[i] - 1) / 2) * a[j] * a[i - j];
                }
                count += (a[i] * (a[i] - 1) / 2) * (a[i / 2] * (a[i / 2] - 1) / 2);
            } else {
                for(int j = 1; j <= i / 2; ++j) {
                    count += (a[i] * (a[i] - 1) / 2) * a[j] * a[i - j];
                }
            }

        } else if(a[i] == 2) {
            if(i % 2 == 0) {
                for(int j = 1; j < i / 2; ++j) {
                    count += a[j] * a[i - j];
                }
                count += (a[i / 2] * (a[i / 2] - 1) / 2);
            } else {
                for(int j = 1; j <= i / 2; ++j) {
                    count += a[j] * a[i - j];
                }
            }
        }
    }

    cout << count % (long long)(1.e9 + 7) << endl;

    return 0;
}