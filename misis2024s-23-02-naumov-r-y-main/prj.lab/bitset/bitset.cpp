#include "BitSet.hpp"

#include <stdexcept>
#include <algorithm>

BitSet::BitSet(const uint32_t size) {
	if (size <= 0){
		throw std::invalid_argument("size should be >0");
	}
	size_ = size;
	data_ = std::vector<uint32_t>(size_, 0);
	
}



BitSet::BitSet(const BitSet& other) {
	this->size_=other.size_;
	this->data_=other.data_;
}


BitSet::BitSet(BitSet&& other) noexcept {
	this->size_=other.size_;
	this->data_ = std::move(other.data_);
	other.size_ = 0;
	
}


BitSet& BitSet::operator=(const BitSet& other) {
	if (this->data_ != other.data_){
		this->size_ = other.size_;
		this->data_ = other.data_;
	}
	return *this;

}

BitSet& BitSet::operator=(BitSet && other) noexcept{
	this->size_ = other.size_;
	this->data_ = std::move(other.data_);
	other.size_ = 0;
	return *this;
}


bool BitSet::operator==(const BitSet& other) {
	return ((this->size_ == other.size_) && (this->data_ == other.data_));
}


bool BitSet::operator!=(const BitSet& other) {
	return !((this->size_ == other.size_) && (this->data_ == other.data_));
}


BitSet& BitSet::operator~() {
	for (uint32_t i = 0; i < size_; ++i) {
		if (data_[i] == 1) {
			data_[i] = 0;
		}
		else {
			data_[i] = 1;
		}
	}
	return *this;
}

BitSet& BitSet::operator&=(const BitSet& other) {
	for (uint32_t i; i < size_; ++i) {
		this->data_[i] *= other.data_[i];
	}
	return *this;
}


BitSet& BitSet::operator|=(const BitSet& other) {
	for (uint32_t i; i < size_; ++i) {
		this->data_[i] += other.data_[i];
	}
	return *this;
}


BitSet& BitSet::operator^=(const BitSet& other) {
	for (uint32_t i; i < size_; ++i) {
		if (this->data_[i] != other.data_[i]) {
			this->data_[i] = 1;
		}
		else {
			this->data_[i] = 0;
		}
	}
	return *this;
}

BitSet BitSet::operator&(const BitSet& other) const {
	BitSet result(std::min(size_, other.size_));
	for (uint32_t i = 0; i < result.data_.size(); ++i) {
		result.data_[i] = data_[i] & other.data_[i];
	}
	return result;
}


BitSet BitSet::operator|(const BitSet& other) const {
	BitSet result(std::max(size_, other.size_));
	for (uint32_t i = 0; i < result.data_.size(); ++i) {
		if (i < data_.size() && i < other.data_.size()) {
			result.data_[i] = data_[i] | other.data_[i];
		}
		else if (i < data_.size()) {
			result.data_[i] = data_[i];
		}
		else {
			result.data_[i] = other.data_[i];
		}
	}
	return result;
}


BitSet BitSet::operator^(const BitSet& other) const {
	BitSet result(std::max(size_, other.size_));
	for (uint32_t i = 0; i < result.data_.size(); ++i) {
		if (i < data_.size() && i < other.data_.size()) {
			result.data_[i] = data_[i] ^ other.data_[i];
		}
		else if (i < data_.size()) {
			result.data_[i] = data_[i];
		}
		else {
			result.data_[i] = other.data_[i];
		}
	}
	return result;
}



uint32_t BitSet::Size() {
	return size_;
}


void BitSet::Resize(const uint32_t size) {
	if (size < 0) {
		throw std::invalid_argument("Size should be >= 0");
	}
	size_ = size;
	// Используем std::vector::resize для изменения размера data_
	data_.resize(size);
}


bool BitSet::Get(uint32_t indx) {
	if ((indx < 0) || (indx >= size_)) {
		throw std::out_of_range("BitSet::Get: out of range");
	}
	return data_[indx];
}

void BitSet::Set( uint32_t indx, const bool val) {
	if (indx < 0 || indx >= size_) {
		throw std::out_of_range("BitSet::Set: out of range");
	}
	data_[indx] = val;
}


void BitSet::Fill(const bool val) noexcept {
	uint32_t fill_value = (val ? 1 : 0);
	std::fill(data_.begin(), data_.end(), fill_value);
}

int32_t BitSet::operator[](const uint32_t indx) {
	return data_[indx];
}


void BitSet::Clear() {
	size_ = 0;
	data_.clear();
}


std::ostream& BitSet::Writetxt(std::ostream& os) {
	for (uint32_t i = 0; i < size_; ++i) {
		os<<data_[i];
	}
	return os;
}

std::istream& BitSet::ReadTxt(std::istream& is) {
	std::string str;
	is >> str;
	size_ = str.size();
	uint32_t* data_=new uint32_t[size_];
	for (uint32_t i = 0; i < size_; ++i) {
		data_[i] = str[i] - '0';
	}
	return is;	
}

std::ostream& operator<<(std::ostream& os, BitSet& bs) {
	for (uint32_t i = 0; i < bs.Size(); ++	i) {
		os << bs.Get(i);
	}
	return os;
}


std::istream& operator>>(std::istream& is, BitSet& bs) {
	std::string str;
	is >> str;
	bs.Resize(str.size());
	for (uint32_t i = 0; i < bs.Size(); ++i) {
		bs.Set(i,str[i] - '0');
	}
	return is;
}


std::ostream& BitSet::WriteBinary(std::ostream& os) {
	for (uint32_t i = 0; i < size_; ++i) {
		os.write(reinterpret_cast<char*>(&data_[i]), sizeof(data_));
	}
	return os;
}


std::istream& BitSet::ReadBinary(std::istream& is) {
	for (uint32_t i = 0; i < size_; ++i) {
		is.read(reinterpret_cast<char*>(&data_[i]), sizeof(data_));
	}
	return is;
}


std::string BitSet::Tostring() noexcept {
	std::string result = "";
	for (int i = 0; i < data_.size(); ++i) {
		if (data_[i]) {
			result += "1";
		}
		else {
			result += "0";
		}
	}
	return result;
}

BitSet::BitSet(const std::string& str) {
	size_ = str.size();
	data_ = std::vector<uint32_t>(size_, 0);
	for (uint32_t i = 0; i < size_; ++i) {
		data_[i] = str[i]-'0';
	}
}