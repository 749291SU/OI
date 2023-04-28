#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	int x, pre = 0;
	int ans = 1;

	for (int i = 0; i < n; i ++) {
		cin >> x;
		pre += x;
		if (pre > m) { pre = x; ans ++; }
	}
	cout << ans << "\n";
	return 0;
}