#pragma once
#include<iostream>
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

class QueueLst {
public:
    QueueLst();
    ~QueueLst();
    void Push(int data);  // ���������� �������� � ����� �������
    int take_front();  // ���������� �������� �� ������ �������
    int& front();  // ��������� ������ �� ������ ������� �������
    int& back();  // ��������� ������ �� ��������� ������� �������
    int size();  // ��������� ���������� ��������� � �������
    bool empty();  // ��������, ����� �� �������
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int data = int(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };
    Node* head;
    Node* tail;
    int count;
};

#endif