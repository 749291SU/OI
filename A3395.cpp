#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

string s;
int cnt[2][3501];
vector<int> a[3501];

vector<int> add(vector<int> b, vector<int> c) {
	vector<int> res;
	int t = 0;
	for (int i = 0, j = 0; i < b.size() || j < c.size(); i ++, j ++) {
		int v1 = i < b.size() ? b[i] : 0;
		int v2 = j < c.size() ? c[j] : 0;
		t += v1 + v2;
		res.push_back(t % 10);
		t /= 10;
	}
	if (t) res.push_back(1);
	return res;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s;
	int maxa = 0;		
	a[0] = vector<int> (1, 1);
	for (int i = 0; i < s.size(); i ++) {
		int v = s[i] - '0';
		int ct = 0;
		memset(cnt[i % 2], 0, sizeof cnt[i % 2]);
		for (int j = 0; j <= 3500; j ++) {
			if (cnt[i % 2 ^ 1][j]) { cnt[i % 2][j + 1] += cnt[i % 2 ^ 1][j]; cnt[i % 2][j + 3] += cnt[i % 2 ^ 1][j]; }
		}
		while (v) {
			int t = v % 2;
			if (t) cnt[i % 2][ct] ++;
			v /= 2;
			ct ++;
		}

		for (int j = 0; j <= 3500; j ++) {
			if (cnt[i % 2][j] == 0) continue;
			int ct = 0;
			int t = cnt[i % 2][j]; cnt[i % 2][j] = 0;
			while (t) {
				int tt = t % 2;
				if (tt) cnt[i % 2][j + ct] ++;	
				t /= 2;
				ct ++;
			}		
			if (cnt[i % 2][j]) maxa = max(maxa, j);
		}
	}

	int pos = (s.size() - 1) % 2;

	vector<int> res;
	for (int i = 1; i <= maxa; i ++) { 
		a[i] = add(a[i - 1], a[i - 1]);
	}
	
	for (int i = 0; i <= 3500; i ++) {
		if (cnt[pos][i] == 1) {
			res = add(res, a[maxa - i]);
		} 		
	}

	for (int i = res.size() - 1; i >= 0; i --) cout << res[i];
	cout << "\n";
	return 0;
}