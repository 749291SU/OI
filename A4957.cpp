#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 11;
int n;
struct Int {
	int l, r, le;
	bool operator < (const Int& ths) const {
		return l < ths.l;
	}
} ints[N];

bool used[N];
bool dfs(int h, int last) {
	if (h == n) return true;

	for (int i = 0; i < n; i ++) {
		if (used[i] || last > ints[i].r) continue;
		used[i] = true;
		if (dfs(h + 1, max(last, ints[i].l) + ints[i].le)) return true;
		used[i] = false;
	}
	return false;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	int t, d, l;
	while (T --) {
		cin >> n;
		memset(used, false, sizeof used);
		for (int i = 0; i < n; i ++) {
			cin >> t >> d >> l;
			ints[i].l = t; ints[i].r = t + d; ints[i].le = l;
		}	
		cout << (dfs(0, 0) ? "YES" : "NO") << "\n";
	}		
	return 0;
}