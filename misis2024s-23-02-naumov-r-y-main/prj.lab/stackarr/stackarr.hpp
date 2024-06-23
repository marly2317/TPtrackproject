#include<iostream>
#include <cstddef>
#include "complex/complex.hpp"
#ifndef STACKARR_HPP
#define STACKARR_HPP
class StackArr {
private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t index_top_ = -1;
	Complex* data_ = nullptr;
	Complex* head_ = nullptr;
public:
	StackArr();
	StackArr(const StackArr& other);
	StackArr(StackArr&& other) noexcept ;
	~StackArr();
	StackArr& operator=(const StackArr& other);
	StackArr& operator=(StackArr&& other) noexcept;
	bool IsEmpty();
	void Pop();
	void Push(const Complex& val) noexcept;
	Complex& Top();
	void Clear();
	Complex GetSize();
	void GetTop();


};
#endif