#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

typedef long long LL;

int n, r, rr;
int a[11] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
int b[11];
vector<int> c;

char get_c(int v) {
	if (v >= 0 && v <= 9) return v + '0';
	return v - 10 + 'A';
}

void out(int val) {
	int t = val % rr;
	if (val / rr) { val /= rr; out(val); }	
	cout << get_c(t);
}

bool dfs(int x, int tmp) {
	if (x == c.size()) {
		int tmp1 = tmp - n, tmp2 = tmp1;
		int cnt = 0;
		if (tmp1 < 0) return false;
		while (tmp1)	{
			if (!(cnt & 1) && tmp1 % rr) return false;
			tmp1 /= rr; cnt ++;
		}
		out(tmp + tmp2);
		return true;
	}		

	for (int i = 1; i < rr; i ++) {
		if (dfs(x + 1, tmp + i * b[c[x]])) return true;	
	}
	return false;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> r;
	rr = abs(r);
	cout << n << "=";

	int ct = 0;
	int tou = abs(n);					
		while (tou) {
		ct ++;
		tou /= rr;
	}
	ct = ct / 2 + 2;

	for (int i = 0; i < ct; i ++) b[i] = pow(rr, a[i]);

	for (int i = 0; i < 1 << ct; i ++) {
		c.clear();
		for (int j = 0; j < ct; j ++) {
			if (i & (1 << j)) c.push_back(j);
		}	
		if (dfs(0, 0)) break;	
	}	
	cout << "(base" << r << ")\n";
	return 0;
}