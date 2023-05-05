#include <iostream>
#include <cstring>
#include <algorithm>

using i64 = long long;

const int N = 1e7 + 10;
int n;

int primes[700000], cnt;
bool st[N];

inline void get(int n) {
	for (int i = 2; i <= n; i ++) {
		if (!st[i]) primes[cnt ++] = i;
		for (int j = 0; i <= n / primes[j]; j ++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) break;	
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n;

	get(n);

	i64 res = 0;	
	for (int i = 0; i < cnt; i ++) {
		int pri = primes[i];
		i64 t = n / pri;
		res += (t - t / pri) * (t + t / pri); 
	}	
	std::cout << res << "\n";
	return 0;
}