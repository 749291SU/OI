#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int n;

struct Node {
	int w;
	string color;
	bool operator < (const Node& ths) const {
		return w > ths.w;
	}
} mit[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i ++) cin >> mit[i].w >> mit[i].color;

	sort(mit, mit + n);

	for (int i = 0; i < n; i ++) cout << mit[i].color << "\n";

	return 0;
}