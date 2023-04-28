#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tt[2022];
vector<int> add(vector<int> a, vector<int> b) {
	vector<int> res;
	int t = 0;
	for (int i = 0, j = 0; i < a.size() || j < b.size(); i ++, j ++) {
		int v1 = i < a.size() ? a[i] : 0;
		int v2 = j < b.size() ? b[i] : 0;	
		t += v1 + v2;
		res.push_back(t % 10);
		t /= 10;
	}
	if (t) res.push_back(1);
	return res;
}

vector<int> multiply(vector<int> a, int b) {
	vector<int> res;
	int t = 0;
	for (int i = 0; i < a.size(); i ++) {
		int v = a[i];
		t += v * b;
		res.push_back(t % 10);
		t /= 10;
	}
	while (t) { res.push_back(t % 10); t /= 10; }
	return res;
}

inline bool le(vector<int> a, vector<int> b) {
	if (a.size() < b.size()) return true;
	if (a.size() > b.size()) return false;
	for (int i = a.size() - 1; i >= 0; i --) {
		if (a[i] < b[i]) return true;	
		if (a[i] > b[i]) return false;
	}		
	return false;
}
vector<int> d[2022];

vector<int> calc(int x) {
	vector<int>& dd = d[x];
	if (dd.size() > 0) return dd;
	if (x == 1) return dd = vector<int>(1, 1);
	if (x == 0) return dd = vector<int>(1, 0);
	
	dd = vector<int>(500, 9);
	for (int i = 0; i < x; i ++) {
		vector<int> t1 = multiply(calc(i), 2), t2 = multiply(calc(x - i - 1), 3), t3 = multiply(multiply(tt[i], i), (x - i - 1));
		vector<int> t = add(t1, add(t2, add(t3, tt[1])));	
		if (le(t, dd)) { ll = i; rr = x - i - 1; dd = t; }
	}	
	return dd;
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i <= 2021; i ++) {
		int j = i;
		while (j) {
			tt[i].push_back(j % 10);
			j /= 10;
		}	
	}


	vector<int> res = calc(2021);
	for (int i = res.size() - 1; i >= 0; i --) cout << res[i];
	cout << "\n";

	return 0;
}