#include <iostream>
#include <string>
using namespace std;

string ans[5005];
inline string Add(string, string);

int main () {
    ios::sync_with_stdio(0);

    freopen("ans.txt", "w", stdout);
    int n;
    cin >> n;

    ans[0] = "0";
    ans[1] = "1";
    ans[2] = "2";
    for(int i = 3; i <= n; ++i) {
        ans[i] = Add(ans[i - 1], ans[i - 2]);
        // cout << ans[i] << endl;
    }

    cout << ans[n] << endl;

    return 0;
}

inline string Add(string a, string b) {
    int maxSize = (a.size() > b.size() ? a.size() : b.size()) + 1;
    for(int i = a.size(); i < maxSize; ++i) {
        a = "0" + a;
    }
    for(int i = b.size(); i < maxSize; ++i) {
        b = "0" + b;
    }
    for(int i = maxSize - 1; i > 0; --i) {
        int t = a[i] - '0' + b[i] - '0';
        if(t >= 10) {
            b[i - 1] += t / 10;
            t %= 10;
        }
        b[i] = t + '0';
    }
    if(b[0] == '0') b = b.substr(1);
    return b;
}