#pragma once
#include "StackArr.hpp"

StackArr::StackArr() {
	size_ = 0;
	index_top_ = -1;
	data_ = nullptr;
}

StackArr::StackArr(const StackArr& other) {
	index_top_ = other.index_top_;
	size_ = other.size_;
	if (other.size_ != -1) {
		data_ = new(Complex[other.size_]);
		for (int i = 0; i < size_; ++i) {
			data_[i] = other.data_[i];
		}
	}
	else {
		data_ = nullptr;
	}
}

StackArr& StackArr::operator=(const StackArr& other) {
	//delete[] data_;
	index_top_ = other.index_top_;
	size_ = other.size_;
	if (size_ > 0) {
		data_ = new Complex[size_];
		for (int i = 0; i < other.size_; ++i) {
			data_[i] = other.data_[i];
		}
	}
	else {
		data_ = nullptr;
	}
	return *this;
}

StackArr::StackArr(StackArr&& other) noexcept{
	data_ = other.data_;
	head_ = other.head_;
	index_top_ = other.index_top_;
	size_ = other.size_;
	other.data_ = nullptr;
	other.index_top_ = 0;
	other.size_ = 0;
	

}

StackArr& StackArr::operator=(StackArr&& other) noexcept {
	data_ = other.data_;
	index_top_ = other.index_top_;
	size_ = other.size_;
	other.data_ = nullptr;
	other.index_top_ = 0;
	other.size_ = 0;
	return *this;
}

StackArr::~StackArr() {
	if (data_) {
		delete[] data_;
		size_ = 0;
		
	}
}

bool StackArr::IsEmpty() {
	return (index_top_ < 0);
}
void StackArr::Pop() {
	index_top_ -= 1;
}
Complex& StackArr::Top() {
	if (index_top_ > -1) {
		return data_[index_top_];

	}
	else {
		throw std::out_of_range("StackArr is Emty");
		
	}

}
void StackArr::Clear() {
	size_ = 0;
	index_top_ = -1;
}

void StackArr::Push(const Complex& value) noexcept{
	if (size_ > 0 && ((index_top_ + 1) == (size_ - 1))) {
		data_[index_top_ + 1] = value;
		index_top_ += 1;
	}
	else {
		std::ptrdiff_t new_size_ = size_ + 1;
		std::ptrdiff_t new_index_top_ = index_top_ + 1;
		Complex* new_data_ = new Complex[new_size_];
		for (int i = 0; i < size_; ++i) {
			new_data_[i] = data_[i];
		}
		delete[] data_;
		new_data_[new_index_top_] = value;
		index_top_ = new_index_top_;
		size_ = new_size_;
		data_ = new_data_;


	}



}
void StackArr::GetTop() {
	if (IsEmpty()) {
		std::cout << "Stack is empty." << std::endl;
	}
	else {
		std::cout << "Top element: " << Top() << std::endl;
	}
}
