#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 13;
int d[N], f[N];

int cal(int n) {
	int& ff = f[n];
	if (ff > 0) return ff;
	if (n == 1) return ff = 1;

	ff = 0x3f3f3f3f;
	for (int i = 1; i < n; i ++) {
		ff = min(ff, 2 * cal(i) + d[n - i]);
	}	
	return ff;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 12; i ++) d[i] = 2 * d[i - 1] + 1;
	for (int i = 1; i <= 12; i ++) cout << cal(i) << "\n";
	return 0;
}