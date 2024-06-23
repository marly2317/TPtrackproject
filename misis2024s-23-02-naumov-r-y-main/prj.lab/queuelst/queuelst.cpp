#include "QueueLst.hpp"

QueueLst::QueueLst() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}


QueueLst::~QueueLst() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    count = 0;
}



void QueueLst::Push(int data) {
    Node* temp = new Node(data, nullptr);
    if (tail == nullptr) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    count++;
}


int QueueLst::take_front() {
    if (head == nullptr) {
        throw std::out_of_range("Queue is empty");
    }
    Node* temp = head;
    int data = temp->data;
    head = head->next;
    delete temp;
    count--;
    if (head == nullptr) {
        tail = nullptr;
    }
    return data;
}



int& QueueLst::front() {
    if (head == nullptr) {
        throw std::out_of_range("Queue is empty");
    }
    return head->data;
}


int& QueueLst::back() {
    if (tail == nullptr) {
        throw std::out_of_range("Queue is empty");
    }
    return tail->data;
}


int QueueLst::size() {
    return count;
}


bool QueueLst::empty() {
    return count == 0;
}