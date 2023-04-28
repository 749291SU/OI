#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100;
int n;
int c[N];
bool a[N * 10 + 1];
int b[N][N * 10 + 1];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T --) {
		cin >> n;
		memset(a, false, sizeof a);
		memset(b, 0, sizeof b);
		int x, k = 1;
		int minx = 0x3f3f3f3f, maxx = -0x3f3f3f3f;
		for (int i = 0; i < n; i ++) {
			cin >> c[i];
			a[c[i]] = true;
			minx = min(minx, c[i]);
			maxx = max(maxx, c[i]);
		}
		for (int i = 0; i < n; i ++) {
			cin >> x;
			k = max(k, x);
			b[x][c[i]] ++;
		}

		for (int i = 1; i <= k; i ++) {
			cout << i << "={";
			bool first = true;
			for (int j = minx; j <= maxx; j ++) {
				if (!a[j]) continue;
				if (!first) cout << ",";	
				cout << j << "=" << b[i][j];
				first = false;
			}		
			cout << "}\n";
		}
	}

	return 0;
}