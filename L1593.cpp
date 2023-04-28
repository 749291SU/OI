#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD = 9901;

typedef long long LL;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);	
}

int fast_pow(LL x, int k) {
	int res = 1;
	while (k) {
		if (k & 1) res = res * x % MOD;
		x = x * x % MOD;
		k >>= 1;
	}
	return res;
}

int sum(LL x, int k) {
	if (k == 0) return 1;
	if (k & 1) return (fast_pow(x, (k + 1) / 2) + 1) * sum(x, (k - 1) / 2) % MOD;
	return (fast_pow(x, k) + sum(x, k - 1)) % MOD;
}


int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b; cin >> a >> b;
	int ans = 1;
	for (int i = 2; i <= a / i; i ++) {
		if (a % i == 0) {
			int cnt = 0;
			while (a % i == 0) { cnt ++; a /= i; }
			if (gcd(i - 1, 9901) == 1) {
				ans = ans * ((fast_pow(i, cnt * b + 1) - 1) * fast_pow(i - 1, 9899) % MOD) % MOD;
			}
			else ans = ans * sum(i, cnt * b) % MOD;
		}
	}
	if (a > 1) ans = ans * sum(a, b) % MOD;
	if (!a) ans = 0;
	cout << ans << "\n";	
	return 0;
}