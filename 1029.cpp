#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int x, y;

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int ans = 0;
	cin >> x >> y;
	int t = x * y;	

	for (int i = x; i <= y; i += x) {
		if (t % i == 0) {
			if (gcd(i, t / i) == x) ans ++;
		}
	}
	cout << ans << "\n";
	return 0;
}