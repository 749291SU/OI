#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;

const int N = 2e5 + 10;
int n;
LL m;
LL a[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	priority_queue<PII, vector<PII>, greater<PII>> q;
	cin >> n >> m;
	int b;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 0; i < n; i ++) { cin >> b; q.push({a[i], b}); }

	while (m) {
		PII t = q.top();
		if (t.second == 0) break;
		q.pop();
		t.first ++; t.second --; m --;		
		q.push(t);
	}		
	cout << q.top().first << "\n";	
	return 0;
}