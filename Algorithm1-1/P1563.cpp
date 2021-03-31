#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct person {
    int     dirct;
    string  ocup;

    person(int x, string s) : dirct(x), ocup(s) {}
};

int main () {
    int n, m;
    cin >> n >> m;
    vector<person> x;
    for(int i = 0; i < n; ++i) {
        int dirct;
        string ocup;
        cin >> dirct >> ocup;
        x.push_back(person(dirct, ocup));
    }
    int pos = 0;
    while(m--) {
        int i, j;
        cin >> i >> j;
        if(x[pos].dirct + i == 1) {
            pos += j;
            pos %= n;
        } else {
            pos = pos - j + n;
            pos %= n;
        }
    }

    cout << x[pos].ocup << endl;

    return 0;
}