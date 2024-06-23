#include<iostream>
#include"QueueLstPr.hpp"




bool QueueLstPr::IsEmpty() noexcept{
	return (head == nullptr);
}

void QueueLstPr::Push(const float& value) {
	Node* cur = head;
	Node* prev = nullptr;
	if (IsEmpty() == 1) {
		Node* newNode = new Node{ value };
		head = tail;
	}
	else {
		while (cur != nullptr && (cur->val < value)) {
			prev = cur;
			cur = cur->next;

		}
	}
	if (prev != nullptr) {
		prev->next = new Node{ value,cur };
	}
	else {
		head = new Node{ value,head };
	}


}

void QueueLstPr::Pop() noexcept{
	if (IsEmpty() == 0) {
		Node* del = head;
		head = head->next;
		delete del;


	}
	else {
		tail = nullptr;
	}
}


QueueLstPr::~QueueLstPr() noexcept {
	Clear();
}

void QueueLstPr::Clear() noexcept {
	while (IsEmpty() == 0) {
		Pop();
	}
}


float& QueueLstPr::Top(){	
	if (IsEmpty() == 1) {
		throw std::logic_error("QueueLstPr Is Empty");
	}
	
	return head->val;
	
}


QueueLstPr::QueueLstPr(const QueueLstPr& other) {
	Node* cur = other.head;
	Node* newHead = nullptr;
	Node* newTail = nullptr;

	while (cur != nullptr) {
		Node* newNode = new Node{ cur->val };
		if (newHead == nullptr) {
			newHead = newNode;
		}
		else {
			newTail->next = newNode;
		}
		newTail = newNode;
		cur = cur->next;
	}

	head = newHead;
	tail = newTail;
}


QueueLstPr& QueueLstPr::operator=(const QueueLstPr& other) {
	if (this != &other) {
		Clear();
		Node* current = other.head;
		while (current) {
			Push(current->val);
			current = current->next;
		}
	}
	return *this;
}


QueueLstPr::QueueLstPr(QueueLstPr&& other) noexcept {
	head = other.head;
	tail = other.tail;
	other.head = nullptr;
	other.tail = nullptr;
}


QueueLstPr& QueueLstPr::operator=(QueueLstPr&& other) noexcept {
	head = other.head;
	tail = other.tail;
	other.head = nullptr;
	other.tail = nullptr;
	other.Clear();
	return *this;
}
