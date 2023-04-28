#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int K = 1e6 + 10;
const int N = 1e6 + 10, MOD = 1e6 + 3;

int e[N][2], ne[N][2], h[N][2], idx[2];
int cnt[2];

bool fi(int x, int f) {
	int ha = x % MOD;	
	int t = h[ha][f];
	while (t != -1 && e[t][f] != x) t = ne[t][f];	
	if (t == -1) { e[idx[f]][f] = x; ne[idx[f]][f] = h[ha][f]; h[ha][f] = idx[f] ++; cnt[f] ++; return false; }
	return true;
}

LL n, k;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	memset(h, -1, sizeof h);
	int r, c;
	LL ans = 0;
	while (k --) {
		cin >> r >> c;
		bool f1 = fi(r, 0), f2 = fi(c, 1);
		if (f1 && f2) continue;
		else if (f1) ans += n - cnt[0];
		else if (f2) ans += n - cnt[1];
		else ans += 2 * n - 1 - cnt[0] - cnt[1] + 2;
	}
	cout << ans << "\n";
	return 0;
}