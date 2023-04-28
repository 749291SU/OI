#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e2 + 10;

typedef long long LL;
typedef pair<int, int> PII;

int n, w;
PII obs[N];

bool cmp(PII& p1, PII& p2) {
	return (double) p1.second / p1.first > (double) p2.second / p2.first;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> w;
	int v, p;
	int minv = 0x3f3f3f3f;
	for (int i = 0; i < n; i ++) {
		cin >> obs[i].first >> obs[i].second;
	}	

	sort(obs, obs + n, cmp);
	// for (int i = 0; i < n; i ++) cout << obs[i].first << " " << obs[i].second;
	// cout << "\n";
	LL ans = 0;	
	int prev = -1, prep = -1;
	for (int i = 0; i < n; i ++) {
		if (w < obs[i].first) continue;
		w -= obs[i].first;
		ans += obs[i].second;
	}
	cout << ans << "\n";

	return 0;
}