#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using i64 = long long;

inline std::vector<int> add(std::string& a, std::string& b) {
	std::vector<int> res;
	int t = 0;
	for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i --, j --) {
		int v1 = i >= 0 ? a[i] - '0' : 0;
		int v2 = j >= 0 ? b[j] - '0' : 0;
		t += v1 + v2;
		res.push_back(t % 10);
		t /= 10;		
	}	
	if (t) res.push_back(1);
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}

inline std::vector<int> subtract(std::string& a, std::string& b) {
	std::vector<int> res;
	int t = 0;
	for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i --, j --) {
		int v1 = i >= 0 ? a[i] - '0' : 0;
		int v2 = j >= 0 ? b[j] - '0' : 0;
		t += v1 - v2;	
		res.push_back((t % 10 + 10) % 10);	
		t = t >= 0 ? 0 : -1;
	}
	while (res.size() > 1 && res.back() == 0) res.pop_back();
	return res;
}

inline std::vector<int> multiply(std::string& a, std::string& b) {
	std::vector<int> res;
	for (int i = b.size() - 1; i >= 0; i --) {
		std::vector<int> tmp;	
		int x =  b[i] - '0';
		int t = 0;
		for (int j = a.size() - 1; j >= 0; j --) {
			t += (a[j] - '0') * x;
			tmp.push_back(t % 10);
			t /= 10;
		}
		while (t) { tmp.push_back(t % 10); t /= 10; }

		int offset = b.size() - i - 1;
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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int f;
	int flag_a = 0, flag_b = 0;
	int add_nega = 0, subtract_nega = 0;
	std::string a, b;
	std::cin >> a >> b;
	flag_a = a[0] == '-'; flag_b = b[0] == '-';
	if (flag_a) a = a.substr(1);
	if (flag_b) b = b.substr(1);

	f = a.size() < b.size() || (a.size() == b.size() && a < b);

	std::vector<int> res1, res2, res3 = multiply(a, b);	
	if (flag_a == flag_b) {
		add_nega = flag_a;
		subtract_nega = flag_a ? !f : f;
		res1 = add(a, b);
		res2 = f ? subtract(b, a) : subtract(a, b);
	}
	else {
		add_nega = flag_a ? !f : f;
		subtract_nega = flag_a;
		res1 = f ? subtract(b, a) : subtract(a, b);
		res2 = add(a, b);
	}
	
	if (add_nega) std::cout << "-";
	for (int i = res1.size() - 1; i >= 0; i --) std::cout << res1[i];
	std::cout << "\n";
	if (subtract_nega) std::cout << "-";
	for (int i = res2.size() - 1; i >= 0; i --) std::cout << res2[i];
	std::cout << "\n";
	if (flag_a ^ flag_b) std::cout << "-";
	for (int i = res3.size() - 1; i >= 0; i --) std::cout << res3[i];
	std::cout << "\n";

	return 0;
}