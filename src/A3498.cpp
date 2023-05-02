#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using i64 = long long;

int a[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool check(int year) {
	return (year % 4 == 0 && year % 100) || year % 400 == 0;
}

inline int getd(int year, int mon, int day) {
	int res = 0;
	for (int i = 1; i < year; i ++) {
		res += check(i) ? 366 : 365;
	}
	if (check(year)) {
		for (int i = 0; i < mon; i ++) res += a[i];		
	}	
	else {
		for (int i = 0; i < mon; i ++) res += b[i];
	}
	res += day;
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	std::string s1, s2;

	while (std::cin >> s1 >> s2) {
		int year1 = stoi(s1.substr(0, 4)), year2 = stoi(s2.substr(0, 4));
		int mon1 = stoi(s1.substr(4, 2)), mon2 = stoi(s2.substr(4, 2));
		int day1 = stoi(s1.substr(6, 2)), day2 = stoi(s2.substr(6, 2));
		std::cout << std::abs(getd(year1, mon1, day1) - getd(year2, mon2, day2)) + 1 << "\n";
	}
	return 0;
}