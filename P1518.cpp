// 设置专属值判断死循环

#include <iostream>
using namespace std;

int map[11][11];        // 0无1障碍
bool flag[160000];

struct A {
    int x, y, dir;      // 0上1右2下3左

};

bool IsLegal(int x, int y) {
    return (x >= 0 && x < 10 && y >= 0 && y < 10 && map[x][y] == 0);
}
void GetNext(A &t);

int main () {
    char t;
    A F, C;
    F.dir = C.dir = 0;
    int timeCount = 0;              // 时间
    for(int i = 1; i <= 100; ) {
        cin >> t;
        if(t == '.') {
            ++i;
            continue;
        } else if (t == '*') {
            map[(i - 1) / 10][(i - 1) % 10] = 1;
            ++i;
        } else if (t == 'F') {
            F.x = (i - 1) / 10;
            F.y = (i - 1) % 10;
            ++i;
        } else if (t == 'C') {
            C.x = (i - 1) / 10;
            C.y = (i - 1) % 10;
            ++i;
        }
    }

    int k = 0;

    while(1) {
        if(F.x == C.x && F.y == C.y) break;
        k = C.x + 10 * C.y + 100 * F.x + 1000 * F.y + 10000 * C.dir + 40000 * F.dir;
        if(flag[k]) {
            timeCount = 0;
            break;
        } else {
            flag[k] = true;
        }


        GetNext(F);
        GetNext(C);

        timeCount++;
    }

    cout << timeCount << endl;

    return 0;
}

void GetNext(A &t) {
    if(t.dir == 0 && IsLegal(t.x - 1, t.y)) {
        t.x--;
    } else if (t.dir == 0 && !IsLegal(t.x - 1, t.y)) {
        t.dir++;
    } else if (t.dir == 1 && IsLegal(t.x, t.y + 1)) {
        t.y++;
    } else if (t.dir == 1 && !IsLegal(t.x, t.y + 1)) {
        t.dir++;
    } else if (t.dir == 2 && IsLegal(t.x + 1, t.y)) {
        t.x++;
    } else if (t.dir == 2 && !IsLegal(t.x + 1, t.y)) {
        t.dir++;
    }else if (t.dir == 3 && IsLegal(t.x, t.y - 1)) {
        t.y--;
    } else if (t.dir == 3 && !IsLegal(t.x, t.y - 1)) {
        t.dir = 0;
    }
}