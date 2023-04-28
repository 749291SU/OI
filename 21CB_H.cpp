#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long LL;
LL n;
int k;

LL c[62][51];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	c[0][0] = 1;	
	for (int i = 1; i <= 61; i ++) {
		c[i][0] = 1;
		for (int j = 1; j <= min(50, i); j ++) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}

	cin >> n >> k;
	LL res = 0;

	while (true) {
		if (n == 0 || k < 0) break;
		int a = log2(n), b = log2(n + 1) - 1;		
		res += c[b + 1][k];	
		if (a == b) break;
		else {
			n -= 1ll << a;	
			k --;
		}
	}				
	cout << res << "\n";
	return 0;
}