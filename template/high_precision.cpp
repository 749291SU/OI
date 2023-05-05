#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

inline std::vector<int> operator + (std::vector<int> a, std::vector<int>& b) {
	int t = 0;
	for (int i = 0, j = 0; i < a.size() || j < b.size(); i ++, j ++) {
		int v1 = i < a.size() ? a[i] : 0;
		int v2 = j < b.size() ? b[j] : 0;
		t += v1 + v2;
		a[i] = t % 10;
		t /= 10;		
	}	
	if (t) a.push_back(1);
	while (a.size() > 1 && a.back() == 0) a.pop_back();
	return a;
}

inline std::vector<int> operator - (std::vector<int> a, std::vector<int>& b) {
	for (int i = 0; i < b.size(); i ++) {
		if ((a[i] -= b[i]) < 0) a[i] += 10, -- a[i + 1]; 
	}
	while (a.size() > 1 && !a.back()) a.pop_back();
	return a;
}

inline std::vector<int> operator * (std::vector<int> a, int b) {
	int t = 0;
	for (int i = 0; i < a.size(); i ++) {
		t += b * a[i];
		a[i] = t % 10;
		t /= 10;
	}		
	while (t) { a.push_back(t % 10); t /= 10; }
	while (a.size() > 1 && !a.back()) a.pop_back();
	return a;
}

inline std::vector<int> operator * (std::vector<int>& a, std::vector<int>& b) {
	std::vector<int> res;
	for (int i = 0; i < b.size(); i ++) {
		std::vector<int> tmp;	
		int x = b[i];
		int t = 0;
		for (int j = 0; j < a.size(); j ++) {
			t += a[j] * x;
			tmp.push_back(t % 10);
			t /= 10;
		}
		while (t) { tmp.push_back(t % 10); t /= 10; }

		int offset = i;
		for (int p = 0, q = -offset; p < res.size() || q < tmp.size(); p ++, q ++) {
			int v1 = p < res.size() ? res[p] : 0;
			int v2 = q >= 0 ? tmp[q] : 0;
			t += v1 + v2;
			if (p >= res.size()) res.push_back(t % 10);
			else res[p] = t % 10;
			t /= 10;
		}
		if (t) res.push_back(1);
	}
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}

inline std::vector<int> operator / (std::vector<int> a, int b) {
	int t = 0;
	for (int i = a.size() - 1; i >= 0; i --) {
		a[i] += t * 10;
		t = a[i] % b;
		a[i] /= b;
	}
	while (a.size() > 1 && a.back() == 0) a.pop_back();
	return a;
}

inline std::vector<int> divide(std::vector<int>& a, std::vector<int>& b) {
	std::vector<int> res, tmp, tmp1;
	for (int i = a.size() - 1; i >= 0; i --) {
		std::reverse(tmp.begin(), tmp.end());
		tmp.push_back(a[i]); std:reverse(tmp.begin(), tmp.end());
		int j = 9; tmp1 = b * j;
		while (j > 0 && tmp1 >= tmp) {
			j --;
			tmp1 = b * j;
		}
		res.push_back(j);
		tmp = tmp - tmp1;	
	}		
	std::reverse(res.begin(), res.end());
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;	
}

inline bool operator > (std::vector<int>& a, std::vector<int>& b) {
	if (a.size() > b.size()) return true;
	if (a.size() < b.size()) return false;
	for (int i = a.size() - 1; i >= 0; i --) {
		if (a[i] > b[i]) return true;
		if (a[i] < b[i]) return false;	
	}	
	return false;
}

inline bool operator < (std::vector<int>& a, std::vector<int>& b) {
	if (a.size() < b.size()) return true;
	if (a.size() > b.size()) return false;
	for (int i = a.size() - 1; i >= 0; i --) {
		if (a[i] < b[i]) return true;
		if (a[i] > b[i]) return false;	
	}	
	return false;
}

inline bool operator >= (std::vector<int>& a, std::vector<int>& b) {
	if (a.size() > b.size()) return true;
	if (a.size() < b.size()) return false;
	for (int i = a.size() - 1; i >= 0; i --) {
		if (a[i] > b[i]) return true;
		if (a[i] < b[i]) return false;	
	}	
	return true;
}

inline bool operator <= (std::vector<int>& a, std::vector<int>& b) {
	if (a.size() < b.size()) return true;
	if (a.size() > b.size()) return false;
	for (int i = a.size() - 1; i >= 0; i --) {
		if (a[i] < b[i]) return true;
		if (a[i] > b[i]) return false;	
	}	
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::vector<int> a;
	int b;
	int n;
	std::cin >> n >> b;
	int x;
	for (int i = 0; i < n; i ++) {
		std::cin >> x;
		a.push_back(x);	
	}	
	std::reverse(a.begin(), a.end());
	// std::reverse(b.begin(), b.end());

	std::vector<int> res = a / b;
	for (int i = res.size() - 1; i >= 0; i --) {
		std::cout << res[i];
	}
	std::cout << "\n";
	return 0;
}