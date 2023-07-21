#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

const i64 Y = 8, CC = 1e8;

inline void compress_bit(std::vector<i64>& a) {
	i64 x = 0;
	int p1 = 0;
	for (int i = 0; i < a.size(); i += Y) {
		x = 0;
		for (int j = std::min(i + Y, (int) a.size()) - 1; j >= i; j --) {
			x = x * 10 + a[j];
		}
		a[p1 ++] = x;
	}	
	while (a.size() > p1) a.pop_back();
}

inline std::vector<i64> operator + (std::vector<i64>& a, std::vector<i64>& b) {
	std::vector<i64> res;
	i64 t = 0;
	for (int i = 0, j = 0; i < a.size() || j < b.size(); i ++, j ++) {
		i64 v1 = i < a.size() ? a[i] : 0;
		i64 v2 = j < b.size() ? b[j] : 0;
		t += v1 + v2;
		res.push_back(t % CC);
		t /= CC;		
	}	
	if (t) res.push_back(1);
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}

inline std::vector<i64> operator - (std::vector<i64> a, std::vector<i64> b) {
	for (int i = 0; i < b.size(); i ++) {
		if ((a[i] -= b[i]) < 0) a[i] += CC, -- a[i + 1]; 
	}
	while (a.size() > 1 && !a.back()) a.pop_back();
	return a;
}

inline std::vector<i64> operator * (std::vector<i64> a, i64 b) {
	i64 t = 0;
	for (int i = 0; i < a.size(); i ++) {
		t += b * a[i];
		a[i] = t % CC;
		t /= CC;
	}		
	while (t) { a.push_back(t % CC); t /= CC; }
	while (a.size() > 1 && !a.back()) a.pop_back();
	return a;
}

inline std::vector<i64> operator * (std::vector<i64>& a, std::vector<i64>& b) {
	std::vector<i64> res;
	for (int i = 0; i < b.size(); i ++) {
		std::vector<i64> tmp;	
		i64 x = b[i];
		i64 t = 0;
		for (int j = 0; j < a.size(); j ++) {
			t += a[j] * x;
			tmp.push_back(t % CC);
			t /= CC;
		}
		while (t) { tmp.push_back(t % CC); t /= CC; }

		i64 offset = i;
		for (int p = 0, q = -offset; p < res.size() || q < tmp.size(); p ++, q ++) {
			i64 v1 = p < res.size() ? res[p] : 0;
			i64 v2 = q >= 0 ? tmp[q] : 0;
			t += v1 + v2;
			if (p >= res.size()) res.push_back(t % CC);
			else res[p] = t % CC;
			t /= CC;
		}
		if (t) res.push_back(1);
	}
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}

inline std::vector<i64> operator / (std::vector<i64> a, i64 b) {
	i64 t = 0;
	for (int i = a.size() - 1; i >= 0; i --) {
		a[i] += t * CC;
		t = a[i] % b;
		a[i] /= b;
	}
	while (a.size() > 1 && a.back() == 0) a.pop_back();
	return a;
}

inline i64 operator % (std::vector<i64> a, i64 b) {
	i64 res = 1;
	for (int i = a.size() - 1; i >= 0; i --) {
		res = (res * CC + a[i])	% b;
	}
	return res;
}

inline bool operator > (std::vector<i64>& a, std::vector<i64>& b) {
	if (a.size() > b.size()) return true;
	if (a.size() < b.size()) return false;
	for (i64 i = a.size() - 1; i >= 0; i --) {
		if (a[i] > b[i]) return true;
		if (a[i] < b[i]) return false;	
	}	
	return false;
}

inline bool operator < (std::vector<i64>& a, std::vector<i64>& b) {
	if (a.size() < b.size()) return true;
	if (a.size() > b.size()) return false;
	for (i64 i = a.size() - 1; i >= 0; i --) {
		if (a[i] < b[i]) return true;
		if (a[i] > b[i]) return false;	
	}	
	return false;
}

inline bool operator >= (std::vector<i64>& a, std::vector<i64>& b) {
	if (a.size() > b.size()) return true;
	if (a.size() < b.size()) return false;
	for (i64 i = a.size() - 1; i >= 0; i --) {
		if (a[i] > b[i]) return true;
		if (a[i] < b[i]) return false;	
	}	
	return true;
}

inline bool operator <= (std::vector<i64>& a, std::vector<i64>& b) {
	if (a.size() < b.size()) return true;
	if (a.size() > b.size()) return false;
	for (i64 i = a.size() - 1; i >= 0; i --) {
		if (a[i] < b[i]) return true;
		if (a[i] > b[i]) return false;	
	}	
	return true;
}

// inline std::vector<i64> operator / (std::vector<i64>& a, std::vector<i64>& b) {
// 	std::vector<i64> res, tmp, tmp1;
// 	for (int i = a.size() - 1; i >= 0; i --) {
// 		std::reverse(tmp.begin(), tmp.end());
// 		tmp.push_back(a[i]); std:reverse(tmp.begin(), tmp.end());
// 		i64 j = CC - 1; tmp1 = multiply(b, j);
// 		while (j > 0 && better(tmp1, tmp)) {
// 			j --;
// 			tmp1 = multiply(b, j);
// 		}
// 		res.push_back(j);
// 		tmp = subtract(tmp, tmp1);	
// 	}		
// 	std::reverse(res.begin(), res.end());
// 	while (res.size() > 1 && res.back() == 0) res.pop_back();
// 	return res;	
// }

inline void print(std::vector<i64>& res) {
	std::cout << res[res.size() - 1];
	for (int i = res.size() - 2; i >= 0; i --) {
		std::cout << std::setw(Y) << std::setfill('0') << res[i];
	}	
	std::cout << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::vector<i64> a;
	i64 b;
	int n, m;
	std::cin >> n >> b;
	i64 x, t;
	for (int i = 0; i < n; i ++) {
		std::cin >> x;
		a.push_back(x);	
	}	
	compress_bit(a);
	std::reverse(a.begin(), a.end());
	// std::reverse(b.begin(), b.end());

	std::vector<i64> res = a * b;
	for (i64 i = res.size() - 1; i >= 0; i --) {
		i64 tmp = res[i];	
		std::vector<int> tt;
		while (tmp > 0) {
			tt.push_back(tmp % 10);
			tmp /= 10;
		}
		for (int i = tt.size() - 1; i >= 0; i --) std::cout << tt[i];
		// std::cout << res[i];
	}
	std::cout << "\n";
	return 0;
}
