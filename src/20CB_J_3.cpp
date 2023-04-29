#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#pragma GCC optimize(2)	

typedef long long LL;

const int N = 1e3 + 10, MOD = 1e9 + 7;

int n, m, w;
int r1, c1, h1, r2, c2, h2;

int primes[1000], cnt;
bool st[1000];
inline void get(int n) {
	for (int i = 2; i <= n; i ++) {
		if (!st[i]) primes[cnt ++] = i;
		for (int j = 0; i <= n / primes[j]; j ++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) break;	
		}
	}
}

LL fac[3 * N], inv[2 * N];
LL fast_pow(LL x, int k) {
	LL res = 1;
	while (k) {
		if (k & 1) res = res * x % MOD;
		x = x * x % MOD;
		k >>= 1;
	}			
	return res;
}

LL f[N][N], tmp[2 * N];
LL calc(int x, int y, int z) {
	LL res = 0;
	memset(tmp, 0, sizeof tmp);
	for (int i = 0; i <= x; i ++) {
		for (int j = 0; j <= y; j ++) {
			tmp[i + j] = (tmp[i + j] + f[x][i] * f[y][j] % MOD * fac[i + j] % MOD * inv[i] % MOD * inv[j] % MOD) % MOD;
		}
	}

	for (int i = 0; i <= x + y; i ++) {
		for (int j = 0; j <= z; j ++) {
			res = (res + tmp[i] * f[z][j] % MOD * fac[i + j] % MOD * inv[i] % MOD * inv[j] % MOD) % MOD;			
		}
	}
	return res;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int ma;
	cin >> n >> m >> w; ma = max(n, max(m, w));
	cin >> r1 >> c1 >> h1 >> r2 >> c2 >> h2;		

	get(1000);	

	fac[0] = inv[0] = 1;
	for (int i = 1; i <= 3 * ma; i ++) fac[i] = fac[i - 1] * i % MOD;
	for (int i = 1; i <= 2 * ma; i ++) inv[i] = fast_pow(fac[i], MOD - 2);

	f[1][0] = 1;	
	for (int i = 2; i <= ma; i ++) {
		for (int j = 1; j <= min(i, ma); j ++) {
			for (int k = 0; k < cnt && primes[k] < i; k ++) {
				f[i][j] = (f[i][j] + f[i - primes[k]][j - 1]) % MOD;	
			}		
		}		
	}		

	LL ans = calc(n, m, w);	

	LL t1 = calc(r1, c1, h1), t2 = calc(r2, c2, h2);
	LL t3 = calc(n - r1 + 1, m - c1 + 1, w - h1 + 1), t4 = calc(n - r2 + 1, m - c2 + 1, w - h2 + 1);
	ans = ((ans - t1 * t3) % MOD + MOD) % MOD;
	ans = ((ans - t2 * t4) % MOD + MOD) % MOD;

	if (r1 <= r2 && c1 <= c2 && h1 <= h2) {
		ans = ((ans + t1 * calc(r2 - r1 + 1, c2 - c1 + 1, h2 - h1 + 1) % MOD * t4) % MOD + MOD) % MOD;	
	}
	if (r1 >= r2 && c1 >= c2 && h1 >= h2) {
		ans = ((ans + t2 * calc(r1 - r2 + 1, c1 - c2 + 1, h1 - h2 + 1) % MOD * t3) % MOD + MOD) % MOD;	
	}
	cout << ans << "\n";
	return 0;
}