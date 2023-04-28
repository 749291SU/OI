#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int n;
LL m;
PII a[N];
int b[N];
LL pre[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i ++) { cin >> a[i].first; a[i].second = i; }
	for (int i = 0; i < n; i ++) cin >> b[i];

	sort(a, a + n);	

	int l = 0, r = 0;
	pre[0] = 0;
	for (int i = 1; i < n; i ++) {
		pre[i] = pre[i - 1] + (a[i].first - a[i - 1].first) * i;	
		if (pre[i] > m) break;
		r = i;
	}	

	auto check = [] (int x) -> bool {
		for (int i = 0; i < x; i ++) {
			if (b[a[i].second] < a[x].first - a[i].first) return false;
		}
		return true;
	};

	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}

	LL ans = a[l].first;
	if (r == n - 1 && l == n - 1) {
		int mi = (m - pre[n - 1]) / n;
		for (int i = 0; i < n; i ++) {
			mi = min(mi, b[a[i].second] - a[n - 1].first + a[i].first);
		}	
		ans += mi;			
	}
	cout << ans << "\n";	
	return 0;
}