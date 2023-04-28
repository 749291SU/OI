#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	priority_queue<int, vector<int>, greater<int>> q;
	int n; cin >> n;
	int x;
	while (n --) {
		cin >> x;
		q.push(x);
	}

	int ans = 0;
	while (q.size() > 1) {
		int u = q.top(); q.pop(); 
		int v = q.top(); q.pop();
		ans += v + u;
		q.push(u + v);
	}
	cout << ans << "\n";
	return 0;
}