#include <iostream>

class Node {
  public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
  public:
    LinkedList() : head(nullptr) {}

    // Function to add a node at the end of the list
    void append(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to print the list
    void printList() {
        Node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

  private:
    Node *head;
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.printList();

    return 0;
}
