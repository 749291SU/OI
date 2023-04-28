#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
int c[N * 10 + 10], w[N * 10 + 10];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int mi = 0x3f3f3f3f, ma = -0x3f3f3f3f;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		c[a[i]] ++;
		ma = max(ma, a[i]);
		mi = min(mi, a[i]);
	}

	for (int i = 0; i < n; i ++) {
		int t = a[i];
		if (c[a[i]]) {
			for (int j = t; j <= ma; j += t) {
				w[j] += c[a[i]];
				if (j == t) w[j] --;
			}
			c[a[i]] = 0;	
		}
	}	

	for (int i = 0; i < n; i ++) cout << w[a[i]] << "\n";

	return 0;
}