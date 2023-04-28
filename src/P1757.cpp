#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 1e3 + 10, M = 1e3 + 10;
const int K = 110;
int n, m;

int d[M];
vector<int> a[K];
int v[N], w[N];
unordered_map<int, int> mm;
int cnt;

inline int get_sign(int x) {
	return mm.count(x) ? mm[x] : mm[x] = cnt ++;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	int x, y, z;
	for (int i = 0; i < n; i ++) {
		cin >> x >> y >> z;
		a[get_sign(z)].push_back(i);
		v[i] = x; w[i] = y;
	}	

	for (int i = 0; i < cnt; i ++) {
		for (int j = m; j >= 0; j --) {
			for (int k = 0; k < a[i].size(); k ++) {
				int t = a[i][k];
				if (j >= v[t]) d[j] = max(d[j], d[j - v[t]] + w[t]);
			}
		}
	}
	cout << d[m] << "\n";
	return 0;
}