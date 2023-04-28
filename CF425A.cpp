#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 210;
int n, k;
int a[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i ++) cin >> a[i];

	int ans = -0x3f3f3f3f;
	for (int i = 0; i < n; i ++) {
		for (int j = i; j < n; j ++) {
			int tmp = 0, tt = k;
			priority_queue<int, vector<int>, greater<int>> q;
			priority_queue<int, vector<int>> q1;
			for (int p = i; p <= j; p ++) { q.push(a[p]); tmp += a[p]; }
			for (int p = 0; p < i; p ++) q1.push(a[p]);
			for (int p = j + 1; p < n; p ++) q1.push(a[p]);
			while (tt -- && q1.size() && q.size() && q1.top() > q.top()) {
				tmp -= q.top(); q.pop();	
				tmp += q1.top(); q1.pop();
			}
			ans = max(ans, tmp);
		}
	}
	cout << ans << "\n";
	return 0;
}