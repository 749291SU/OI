#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

const double eps = 1e-8;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int t = 0; t <= 6 * 3600 + 59 * 60 + 59; t ++) {
		double a = (double) 23 * t / 240, b = (double) 59 * t / 10;
		while (a - 360 > eps) a -= 360;	
		while (b - 360 > eps) b -= 360;
		if (a - 180 > eps) a = 360 - a;
		if (b - 180 > eps) b = 360 - b;
		if (fabs(a - 2 * b) < eps) {
			// cout << t << "\n";
			cout << t / 3600 << " " << (t % 3600) / 60 << " " << t % 3600 % 60 << "\n";
		}
	}

	return 0;
}