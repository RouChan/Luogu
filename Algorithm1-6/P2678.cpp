#include <iostream>
using namespace std;

int l, n, m;
int x[50005];

inline bool IsLegal(int s);

int main () {
	ios::sync_with_stdio(0);
	cin >> l >> n >> m;
	for(register int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	x[n + 1] = l;

	int i = 1, j = l, ans;
	while(i <= j) {
		int mid = (i + j) / 2;
		if(IsLegal(mid)) {
			ans = mid;
			i = mid + 1;
		}
		else 	j = mid - 1;
	}

	cout << ans << endl;

	return 0;
}

inline bool IsLegal(int s) {
	int count = 0, now = 0;
	for(int i = 1; i <= n + 1; ++i) {
		if(x[i] - x[now] < s) 	count++;
		else					now = i;
	}
	if(count > m) 	return false;
	else			return true;	
}