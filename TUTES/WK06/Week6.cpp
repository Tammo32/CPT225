#include <iostream>
#include <string>

class node {
    public:
    int data;
    node* next;
    // node* previous;

    node() {
        data = 0;
        next = NULL;
    };
};

class linkedList {
    private:
    node* head;
    node* tail; // this is optional but make your list computationally cheaper
    int length;

    public:
    // Constructor
    linkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    ~linkedList() {
        delete head;
        delete tail;
    }

    // Get length
    int getLength() {
        return length;
    }

    // Add front
    void addFront(int n) {
        node* temp = new node(); // on the heap (to be deleted) DECONSTRUCTOR
        temp->data = n;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
        length++;
    }

    // Remove front
    void removeFront() {
        if (head ==NULL) {
            std::cout << "cannot remove front" << std::endl;
            return;
        }
        else if (head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            node* temp = head;
            delete temp;

            head = head->next;
        }
        length--;
    }

    // Add end
    void addEnd(int n) {
        node* temp = new node(); // on the heap (to be deleted) DECONSTRUCTOR
        temp->data = n;
        temp->next = NULL;

        if(head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        length++;
    }

    // Remove end
    void removeEnd() {
        if (head == nullptr) {
            std::cout << "cannot remove end" << std::endl;
            return;
        }
        node* temp = head;

        while(temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        temp->next = NULL;
        tail = temp;
        length--;
    }

    // Print the list
    void printAll() {
        node* temp = head;

        if (temp == NULL) { // length == 0
            std::cout << "the link list is empty indeed!" << std::endl;
        }
        else {
            while(temp != NULL) {
            // for (int i = 0; i < length; i++)
            std::cout << temp->data << std::endl;
            temp = temp->next;
            }
        }
        // std::cout << std::endl;
    }
};

int main() {
    linkedList myList;

    myList.addFront(1);
    myList.addFront(2);
    myList.addFront(3);
    myList.printAll();
    
    return 0;
}