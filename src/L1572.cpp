#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
	return !b ? a : gcd(b, a % b);
}

inline bool is(char c) {
	return c >= '0' && c <= '9';
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	int n = s.size();
	LL a = 0, b = 1, ope, i = 0;
	if (s[0] == '-') { ope = -1; i ++; }
	else ope = 1;

	while (i < n) {
		LL t1 = 0, t2 = 0;
		while (is(s[i])) t1 = t1 * 10 + s[i ++] - '0';
		i ++;
		while (i < n && is(s[i])) t2 = t2 * 10 + s[i ++] - '0';
		LL tmp_b = b * t2, tmp_a = a * t2 + ope * b * t1, gg = gcd(abs(tmp_b), abs(tmp_a));
		a = tmp_a / gg, b = tmp_b / gg;
		if (i < n) ope = s[i ++] == '+' ? 1 : -1;
	}
	if (b == 1) cout << a;
	else cout << a << "/" << b;
	cout << "\n";
	return 0;
}