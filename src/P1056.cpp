#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10;
int n, m, k, l, d;

PII cols[N], rows[N];

bool cmp(PII& p1, PII& p2) {
	return p1.first > p2.first;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k >> l >> d;	

	int x, y, p, q;
	for (int i = 1; i <= n; i ++) rows[i].second = i;
	for (int i = 1; i <= m; i ++) cols[i].second = i;
	while (d --) {
		cin >> x >> y >> p >> q;
		if (abs(x - p) == 1) rows[min(x, p)].first ++;
		else cols[min(y, q)].first ++;
	}

	sort(cols + 1, cols + m + 1, cmp);
	sort(rows + 1, rows + n + 1, cmp);

	vector<int> ans1, ans2;
	for (int i = 1; i <= n && k; i ++, k --) {
		ans1.push_back(rows[i].second);
	}	
	for (int i = 1; i <= m && l; i ++, l --) {
		ans2.push_back(cols[i].second);
	}
	sort(ans1.begin(), ans1.end());
	sort(ans2.begin(), ans2.end());

	bool first = true;
	for (auto t : ans1) {
		if (!first) cout << " ";
		cout << t;
		first = false;
	}
	cout << "\n";
	first = true;
	for (auto t : ans2) {
		if (!first) cout << " ";
		cout << t;
		first = false;
	}
	return 0;
}