#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 4e4 + 10;
int n;
int primes[210], cnt;
bool st[210];
int phi[N], s[N];

void get(int n) {
	for (int i = 2; i <= n; i ++) {
		if (!st[i]) primes[cnt ++] = i;
		for (int j = 0; i <= n / primes[j]; j ++) {
			st[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int ans = n > 1 ? 3 : 0;

	get(200);

	for (int i = 2; i < n; i ++) phi[i] = s[i] = i;
	
	for (int i = 0; i < cnt && primes[i] <= n / primes[i]; i ++) {
		int pri = primes[i];		
		for (int j = pri; j < n; j += pri) {
			if (s[j] % pri == 0) phi[j] = phi[j] / pri * (pri - 1);
			while (s[j] % pri == 0) s[j] /= pri;
		}
	}			

	for (int i = 2; i < n; i ++) { 
		if (s[i] != 1) phi[i] = phi[i] / s[i] * (s[i] - 1);
		ans += phi[i] * 2;
	}

	cout << ans << "\n";
	return 0;
}