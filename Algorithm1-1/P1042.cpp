#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

struct comp{
    int scoreA;
    int scoreB;
    comp(int x, int y) : scoreA(x), scoreB(y) {}
};

bool IsEnd(int A, int B, int type);

int main () {
    vector<comp> r11, r21;            
    int A11, A21, B11, B21;
    A11 = A21 = B11 = B21 = 0;
    char c;
    while((c = cin.peek()) != 'E') {
        cin.get();
        if(c == 'W') {
            A11++;
            A21++;
        } else if(c == 'L') {
            B11++;
            B21++;
        } else {
            continue;
        }

        if(IsEnd(A11, B11, 11)) {
            r11.push_back(comp(A11, B11));
            A11 = B11 = 0;
        }
        if(IsEnd(A21, B21, 21)) {
            r21.push_back(comp(A21, B21));
            A21 = B21 = 0;
        }
    }
    // if(A11 == 0 && B11 == 0) {
    //     r11.push_back(comp(0, 0));
    //     r21.push_back(comp(0, 0));
    // }
    if(A11 != 0 || B11 != 0) {
        r11.push_back(comp(A11, B11));
    } else {
        r11.push_back(comp(0, 0));
    }
    if(A21 != 0 || B21 != 0) {
        r21.push_back(comp(A21, B21));
    } else {
        r21.push_back(comp(0, 0));
    }

    int c11 = r11.size(), c21 = r21.size();
    for(int i = 0; i < c11; ++i) {
        cout << r11[i].scoreA << ":" << r11[i].scoreB << endl;
    }

    cout << endl;

    for(int i = 0; i < c21; ++i) {
        cout << r21[i].scoreA << ":" << r21[i].scoreB << endl;
    }

    return 0;
}

inline bool IsEnd(int A, int B, int type) {
    if(A < B) {
        int t = A;
        A = B;
        B = t;
    }
    if(A >= type && A - B > 1) {
        return true;
    } else {
        return false;
    }
}