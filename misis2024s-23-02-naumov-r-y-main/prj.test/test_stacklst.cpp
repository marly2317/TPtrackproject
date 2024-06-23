#include "stackLst/stackLst.hpp"
#include<iostream>
int main() {
	StackLst lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(15);
	lst.pop_back();
	lst.pop_back();
	StackLst lst1(lst);
	std::cout << lst1.getSize();
	StackLst lst2 = lst;

	std::cout << lst.getSize();

	std::cout << lst2.getSize();
}