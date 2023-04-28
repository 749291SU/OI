#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int MOD = 9901;
int a, b;
unordered_map<int, int> mm;

void explode() {
	for (int i = 2; i <= a / i; i ++) {
		while (a % i == 0) {
			mm[i] ++;
			a /= i;
		}	
	}	
	if (a > 1) mm[a] ++;
}

int fast_pow(LL x, LL k) {
	int res = 1;
	while (k) {
		if (k & 1) res = res * x % MOD;
		x = x * x % MOD;
		k >>= 1;
	}	
	return res;
}

int poww(int x, LL k) {
	if (k == 0) return 1;
	if (k & 1) return (fast_pow(x, (k + 1) / 2) + 1) * poww(x, (k - 1) / 2) % MOD;	
	return (fast_pow(x, k) + poww(x, k - 1)) % MOD;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b;

	LL ans = !a ? 0 : 1;
	explode();
	for (auto t : mm) {
		ans = ans * poww(t.first, t.second * b) % MOD;
	}
	cout << ans << "\n";
	return 0;
}