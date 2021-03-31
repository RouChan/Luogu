#include <iostream>
#include <algorithm>
using namespace std;

int x[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main () {
    ios::sync_with_stdio(false);

    int a, b, c, count = 0;
    cin >> a >> b >> c;

    do{
        int p = 100 * x[1] + 10 * x[2] + x[3];
        int q = 100 * x[4] + 10 * x[5] + x[6];
        int r = 100 * x[7] + 10 * x[8] + x[9];

        if(p * b * c == q * a * c && p * b * c == r * a * b) {
            cout << p << " " << q << " " << r << endl;
            count++;
        }
    } while(next_permutation(x + 1, x + 10));

    if(count == 0) {
        cout << "No!!!" << endl;
    }

    return 0;
}