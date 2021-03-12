#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int x[] = {1, 2, 2, 4, 7, 25, 110};
string y[] = {"BangZhu", "FuBangZhu", "HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};

struct P {
    int count;  // 输入顺序

    string name;
    int pos;
    long long banggong;
    int grade;
};

bool cmp1(P a, P b) {
    if(a.banggong == b.banggong) return a.count < b.count;
    else return a.banggong > b.banggong;
}

bool cmp2(P a, P b) {
    if(a.pos < b.pos) {
        return true;
    } else if (a.pos == b.pos && a.grade > b.grade) {
        return true;
    } else if (a.pos == b.pos && a.grade == b.grade && a.count < b.count) {
        return true;
    }
    
    return false;
}

int main () {
    P ans[115];
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string a, b;
        int c, d;
        cin >> a >> b >> c >> d;

        ans[i].count = i;
        ans[i].name = a;        
        ans[i].banggong = c;
        ans[i].grade = d;
    }

    ans[0].pos = 0;
    ans[1].pos = ans[2].pos = 1;

    sort(ans + 3, ans + n, cmp1);

    for(int i = 3, j = 2; i < n; ++i) {
        if(x[j] <= 0) ++j;

        ans[i].pos = j;
        x[j]--;
    }

    sort(ans + 1, ans + n, cmp2);

    for(int i = 0; i < n; ++i) {
        cout << ans[i].name << " " << y[ans[i].pos] << " " << ans[i].grade << endl;
    }

    return 0;
}