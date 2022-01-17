#include <iostream>
#include <string>


template <class T> // <class T, ...etc>
class Node {
    public:
    int data;
    Node<T>* next;

    Node() {

    }
};

template <class T>
class linkedList {
    private:
    Node<T>* head;
    Node<T>* tail;

    public:
    linkedList(){
        head = NULL;
        tail = NULL;
    };

    void printAll() {
        Node<T>* temp = head;

        do {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
        while(temp->next != NULL);
        std::cout << temp->data << std::endl;
    };

    void addEnd(T x) {
        Node<T>* temp = new Node<T>(); // instantiate on the heap
        temp->data = x;
        temp->next = NULL;

        if(head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = tail->next;
        }
    };

    void addFront(T x) {
        Node<T>* temp = new Node<T>(); // instantiate on the heap
        temp->data = x;
        temp->next = NULL;

        if(head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
    };

    T removeFront() {
        T x;

        if (head == NULL) {
            std::cout << "List is empty" << std::endl;
        }
        else if (head == tail) {
            x = head->data;
            head = NULL;
            tail = NULL;
        }
        else {
            Node<T>* temp;
            temp = head;
            x = head->data;
            head = head->next;
            delete(temp);
        }
        return x;
    };

};

int main() {
    linkedList<bool> list1; // a list to store bool (bool data)
    list1.addFront(true);
    list1.addFront(false);
    list1.printAll();

    linkedList<double> list2; // a list to store double (double data)
    list2.addFront(10);
    list2.addFront(20);
    list2.addFront(30);
    list2.printAll();

    linkedList<int> list3;// a list to store int (int data)
    list2.addFront(10);
    list3.addFront(1);
    list3.addFront(2);
    list3.addFront(3);
    list3.printAll();

    std::cout << "Item removed: " << list3.removeFront() << std::endl;
    std::cout << "Item removed: " << list3.removeFront() << std::endl;
    std::cout << "Item removed: " << list3.removeFront() << std::endl;
    

    return 0;
}