#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e4 + 10;
int l, r;
int primes[N], cnt;
bool st[N], st1[N * 100];
int ans;
void get(int n) {
	for (int i = 2; i <= n; i ++) {
		if (!st[i]) { 
			primes[cnt ++] = i;
			for (long long j = max((long long) 2 * i, (long long) ((l - 1) / i + 1) * i); j <= r; j += i) {
				st1[j - l] = true;
			}
		}
		for (int j = 0; i <= n / primes[j]; j ++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> l >> r;
	get(5e4);
	if (l == 1) st1[0] = true;
	for (int i = 0; i <= r - l; i ++) {
		if (!st1[i]) ans ++;
	}
	cout << ans << "\n";
	return 0;
}