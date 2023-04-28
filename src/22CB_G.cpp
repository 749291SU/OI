#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

typedef pair<double, int> PII;

const int N = 41, M = 21;
const double eps = 1e-8;

int n, m, k;

int a[N];
int b[N][M];
int c[M];
PII res[N];
bool vis[M];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;	
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) cin >> b[i][j];
	}
	cin >> k;
	int x;
	for (int i = 0; i < k; i ++) {
		cin >> x;
		vis[x] = true;
	}

	double pb = 0;
	for (int i = 1; i <= n; i ++) {
		double tmp = (double) a[i] / 100;
		for (int j = 1; j <= m; j ++) {
			if (vis[j]) tmp *= (double) b[i][j] / 100;
			else tmp *= 1 - (double) b[i][j] / 100;
		}
		res[i] = {tmp, i};
		pb += tmp;
	}	

	for (int i = 1; i <= n; i ++) res[i].first /= pb;
		
	auto cmp = [] (PII& p1, PII& p2) -> bool {
		return p1.first - p2.first > eps || (fabs(p1.first - p2.first) <= eps && p1.second < p2.second);	
	};

	sort(res + 1, res + n + 1, cmp);

	for (int i = 1; i <= n; i ++) { 
		cout << res[i].second << " ";
		cout << fixed << setprecision(2) << res[i].first * 100 << "\n";
	}		
	return 0;
}