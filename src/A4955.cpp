#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 510, M = 1e3 + 10;
int n, m;
int v[N], si[N], d[M], idx;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	LL sum = 0;
	cin >> n >> m;
	memset(d, -1, sizeof d);
	memset(si, -1, sizeof si);
	int x;
	for (int i = 1; i <= n; i ++) cin >> v[i];
	for (int i = 0; i < m; i ++) {
		cin >> x;
		for (int j = si[x] + 1; j < idx; j ++) {
			if (d[j] < 0) continue;
			sum += v[d[j]];
		}
		d[si[x]] = -1; d[idx ++] = x;
		si[x] = idx - 1;
	}

	cout << sum << "\n";
	return 0;
}