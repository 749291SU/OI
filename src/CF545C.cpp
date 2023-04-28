#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int x, h;
	int n; cin >> n;
	LL pre = -1, ppre = -1;
	LL preh, ppreh;
	LL prex = -1;

	int ans = n >= 2 ? 2 : 1;
	while (n --) {
		cin >> x >> h;
		if (ppre != -1) {
			if (pre - preh > prex) { ans ++; prex = pre; }		
			else if (pre + preh < x) { ans ++; prex = pre + preh; }
			else prex = pre;
		}
		if (pre == -1) prex = x;
		ppre = pre; pre = x;
		ppreh = preh; preh = h;
	}
	cout << ans << "\n";
	return 0;
}