#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<int> p;
	for (int i = 0; i < 10; i ++) p.push_back(i);

	// auto f = [] (int a, int b) { return a + b; };
	// sort(p.begin(), p.end(), )	
	// cout << f(1, 2) << "\n";
	sort(p.begin(), p.end(), [](int a, int b) { return a > b; });
	// for (int i = 0; i < p.size(); i ++) cout << p[i];
	// cout << "\n";
	return 0;
}