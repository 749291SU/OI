#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m;

struct Node {
	int l, r, le;
	Node() { }
	bool operator < (const Node& ths) const {
		l < ths.l;
	}
} ints[N];


int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	int t, d, l;
	while (T --) {
		cin >> n;
		for (int i = 0; i < n; i ++) {
			cin >> t >> d >> l;
			ints[i].l = t; ints[i].r = t + d; ints[i].le = l;
		}

		sort(ints, ints + n);

		bool flag = true;
		int pre = 0;
		for (int i = 0; i < n; i ++) {
			if (pre > ints[i].r) { flag = false; break; }
			pre = max(ints[i].l, pre) + ints[i].le;
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}
	return 0;
}
