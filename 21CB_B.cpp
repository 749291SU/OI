#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int primes[2887230], cnt;
bool st[20210606];

void get(int n) {
	for (int i = 2; i <= n; i ++) {
		if (!st[i]) primes[cnt ++] = i;
		for (int j = 0; primes[j] <= n / i; j ++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}


int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	get(20210605);

	int ans = 0;
	for (int i = 0; i < cnt; i ++) {
		int pri = primes[i];
		bool flag = true;
		while (pri) {
			int t = pri % 10;
			if (t != 2 && t != 3 && t != 5 && t != 7) { flag = false; break; }
			pri /= 10;
		}	
		if (flag) ans ++;
	}
	cout << ans << "\n";
	return 0;
}