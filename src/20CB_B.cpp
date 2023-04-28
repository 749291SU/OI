#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

bool g[6061][6061];

int idx[4] = {-1, 0, 0, 1};
int idy[4] = {0, -1, 1, 0};

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	g[2020][2020] = g[4040][2031] = g[2031][2034] = g[4020][4020] = true;	

	vector<PII> q;
	q.push_back({2020, 2020}); q.push_back({4040, 2031}); 
	q.push_back({2031, 2034}); q.push_back({4020, 4020});

	long long ans = 4;
	int t = 2020;
	while (t --) {
		vector<PII> b;	
		for (int i = 0; i < q.size(); i ++) {
			int x = q[i].first, y = q[i].second;
			for (int j = 0; j < 4; j ++) {
				int _x = x + idx[j], _y = y + idy[j];	
				if (!g[_x][_y]) {
					ans ++;
					g[_x][_y] = true;
					b.push_back({_x, _y});
				}	
			}
		}
		q = b;
	}
	cout << ans << "\n";	
	return 0;
}