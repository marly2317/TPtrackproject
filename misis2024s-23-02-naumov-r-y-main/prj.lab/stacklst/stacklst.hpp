#pragma once
#ifndef STACKLST_HPP
#define STACKLST_HPP
#include<iostream>

class StackLst {
public:
	StackLst();
	~StackLst();
	StackLst(const StackLst& other);
	StackLst& operator =(const StackLst& other);
	void push_back(int data);
	int getSize() {
		return Size;
	}
	StackLst(StackLst&& other) noexcept;
	StackLst& operator =(StackLst&& other) noexcept;
	int& top();
	bool IsEmpty();
	int pop_back();
	void Clear() noexcept;
private:
	
	class Node {
	public:
		int data;
		Node* pnext;
		Node(int data = 0, Node* pnext = nullptr) {
			this->data = data;
			this->pnext = pnext;

		}
	};
	Node* head;
	int Size;

};
#endif




