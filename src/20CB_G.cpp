#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<string, int> PII;

const int N = 1e6 + 10;

string s;
PII c[N];
int cnt = -1;
int b[N];
int st[N], po[N];

inline int bi_si(int x, int tt) {
	int l = 0, r = tt;
	while (l < r) {
		int mid = l + r >> 1;
		if (b[st[mid]] > b[x]) l = mid + 1;
		else r = mid;
	}
	return l;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] < 'a') { cnt ++; c[cnt].second = cnt; }
		c[cnt].first.push_back(s[i]);
	}

	sort(c, c + cnt + 1);

	for (int i = 0, j = -1; i <= cnt; i ++) {
		if (i == 0 || c[i].first > c[i - 1].first) {
			j ++;
		}
		b[c[i].second] = j;
	}

	for (int i = 0; i <= cnt; i ++) cout << b[i] << " ";
	cout << "\n";	

	int tt = 0;
	for (int i = cnt; i >= 0; i --) {
		int pos;
		if (tt == 0 || b[i] < b[st[tt - 1]]) { pos = tt; st[tt ++] = i; }
		else {
			pos = bi_si(i, tt);
			st[pos] = i;
		}
		po[i] = pos > 0 ? po[st[pos - 1]] + 1 : 1;	
	}	

	int i = 0;
	int pre = -1;
	while (tt > 0) {
		int mi_i = -1;
		for (int j = pre + 1; j <= cnt; j ++) {
			if (po[c[j].second] == tt && (pre == -1 || (b[c[j].second] > b[c[pre].second] && c[j].second > c[pre].second))) {
				mi_i = j;
				break;
			}
		}		
		cout << c[mi_i].first;
		pre = mi_i;
		tt --;
	}
	cout << "\n";
	return 0;
}