#include "queueLst/queueLst.hpp"
#include<iostream>
int main() {
    QueueLst lst;
    lst.Push(5);
    lst.Push(10);
    lst.Push(15);
    std::cout << lst.take_front();
}
