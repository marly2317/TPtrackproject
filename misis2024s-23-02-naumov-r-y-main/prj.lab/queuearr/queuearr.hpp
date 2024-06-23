#pragma once
#include <cstddef>
#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP
#include "complex/complex.hpp"
class QueueArr {
private:
	Complex* data_ = nullptr;
	ptrdiff_t head_ = 0;
	ptrdiff_t size_ = 0;
	ptrdiff_t tail_ = 0;
	ptrdiff_t cap_ = 0;
public:
	QueueArr() = default;
	QueueArr(const QueueArr& other);
	QueueArr(const int& head);
	QueueArr(QueueArr&& other);
	~QueueArr();
	QueueArr& operator =(const QueueArr& other);
	QueueArr& operator =(QueueArr&& other) noexcept;
	void Pop() noexcept;
	void Push(const Complex& value);
	void Clear() noexcept;
	bool IsEmpty() noexcept{
		return size_ == 0;
	}
	Complex& Top();	
	void Print();
};
#endif