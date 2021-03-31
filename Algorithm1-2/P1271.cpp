#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int ans[MAX];

int main () {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        ans[tmp]++;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < ans[i]; ++j) {
            cout << i << " ";
        }
    }

    return 0;
}