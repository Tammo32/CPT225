// void function1() {
//     int* ptr1 = new int(15); // on the heap
//     int x = 10;

//     if (x == 10) {
//         return;
//     }

//     delete ptr1;
//     return; 
// };


// // Version 2
// #include <memory>
// void function2() {
//     std::unique_ptr<int> ptr2(new int(10));

//     int x = 10;
//     if (x == 10) {
//         return;
//     }
//     return;
// }

#include <iostream>
#include <memory>

class node {
    private:
    int data;
    // node* next;
    std::shared_ptr<node> next;

    public:
    node();
    node(int d, std::shared_ptr<node> nextPtr);
    int getData();
    std::shared_ptr<node> getNext();
    void setNext(std::shared_ptr<node> nextPtr);
    ~node();
};

node::node() : data(0), next(nullptr) {};

node::node(int d, std::shared_ptr<node> nextPtr) : data(d), next(nextPtr) {};

int node::getData() { return data; };

std::shared_ptr<node> node::getNext() { return next; };

void node::setNext(std::shared_ptr<node> nextPtr) {
    next = nextPtr;
};

node::~node() {
    std::cout << "Deleting " << data << std::endl;
}

int main() {

    std::shared_ptr<node> head(new node(10,nullptr));
    std::shared_ptr<node> next1(new node(20,nullptr));
    std::shared_ptr<node> next2;

    // After a shared pointer is declared we can set it using reset
    next2.reset(new node(30,nullptr));

    // link the nodes
    head->setNext(next1);
    next1->setNext(next2);

    // print the list
    std::shared_ptr<node> temp = head;

    while(temp != nullptr) {
        std::cout << temp->getData() <<std::endl;
        temp = temp->getNext();
    }

    return 0;
}