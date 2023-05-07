#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

const int N = 1e6 + 10;
int n, m, nn;
int a[N], b[N], cnt[N];
int ans[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> m;
	int x;
	for (int i = 0; i < n; i ++) {
		std::cin >> x;
		a[i] = x;
		if (x <= m) {
			cnt[x] ++;
			b[nn ++] = x;
		}
	}

	std::sort(b, b + nn); nn = std::unique(b, b + nn) - b;
	for (int i = 0; i < nn; i ++) {
		for (int j = b[i]; j <= m; j += b[i]) {
			ans[j] += cnt[b[i]];	
		}
	}
	int l = 1, k = 0;
	for (int i = 0; i <= m; i ++) {
		if (ans[i] > k) {
			l = i;
			k = ans[i];	
		}	
	}		
	std::cout << l << " " << k << "\n";
	for (int i = 0; i < n; i ++) {
		if (l % a[i] == 0) std::cout << i + 1 << " ";	
	}	
	std::cout << "\n";
	return 0;
}