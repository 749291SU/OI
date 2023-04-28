#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10, INF = 2e9 + 10;
int n;

LL xx[N], ll[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> xx[i] >> ll[i];
	}
	xx[n] = INF;

	int ans = 1;
	LL pre = xx[0];
	for (int i = 1; i < n; i ++) {
		if (xx[i] - ll[i] > pre) { ans ++; pre = xx[i]; }
		else if (xx[i] + ll[i] < xx[i + 1]) { ans ++; pre = xx[i] + ll[i]; }
		else pre = xx[i];
	}
	cout << ans << "\n";	
	return 0;
}