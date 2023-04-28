#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;
int n;
int cnt[N * 100 + 10];
int d[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int ma = -0x3f3f3f3f;
	int x;
	for (int i = 0; i < n; i ++) {
		cin >> x; cnt[x] ++;
		ma = max(ma, x);
	}	

	for (int i = 1; i <= ma; i ++) {
		int tmp = 0;
		for (int j = i; j <= ma; j += i) {
			tmp += cnt[j];
		}
		d[tmp] = max(d[tmp], i);
	}	

	int mr = 0;
	for (int i = n; i > 0; i --) {
		mr = max(mr, d[i]);
		d[i] = mr;
	}
	for (int i = 1; i <= n; i ++) cout << d[i] << "\n";
	return 0;
}