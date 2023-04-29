#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

int k;
LL x1, y1, x2, y2;

LL jie[39];
LL a[39];
int fx[9] = {0, 1, 0, 0, 1, 0, 0, 1, 0};
int fy[9] = {0, 0, 0, 1, 1, 1, 0, 0, 0};

inline PII getPos(LL x, LL y, int k) {
	int _x = x / jie[k - 1], _y = y / jie[k - 1];	
	return {_x, _y};
}

inline LL getCnt(LL x, LL y, int k) {
	PII t = getPos(x, y, k);
	return t.first & 1 ? t.first * 3 + 2 - t.second : t.first * 3 + t.second;
}

LL calc(LL x1, LL y1, LL x2, LL y2, int k) {
	LL t = jie[k - 1];
	LL p1 = getCnt(x1, y1, k), p2 = getCnt(x2, y2, k);
	if (p1 > p2) { swap(x1, x2); swap(y1, y2); swap(p1, p2); }
	
	if (k == 1) return p2 - p1;

	x1 %= t, y1 %= t;	
	x2 %= t, y2 %= t;

	if (fx[p1]) x1 = t - 1 - x1;	
	if (fx[p2]) x2 = t - 1 - x2;
	if (fy[p1]) y1 = t - 1 - y1;
	if (fy[p2]) y2 = t - 1 - y2;

	LL res = p2 - p1;
	if (p2 - p1 > 1) {
		a[k - 1] = a[k - 1] > 0 ? a[k - 1] : calc(0, 0, t - 1, t - 1, k - 1);
		res += (p2 - p1 - 1) * a[k - 1];
	}
	if (p2 - p1 > 0) res += calc(x1, y1, t - 1, t - 1, k - 1) + calc(0, 0, x2, y2, k - 1);				
	else res += calc(x1, y1, x2, y2, k - 1);
	return res;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> k >> x1 >> y1 >> x2 >> y2;
	k = min(k, 38);
	jie[0] = 1;

	for (int i = 1; i <= 37; i ++) jie[i] = jie[i - 1] * 3;
		
	cout << calc(x1, y1, x2, y2, k) << "\n";	
	return 0;
}