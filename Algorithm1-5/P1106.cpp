#include <iostream>
#include <string>
using namespace std;

#define min(x, y) (x > y ? y : x)

string str;
bool ans[255];
int s;

inline void Pick(int, int, int);

int main () {
    ios::sync_with_stdio(0);

    int k;
    cin >> str >> k;
    s = str.size();
    Pick(0, k, s - k);

    int flag = 0;
    while(!(ans[flag] && str[flag] != '0')) {
        flag++;
        if(flag == s) break;
    }

    if(flag == s) {
        cout << '0' << endl;
    } else {
        for(int i = flag; i < s; ++i) {
            if(ans[i]) cout << str[i];
        }
        cout << endl;
    }

    return 0;
}

inline void Pick(int from, int to, int k) {
    if(k == 0) return ;
    int min = from;
    for(int i = from + 1; i <= to; ++i) {
        if(str[i] < str[min]) min = i;
    } 
    ans[min] = true;
    Pick(min + 1, min(to + 1, s - 1), k - 1);
}