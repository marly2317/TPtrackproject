#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		ll x, y, z, vol;
		cin >> x >> y >> z >> vol;
		ll ans = 0;

		for (ll a = 1; a <= x; a++) {
			for (ll b = 1; b <= y; b++) {
				if (vol % (a * b) == 0) {
					ans = max(ans, (x - a + 1) * (y - b + 1) * (z - (vol / (a * b)) + 1));
				}
			}
		}
		cout << ans << endl;
	}
}