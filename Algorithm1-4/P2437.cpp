#include <iostream>
#include <string>
using namespace std;

string ans[1005] = {"0", "1", "2"};
inline string Add(string, string);

int main () {
    ios::sync_with_stdio(0);
    for(int i = 3; i <= 1000; ++i){
        ans[i] = Add(ans[i - 1], ans[i - 2]);
    }
    int m, n;
    cin >> m >> n;

    if(m > n)   cout << 0 << endl;
    else        cout << ans[n - m] << endl;

    return 0;
}

inline string Add(string a, string b) {
    int t = (a.size() > b.size() ? a.size() + 1 : b.size() + 1);
    for(int i = a.size(); i < t; ++i) {
        a = "0" + a;
    }
    for(int i = b.size(); i < t; ++i) {
        b = "0" + b;
    }
    for(int i = t - 1; i > 0; --i) {
        int m = a[i] - '0' + b[i] - '0';
        if(m >= 10) {
            a[i - 1] += m / 10;
            m %= 10;
            
        }  
        a[i] = m + '0'; 
    }
    if(a[0] == '0') {
        a = a.substr(1);
    } 
    return a;
}