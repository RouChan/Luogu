#include <iostream>
#include <algorithm>
using namespace std;

struct P {
    int count;
    int chinese;
    int math;
    int eglsh;
} stu[305];

bool cmp(P a, P b);

int main () {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        stu[i].count = i;
        cin >> stu[i].chinese >> stu[i].math >> stu[i].eglsh;
    }

    sort(stu + 1, stu + n + 1, cmp);

    for(int i = 1; i <= ((n >= 5) ? 5 : n); ++i) {
        cout << stu[i].count << " " << stu[i].chinese + stu[i].math + stu[i].eglsh << endl;
    }

    return 0;
}

bool cmp(P a, P b) {
    int aTotal = a.chinese + a.math + a.eglsh;
    int bTotal = b.chinese + b.math + b.eglsh;
    if(aTotal > bTotal) {
        return true;
    } else if (aTotal < bTotal) {
        return false;
    } else {
        if(a.chinese > b.chinese) {
            return true;
        } else if (a.chinese < b.chinese) {
            return false;
        } else {
            return a.count < b.count;
        }
    }
}