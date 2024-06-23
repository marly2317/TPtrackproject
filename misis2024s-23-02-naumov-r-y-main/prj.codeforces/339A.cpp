#include<iostream>
int main() {
	std::string ins;
	std::cin >> ins;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	for (int i = 0; i < ins.size(); ++i) {
		if (ins[i] == '1') {
			c1 += 1;
		}
		if (ins[i] == '2') {
			c2 += 1;
		}
		if (ins[i] == '3') {
			c3 += 1;
		}
	}
	std::string outs;
	for (int i = 0; i < c1; ++i) {
		outs += "1+";
	}
	for (int i = 0; i < c2; ++i) {
		outs += "2+";
	}
	for (int i = 0; i < c3; ++i) {
		outs += "3+";
	}
	outs.pop_back();
	std::cout << outs;
	return 0;
}