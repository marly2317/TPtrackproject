#include<iostream>
using namespace std;
int t, x;
void work() {
	cout << 31 << endl;
	for (int i = 0; i < 31; i++) {
		if (x % 2) {
			if (x % 4 == 3) {
				cout << -1 << ' ';
				x++;
			}
			else cout << 1 << ' ';
		}
		else cout << 0 << ' ';
		x /= 2;
	}
	cout << endl;
}
int main() {
	cin >> t;
	while (t--) {
		cin >> x;
		work();
	}
}
