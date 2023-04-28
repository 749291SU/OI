#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long a, b, c;


long long gcd(long long a, long long b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> c;
	cout << a * b * c / gcd(a, b) / gcd(a * b / gcd(a, b), c) << "\n";
	return 0;
}