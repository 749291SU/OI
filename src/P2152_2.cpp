#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

const int Y = 7, CC = 1e7;

inline void compas_bit(std::vector<i64>& a) {
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

inline bool operator < (std::vector<i64>& a, std::vector<i64>& b) {
	if (a.size() < b.size()) return true;
	if (a.size() > b.size()) return false;
	for (int i = a.size() - 1; i >= 0; i --) {
		if (a[i] > b[i]) return false;
		if (a[i] < b[i]) return true;
	}	
	return false;
}

std::vector<i64> gcd(std::vector<i64> a, std::vector<i64> b) {
	int t = 0;
	if (a < b) swap(a, b);		
	while (!(a[0] & 1) && !(b[0] & 1)) { a = a / 2; b = b / 2; t ++; }

	while (!(a == b)) {
		int t1 = a[0] & 1, t2 = b[0] & 1;	
		!t1 ? a = a / 2 : !t2 ? b = b / 2 : a = a - b;
		if (a < b) swap(a, b);
	}
	while (t --) a = a * 2;
	return a;
}

// inline void print_vec(std::vector<i64>& a) {
// 	for (int i = 0; i < a.size(); i ++) std::cout << a[i] << " ";
// 	std::cout << "\n";
// }

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::string a, b; std::cin >> a >> b;
	std::vector<i64> aa, bb;

	for (int i = a.size() - 1; i >= 0; i --) aa.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i --) bb.push_back(b[i] - '0');

	compas_bit(aa); compas_bit(bb);

	std::vector<i64> res = gcd(aa, bb);
	for (int i = res.size() - 1; i >= 0; i --) {
		i64 x = res[i];
		std::vector<int> t;
		do {
			t.push_back(x % 10);
			x /= 10;
		} while (x);
		for (int j = t.size() - 1; j >= 0; j --) std::cout << t[j];
	}
	std::cout << "\n";
	return 0;
}