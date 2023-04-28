#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int pre = -1;
	int x;
	LL posi_cnt = 0, nega_cnt = 0;
	while (n --) {
		cin >> x;
		if (pre != -1) {
			if (x - pre > 0) posi_cnt += x - pre;
			else nega_cnt += pre - x;
		}
		pre = x;
	}
	cout << min(posi_cnt, nega_cnt) + abs(posi_cnt - nega_cnt) << "\n" << abs(posi_cnt + nega_cnt) + 1 << "\n";
	return 0;
}