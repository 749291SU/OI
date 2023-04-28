#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void out(int n, int r) {
	if (n == 0) return ;
	int m = n % r;
	if (m < 0) { m -= r; n += r; }
	m = m >= 10 ? m - 10 + 'A' : m + '0';
	out(n / r, r);
	cout << (char) m;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, r; cin >> n >> r;
	cout << n << "=";
	out(n, r);
	cout << "(base" << r << ")\n";
	return 0;
}