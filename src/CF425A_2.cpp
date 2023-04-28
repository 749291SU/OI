#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define out_ins(i) out.insert(lower_bound(out.begin(), out.end(), i, greater<int>()), i);

const int N = 210;
int n, k;
int b[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	b[0] = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> b[i];
		b[i] += b[i - 1];
	}

	int ans = -0x3f3f3f3f;
	for (int i = 1; i <= n; i ++) {
		vector<int> out;
		multiset<int> m;
		for (int p = 1; p < i; p ++) out_ins(b[p] - b[p - 1]);
		for (int p = i; p <= n; p ++) m.insert(b[p] - b[p - 1]);
		for (int j = n; j >= i; j --) {
			int tmp	= b[j] - b[i - 1], tt = k;
			int p = 0;
			for (auto t : m) {
				if (tt -- <= 0) break;	
				if (p == out.size()) break;
				if (t >= out[p]) break;	
				tmp += out[p ++] - t;
			}
			ans = max(ans, tmp);
			out_ins(b[j] - b[j - 1]);
			m.erase(m.lower_bound(b[j] - b[j - 1]));
		}	
	}
	cout << ans << "\n";
	return 0;
}