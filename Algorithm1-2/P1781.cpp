#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct PE {
    int num;
    string votes;
} ans[25];

bool cmp(PE a, PE b);

int main () {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        ans[i].num = i;
        cin >> ans[i].votes;
    }

    sort(ans + 1, ans + n + 1, cmp);

    cout << ans[1].num << endl << ans[1].votes << endl;

    return 0;
}

bool cmp(PE a, PE b) {
    if(a.votes.size() > b.votes.size()) {
        return true;
    } else if (a.votes.size() < b.votes.size()) {
        return false;
    } else {
        int t = a.votes.size();
        for(int i = 0; i < t; ++i) {
            if(a.votes[i] > b.votes[i]) {
                return true;
            } else if (a.votes[i] < b.votes[i]) {
                return false;
            }
        }
    }
}