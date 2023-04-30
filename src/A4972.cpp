#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);

	int a, b, c;
	std::cin >> a >> b >> c;
	double t1 = std::sqrt(b * b - 4 * a * c);		
	double res1 = (t1 - b) / a / 2, res2 = (-t1 - b) / a / 2;

	std::cout << std::fixed << std::setprecision(6) << std::max(res1, res2) << "\n" << std::min(res1, res2) << "\n"; 
	return 0;
}