#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 16;
int n, l, r, x;
int a[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i ++) cin >> a[i];

	int ans = 0;
	for (int i = 0; i < 1 << n; i ++) {
		int cnt = 0, sum = 0;
		int mi = 0x3f3f3f3f, ma = -0x3f3f3f3f;
		for (int j = 0; j < n; j ++) {
			if (i & (1 << j)) {
				cnt ++;
				mi = min(mi, a[j]); ma = max(ma, a[j]);	
				sum += a[j];
			}
		}
		if (cnt >= 2 && sum >= l && sum <= r && ma - mi >= x) ans ++;
	}	
	cout << ans << "\n";
	return 0;
}