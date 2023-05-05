#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

const int N = 1e7 + 10;
int n;

int primes[700000], cnt;
bool st[N];
int phi[N];
i64 pre[N];

inline void get(int n) {
	phi[1] = 1;
	for (int i = 2; i <= n; i ++) {
		if (!st[i]) { primes[cnt ++] = i; phi[i] = i - 1; }
		for (int j = 0; i <= n / primes[j]; j ++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) {
				phi[i * primes[j]] = phi[i] * primes[j];
				break;	
			}
			phi[i * primes[j]] = phi[i] * (primes[j] - 1);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;

	get(n);

	for (int i = 1; i <= n; i ++) {
		pre[i] = pre[i - 1] + phi[i]; 
	}

	i64 res = 0;	
	for (int i = 0; i < cnt; i ++) {
		res += 2 * pre[n / primes[i]] - 1;	
	}
	std::cout << res << "\n";	
	return 0;
}