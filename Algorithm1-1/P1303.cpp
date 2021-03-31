#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 4005;

int main () {
    int result[MAX] = {0};
    string a, b;
    cin >> a >> b;

    int aLen = a.size(), bLen = b.size();
    
    for(int i = 0; i < bLen; ++i) {
        int n = b[bLen - 1 - i] - '0';
        for(int j = 0; j < aLen; ++j) {
            int m = a[aLen - 1 - j] - '0';
            
            result[MAX - 1 - j - i] += m * n;
            
            result[MAX - 2 - j - i] += result[MAX - 1 - j - i] / 10;
            result[MAX - 1 - j - i] %= 10;
        }
    }

    int i = 0;
    while(i < MAX && result[i] == 0) ++i;

    if(i == MAX) cout << "0";

    for(; i < MAX; ++i) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}