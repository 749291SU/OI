#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 5e4 + 10;
int a[N];
unordered_map<int, int> mm;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	int n, x; 
	while (T --) {
		cin >> n;
		mm.clear();
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i ++) {
			cin >> x;
			for (int j = 2; j <= x / j; j ++) {
				if (x % j == 0) {
					int cnt = 0;
					while (x % j == 0) { cnt ++; x /= j; }
					if (i == 1) a[j] -= cnt;
					else a[j] += cnt;
				}
			}
			if (x > 1) {
				if (x >= N) {
					if (i == 1) mm[x] -= 1;
					else mm[x] += 1;
				}
				else {
					if (i == 1) a[x] -= 1;
					else a[x] += 1;
				}
			}
		}
		bool flag = true;
		for (int i = 2; i < N; i ++) {
			if (a[i] < 0) { flag = false; break; }
		}
		if (flag) {
			for (auto t : mm) {
				if (t.second < 0) { flag = false; break; }
			}
		}
		cout << (flag ? "Yes" : "No") << "\n";
	}
	return 0;
}