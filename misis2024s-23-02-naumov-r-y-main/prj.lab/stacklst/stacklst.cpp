#include "StackLst/StackLst.hpp"



StackLst::StackLst() {
	Size = 0;
	head = nullptr;

}



StackLst::~StackLst() {
	if (Size == 0) {
		std::cout << "queue is empty";
	}
}



void StackLst::push_back(int data) {
	if (head == nullptr) {
		Node* current = new Node(data, nullptr);
		head = current;
	}
	else {
		Node* new_node = new Node(data, head);
		head = new_node;
	}
	Size += 1;
}

int& StackLst::top() {
	return head->data;
}



bool StackLst::IsEmpty() {
	return (head == nullptr);
}


int StackLst::pop_back() {
	if (Size == 0) {
		return 0;
	}
	int data = head->data;
	Node* temp = head;
	head = head->pnext;
	delete temp;
	Size -= 1;
	return data;
}
StackLst::StackLst(const StackLst& other) {
	this->Size = other.Size;
	this->head = nullptr;
	Node* current = other.head;
	Node* temp = nullptr;
	while (current != nullptr) {
		Node* newNode = new Node(current->data, nullptr);
		if (head == nullptr) {
			head = newNode;
			temp = head;
		}
		else {
			temp->pnext = newNode;
			temp = temp->pnext;
		}
		current = current->pnext;
	}
}
StackLst& StackLst::operator =(const StackLst& other) {
	if (this == &other) {
		return *this;
	}
	this->Size = other.Size;
	this->head = nullptr;
	Node* current = other.head;
	Node* temp = nullptr;
	while (current != nullptr) {
		Node* newNode = new Node(current->data, nullptr);
		if (head == nullptr) {
			head = newNode;
			temp = head;
		}
		else {
			temp->pnext = newNode;
			temp = temp->pnext;
		}
		current = current->pnext;
	}
	return *this;
}

void StackLst::Clear() noexcept {
	while (head != nullptr) {
		Node* temp = head->pnext;
		delete head;
		head = temp;
	}
}

StackLst::StackLst(StackLst&& other) noexcept{
	head = nullptr;
	if (this != &other) {
		Clear();
		if (!other.IsEmpty()) {
			head = new Node;
			head->data = other.head->data;
			Node* temp = other.head;
			Node* prev = head;
			while (temp->pnext != nullptr) {
				temp = temp->pnext;
				Node* curr = new Node;
				prev->pnext = curr;
				curr->data = temp->data;
				prev = curr;
			}
		}
	}
	
}


StackLst& StackLst::operator=(StackLst&& other) noexcept{
		
	head = other.head;
	other.head = nullptr;
	Clear();

	return *this;
}