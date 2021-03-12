#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string y[5] = {"HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"}; 
int z[5] = {2, 4, 7, 25, 110};

struct P {
    string name;
    string pos;
    int banggong;
    int grade;

    int flag;
};

bool cmp1 (P a, P b);
bool cmp2 (P a, P b);

int main () {
    P ally[115];
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        string a, b;
        int c, d;
        cin >> a >> b >> c >> d;
        ally[i].name = a;
        ally[i].pos = b;
        ally[i].banggong = c;
        ally[i].grade = d;
    }

    ally[0].flag = -2;
    ally[1].flag = ally[2].flag = -1;

    stable_sort(ally + 3, ally + n, cmp1);

    for(int i = 3, j = 0; i < n; ++i) {
        if(z[j] <= 0) j++;

        ally[i].flag = j;
        z[j]--;
    }
    stable_sort(ally + 3, ally + n, cmp2);

    if(ally[1].grade < ally[2].grade) {
        string tmp;
        tmp = ally[1].name;
        ally[1].name = ally[2].name;
        ally[2].name = tmp;

        int t;
        t = ally[1].grade;
        ally[1].grade = ally[2].grade;
        ally[2].grade = t;
    }

    cout << ally[0].name << " " << "BangZhu" << " " << ally[0].grade << endl;
    cout << ally[1].name << " " << "FuBangZhu" << " " << ally[1].grade << endl;
    cout << ally[2].name << " " << "FuBangZhu" << " " << ally[2].grade << endl;

    for(int i = 3; i < n; ++i) {
        cout << ally[i].name << " " << y[ally[i].flag] << " " << ally[i].grade << endl;
    }
    return 0;
}

bool cmp1 (P a, P b) {
    return a.banggong > b.banggong;
}

bool cmp2(P a, P b) {
    return (a.flag < b.flag || (a.flag == b.flag && a.grade > b.grade));
}