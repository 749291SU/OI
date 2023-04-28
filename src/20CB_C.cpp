#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cnt[101];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 100; i ++) {
		int x = i;
		for (int j = 2; j <= x / j; j ++) {
			while (x % j == 0) { cnt[j] ++;	x /= j; }
		}	
		if (x > 1) cnt[x] ++;
	}

	long long ans = 1;
	for (int i = 1; i <= 100; i ++) {
		ans *= cnt[i] + 1;
	}
	cout << ans << "\n";
	return 0;
}