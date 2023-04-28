#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, H = 5e4 + 10;
int n, h;
int d[H];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> h;
	int v, w;
	d[0] = 0;
	for (int i = 1; i <= h; i ++) d[i] = 0x3f3f3f3f;
	while (n --) {
		cin >> v >> w;
		for (int j = 0; j <= h; j ++) {
			d[j] = min(d[j], d[max(0, j - v)] + w);
		}
	}
	cout << d[h] << "\n";
	return 0;
}