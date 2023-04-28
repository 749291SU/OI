#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL l, r;

const int N = 1e6 + 10, MOD = 666623333;
int primes[N], cnt;
bool st[N];
LL phi[N];
LL a[N];

void get() {
	for (int i = 2; i <= N; i ++) {
		if (!st[i]) primes[cnt ++] = i;
		for (int j = 0; i <= N / primes[j]; j ++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}	
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> l >> r;
	for (LL i = l; i <= r; i ++) {
		phi[i - l] = i;
		a[i - l] = i;
	}

	get();

	LL ans = 0;
	for (int i = 0; i < cnt && primes[i] <= r / primes[i]; i ++) {
		LL pr = primes[i];
		for (LL j = ((l - 1) / pr + 1) * pr; j <= r; j += pr) {
			phi[j - l] = phi[j - l] / pr * (pr - 1);
			while (a[j - l] % pr == 0) a[j - l] /= pr;
		}
	}

	for (int i = 0; i <= r - l; i ++) {
		if (a[i] > 1) {
			phi[i] = phi[i] / a[i] * (a[i] - 1);
		}
		ans = (ans + (i + l - phi[i]) % MOD) % MOD;
	}

	cout << ans << "\n";
	return 0;
}