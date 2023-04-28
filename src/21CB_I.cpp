#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n, m;
string s;
int diff[N];
int st[N];

int solve(int l) {
	int res = 0, t = 0, tt = -1;
	for (int i = 0; i < l; i ++) {
		if (diff[i]) t = !t;
	}
	for (int i = l; i < n; i ++) {
		if (diff[i]) t = !t;
		if (t == 1) {
			if (!(tt >= 0 && st[tt --] == 0)) return res;
			if (tt == -1) res = i + 1;
		}
		if (t == 0) st[++ tt] = t;	
	}	
	return res;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> s;

	diff[0] = s[0] == '(' ? 0 : 1;
	for (int i = 1; i < n; i ++) {
		if (s[i] == s[i - 1]) diff[i] = 0;
		else diff[i] = 1;
	}

	int ope, l, r;		
	while (m --) {
		cin >> ope >> l;
		l --;
		if (ope == 1) {
			cin >> r; r --;
			diff[l] = !diff[l];
			diff[r + 1] = !diff[r + 1];
		}
		else {
			cout << solve(l) << "\n";
		}
	}

	return 0;
}