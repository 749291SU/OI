#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	LL ans = 0;
	for (int i = 1; i <= n; i ++) {
		int x = i;
		LL tmp = 1;
		for (int j = 2; j <= x / j; j ++) {
			int cnt = 0;
			if (x % j == 0) {
				while (x % j == 0) { x /= j; cnt ++; }
				tmp = tmp * (cnt + 1);
			}
		}
		if (x > 1) tmp = tmp * 2;
		ans += tmp;
	}	
	cout << ans << "\n";	
	return 0;
}