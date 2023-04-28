#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 351, M = 130;
int n, m;
int a[N], b[5];
int d[N][41][41][41];

int dp(int i, int e, int f, int g) {
	int& dd = d[i][e][f][g];
	if (dd > 0) return dd;
	if (i >= n) return dd = 0;

	if (e > 0) dd = max(dd, a[i] + dp(i + 1, e - 1, f, g));
	if (f > 0) dd = max(dd, a[i] + dp(i + 2, e, f - 1, g));
	if (g > 0) dd = max(dd, a[i] + dp(i + 3, e, f, g - 1));
	if (n - i - 1 - e - 2 * f - 3 * g > 0) {
		// cout << "hh" << "\n";
		dd = max(dd, a[i] + dp(i + 4, e, f, g));
	}
	if (i == n - 1) dd = a[n - 1];
	return dd;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int x;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < m; i ++) {
		cin >> x;
		b[x] ++;
	}
	cout << dp(0, b[1], b[2], b[3]) << "\n";
	return 0;
}