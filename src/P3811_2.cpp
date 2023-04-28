#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 3e6 + 10;
int n, p;
int inv[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> p;
	inv[1] = 1;
	cout << 1 << "\n";
	for (LL i = 2; i <= n; i ++) {
		inv[i] = (p - p / i) * inv[p % i] % p;
		cout << inv[i] << "\n";
	}
	return 0;
}