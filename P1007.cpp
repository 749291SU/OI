#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e3 + 10;
int n, l;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> l >> n;
	int x;
	int mi = 0;
	int mix = 0x3f3f3f3f, maxx = 0;
	for (int i = 0; i < n; i ++) {
		cin >> x;
		mi = max(mi, min(x, (l - x + 1)));
		mix = min(mix, x); maxx = max(maxx, x);
	}
	cout << mi << " " << max(mix, (l + 1 - maxx)) + maxx - mix << "\n";
	return 0;
}