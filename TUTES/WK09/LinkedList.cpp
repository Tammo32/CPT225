#include <iostream>
#include <string>

class node {
    public:
    int data;
    node *next;

    node() {}
};

class linked_list {
    private:
    node *head, *tail;

    public:
    node * gethead() {
        return this->head;
    }

    linked_list() {
        head = NULL;
        tail = NULL;
    }

    void addEnd(int n) {
        node *tmp = new node();
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }

/*
    node *newNode(int data) {
        node *temp = new node;
        temp->data = data;
        temp->next = NULL;
        return temp;
    }
*/

    void removeEnd() {
        node *temp = head;
        node *secondLast = NULL;

        while(temp->next != NULL) {
            secondLast = temp;
            temp = temp->next;

        }
        secondLast->next = NULL;
    }

    void addFront(int n) {
        node *tmp = new node();
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tmp->next = head;
            head = tmp;
        }
    }

    void removeFront() {
        if(head == NULL) { 
            return; 
        }
        else if(head == tail) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
        }
    }

    void printAll() {
        node *temp = head;

        while (temp->next != NULL) {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }

        std::cout << temp->data << std::endl;
    }


    // RECURSIVE FUNCTIONS
    int size(node* head) {
        // base case
        if (head->next == nullptr) {
            return 1;
        }
        else {
            // do the recursion
            return 1 + size(head->next);
        }
    }

    void printAll_recursively(node* head) {
        // base case
        if(head == nullptr) {
            return;
        }
        // recursion
        std::cout << head->data << " ";
        printAll_recursively(head->next);
    }

    node* addEndRecursively(node* head, int n) {
        if (head == nullptr) {
            node* temp = new node;
            temp->data = n;
            temp->next = nullptr;
            return temp;
        } else {
            head->next = addEndRecursively(head->next, n);
        }
        return head;
    }

    void deleteListRecursively(node* head) {
        // base case
        if (head == nullptr) {
            return;
        } else {
            deleteListRecursively(head->next);
            delete head;
        }
    }

    node* deleteNodeRecursively(node* head, int k) {
        // invalid function
        if (k < 1) {
            return head;
        }
        // if linked list is empty
        if (head == nullptr) {
            return nullptr;
        }

        // base case (start needs to be deleted)
        if (k == 1) {
            node* temp = head->next;
            delete(head);
            return temp;
        }

        head->next = deleteNodeRecursively(head->next, k-1);
        return head;
    }

    node* deleteNodeRecursivelyByData(node* head, int data) {
        // if linked list is empty
        if (head == nullptr) {
            std::cout << "Data was not found" << std::endl;
            return nullptr;
        }

        // base case (start needs to be deleted)
        if (head->data == data) {
            node* temp = head->next;
            delete(head);
            return temp;
        }

        head->next = deleteNodeRecursivelyByData(head->next, data);
        return head;
    }



};

int main() {
    linked_list test;

    test.addEnd(1);
    test.addEnd(2);
    test.addEnd(3);
    test.addEnd(4);
    test.addEnd(5);
    test.addEnd(6);
    test.addEnd(7);
    test.addEndRecursively(test.gethead(), 8);
    test.addEndRecursively(test.gethead(), 9);
    test.addEndRecursively(test.gethead(), 10);

    test.printAll();

    std::cout << "Size is " << test.size(test.gethead()) << std::endl;
    test.printAll_recursively(test.gethead());

    test.deleteNodeRecursively(test.gethead(), 5);
    test.deleteNodeRecursivelyByData(test.gethead(), 6);
    std::cout << std::endl;
    test.printAll_recursively(test.gethead());
    
    return 0;
}