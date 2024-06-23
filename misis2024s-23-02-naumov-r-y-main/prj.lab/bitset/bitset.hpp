#pragma once
#ifndef BITSET_HPP
#define BITSET_HPP
#include <vector>
#include <cstdint>
#include <algorithm>
#include<iostream>
class BitSet {
private:
	uint32_t size_ = 0;
	std::vector<uint32_t> data_;
public:
	BitSet(const uint32_t size);
	BitSet() {
		data_ = std::vector<uint32_t>(size_, 0);
	}
	BitSet(const BitSet& other);//
	BitSet(BitSet&& other) noexcept;//
	~BitSet() = default;//
	BitSet& operator=(const BitSet& other);//
	BitSet& operator=(BitSet&& other) noexcept;//
	bool operator==(const BitSet& other);//
	bool operator!=(const BitSet& other);//
	BitSet& operator~();//
	BitSet& operator&=(const BitSet& other);//
	BitSet& operator|=(const BitSet& other);//
	BitSet& operator^=(const BitSet& other);//
	uint32_t Size();//
	void Resize(const uint32_t size);//
	bool Get(uint32_t indx);//
	void Set(uint32_t indx, const bool value);	//
	void Fill(const bool val) noexcept;//
	int operator[](const uint32_t indx);//
	void Clear();
	std::ostream& Writetxt(std::ostream& bi);
	std::istream& ReadTxt(std::istream& is);
	std::ostream& WriteBinary(std::ostream&);
	std::istream& ReadBinary(std::istream& is);
	std::string Tostring() noexcept;
	BitSet(const std::string& str);
	BitSet operator&(const BitSet& other) const;
	BitSet operator|(const BitSet& other) const;
	BitSet operator^(const BitSet& other) const;
	
};


//BitSet operator&(const BitSet& lhs, const BitSet& rhs);
//BitSet operator|(const BitSet& lhs, const BitSet& rhs);
//BitSet operator^(const BitSet& lhs, const BitSet& rhs);
std::ostream& operator<<(std::ostream& os, BitSet&);
std::istream& operator>>(std::istream& is, BitSet&);

#endif