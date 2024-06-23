#include "QueueArr.hpp"
#include<iostream>
#include <algorithm>
QueueArr::QueueArr(const QueueArr& other) {
	this->size_ = other.size_;
	this->cap_ = other.cap_;
	head_ = 0;
	tail_ = 0;
	data_ = new Complex[cap_];
	for (int i = 0; i < size_; ++i) {
		data_[i] = other.data_[i];
	}	

}




QueueArr::QueueArr(QueueArr&& other) {
	data_ = other.data_;
	size_ = other.size_;
	cap_ = other.cap_;
	head_ = other.head_;
	tail_ = other.tail_;
	other.data_ = nullptr;
	other.size_ = 0;
	other.cap_ = 0;
	other.head_ = 0;
	other.tail_ = 0;
}


QueueArr& QueueArr::operator=(const QueueArr& other) {
	if (this!=&other) {
		size_= other.size_;
		cap_ = other.cap_;
		head_ = other.head_;
		delete[] data_;
		tail_ = other.tail_;
		data_ = new Complex[cap_];
		for (int i = 0; i < size_; ++i) {
			this->data_[i] = other.data_[i];
		}
	}
	return *this;
 }

QueueArr& QueueArr::operator=(QueueArr&& other) noexcept {
	if (this != &other) {
		delete[] data_;
		size_ = other.size_;
		cap_ = other.cap_;
		head_ = other.head_;
		tail_ = other.tail_;
		other.data_ = nullptr;
		other.size_ = 0;
		other.cap_ = 0;
		other.head_ = 0;
		other.tail_ = 0;

	}
	return *this;

}

QueueArr::~QueueArr() {
	delete[]data_;
	data_ = nullptr;
	head_ = 0;
	tail_ = 0;
	cap_ = 0;
	size_ = 0;
}


void QueueArr::Pop() noexcept {
	if (size_ > 0) {
		head_ = (head_ + 1) % cap_;
		--size_;
	}
}


void QueueArr::Push(const Complex& value) {
	if (size_ == 0) {
		cap_ = 8;
		data_ = new Complex[cap_];
		data_[0] = value;
		++size_;
	}	
	if (size_ == cap_) {
		cap_ *= 2;
		Complex* new_data_ = new Complex[cap_];
		for (int i = 0; i < size_; ++i) {
			new_data_[i] = data_[i];
		}
		delete[] data_;
		data_ = new_data_;
		tail_ = size_;
		data_[tail_] = value;
		size_++;
	}
	tail_ = (tail_ + 1) % cap_;
	data_[tail_] = value;
	++size_;
	
}



Complex& QueueArr::Top() {
	if (IsEmpty()) {
		throw std::logic_error("Queue is empty");
	}
	return data_[head_];
}




void QueueArr::Clear() noexcept{
	delete[] data_;
	data_ = nullptr;
	head_ = 0;
	tail_ = 0;
	size_ = 0;
	cap_ = 0;
}


