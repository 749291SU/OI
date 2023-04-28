#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e7 + 10;
int n, q;
int primes[N], cnt;
bool st[N * 10];

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

	cin >> n >> q;
	get(n);
	while (q --) {
		int k; cin >> k;
		cout << primes[k - 1] << "\n";
	}

	return 0;
}