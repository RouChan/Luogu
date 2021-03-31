#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct A {
    int num, y, m, d;
    string name;

    bool operator<(A &other) const {
        int sumA = y * 10000 + m * 100 + d;
        int sumB = other.y * 10000 + other.m * 100 + other.d;

        if(sumA > sumB) {
            return false;
        } else if (sumA < sumB) {
            return true;
        } else {
            if(num > other.num) {
                return true;
            } else {
                return false;
            }
        }
    }
} stu[105];

bool cmp(A a, A b) {
    return a < b;
}

int main () {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> stu[i].name >> stu[i].y >> stu[i].m >> stu[i].d;
        stu[i].num = i;
    }

    sort(stu + 1, stu + 1 + n, cmp);

    for(int i = 1; i <= n; ++i) {
        cout << stu[i].name << endl;
    }

    return 0;
}