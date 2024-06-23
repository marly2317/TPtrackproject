#include<iostream>
#include<fstream>
#include<vector>
int main() {
	int p = 0;
	std::cin >> p;
	while (p-- > 0) {
		std::vector<std::string> sh(8);
		for (auto& it : sh) {
			std::cin >> it;
		}
		int rans = -1;
		int cans = -1;
		for (int r = 1; r < 7; ++r) {
			for (int c = 1; c < 7; ++c) {
				if (sh[r - 1][c - 1] == '#' && sh[r + 1][c - 1] == '#' && sh[r + 1][c + 1] == '#' && sh[r - 1][c + 1] == '#') {
					rans = r + 1;
					cans = c + 1;
				}
			}
		}
		std::cout << rans << ' ' << cans << std::endl;
	}
}