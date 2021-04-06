#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main () {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

    int ans = 0;

    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        q.push(t);
    }

    while(q.size() >= 2) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        q.push(a + b);
        ans += a + b;
    }

    cout << ans << endl;


    return 0;
}