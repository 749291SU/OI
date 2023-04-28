#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m1, m2;
int ans = 0x3f3f3f3f;

unordered_map<int, int> mm1;
void explode(int x, bool flag) {
	int t = mm1.size();
	int tmp = 1;
	for (int i = 2; i <= x / i; i ++) {
		if (x % i == 0) {
			int cnt = 0;
			while (x % i == 0) {
				if (!flag) mm1[i] += m2;
				x /= i; cnt ++;
			}	
			if (flag) {
				if (mm1.count(i)) {
					t --;
					if (mm1[i] > cnt) tmp = max(tmp, (mm1[i] - 1) / cnt + 1);
				}
			}
		}
	}	
	if (x > 1) {
		if (!flag) mm1[x] += m2;
		else {
			if (mm1.count(x)) {
				t --;
				if (mm1[x] > 1) tmp = max(tmp, mm1[x]);
			}
		}
	}
	if (!t && flag) ans = min(ans, tmp);
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m1 >> m2;
	explode(m1, false);	
	int s;
	while (n --) {
		cin >> s;
		explode(s, true);	
	}
	if (m1 == 1) ans = 0;
	cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
	return 0;
}