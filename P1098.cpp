#include <iostream>
#include <cctype>
#include <cstdio>
#include <string>
using namespace std;

inline void display(char x, char y, int p1, int p2, int p3);
string ans;

int main () {
    char c;
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    cin >> ans;
    int i = ans.size();
    for(int t = 0; t < i; ++t) {
        if(t + 2 < i && ans[t + 1] == '-' && ((isdigit(ans[t]) && isdigit(ans[t + 2])) || (isalpha(ans[t]) && isalpha(ans[t + 2])))) {
            display(ans[t], ans[t + 2], p1, p2, p3);
            t += 2;
        } else {
            cout << ans[t];
        }
    }
    return 0;
}

inline void display(char x, char y, int p1, int p2, int p3) {
    if(y - x == 1) {
        cout << x << y;
        return ;
    } else if(y <= x) {
        cout << x << '-' << y;
        return;
    } else {
        char ans[805];
        int num = (y - x) * p2;
        if(p1 == 3) {
            if(x >= '0' && x <= '9') {
                num = 0;
            } else {
                for(int i = 0; i < num; ++i) {
                    ans[i] = '*';
                }
            }
        } else if (x >= '0' && x <= '9') {
            int t = 0;
            for(char k = x + 1; k != y; k++) {
                for(int i = 0; i < p2; ++i) {
                    ans[t] = k;
                    ++t;
                }
            }
        } else if (p1 == 1) {
            int t = 0;
            for(char k = x + 1; k != y; k++) {
                for(int i = 0; i < p2; ++i) {
                    ans[t] = k;
                    ++t;
                }
            }
        } else if (p1 == 2) {
            int t = 0;
            for(char k = x + 1; k != y; k++) {
                for(int i = 0; i < p2; ++i) {
                    ans[t] = k + 'A' - 'a';
                    ++t;
                }
            }
        }
        cout << x;
        if(p3 == 1) {
            for(int i = 0; i < num; ++i) {
               cout << ans[i]; 
            }
        } else if (p3 == 2) {
            for(int i = num - 1; i >= 0; --i) {
               cout << ans[i]; 
            }
        }
        cout << y;
        return ;
    }
}