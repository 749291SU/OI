#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int sum[32];
int c[16], cnt;
int d[5] = {6, 10, 5, 9, 4};

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int i = 1; i <= 31; i ++) {
		int j = i, t = 0;
		while (j) {
			t += j % 10;
			j /= 10;	
		}
		sum[i] = t;
	}

	for (int i = 2001; i <= 2021; i ++) {
		if (i == 2004 || i == 2008 || i == 2012 || i == 2016 || i == 2020) continue;
		int j = i;
		int t = 0;
		while (j) {
			t += j % 10;
			j /= 10;
		}	
		c[cnt ++] = t;
	}	

	int ans = 0;
	for (int i = 0; i < 16; i ++) {
		for (int j = 1; j <= 12; j ++) {
			for (int k = 1; k <= a[j]; k ++) {
				int t = c[i] + sum[j] + sum[k];		
				int e1 = sqrt(t);
				if (e1 * e1 == t) ans ++;
			}	
		}	
	}
	for (int i = 0; i < 5; i ++) {
		for (int j = 1; j <= 12; j ++) {
			for (int k = 1; k <= b[j]; k ++) {
				int t = d[i] + sum[j] + sum[k];		
				int e1 = sqrt(t);
				if (e1 * e1 == t) ans ++;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}