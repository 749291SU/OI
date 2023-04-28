#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;
int n, m;
int d[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int p, t;
	while (m --) {
		cin >> p >> t;
		for (int j = 0; j <= n; j ++) {
			if (j >= t) d[j] = max(d[j], d[j - t] + p);
		}
	}
	cout << d[n] << "\n";
	return 0;
}