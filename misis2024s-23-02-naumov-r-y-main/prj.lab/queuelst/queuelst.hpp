#pragma once
#include<iostream>
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

class QueueLst {
public:
    QueueLst();
    ~QueueLst();
    void Push(int data);  // Добавление элемента в конец очереди
    int take_front();  // Извлечение элемента из начала очереди
    int& front();  // Получение ссылки на первый элемент очереди
    int& back();  // Получение ссылки на последний элемент очереди
    int size();  // Получение количества элементов в очереди
    bool empty();  // Проверка, пуста ли очередь
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