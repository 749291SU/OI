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
	}		
	return 0;
}