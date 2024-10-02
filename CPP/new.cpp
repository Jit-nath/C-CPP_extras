#include <iostream>
template<typename t>
class LinkedList
{
    t val;
    LinkedList *NextNode;

public:
    // Constructor
    LinkedList(t data) : val(data), NextNode(nullptr) {}

    // Destructor to delete the entire list
    ~LinkedList()
    {
        // Recursively delete the next node
        delete NextNode;
    }

    // Insert a new node at the end of the list
    void insertEnd(t data)
    {
        LinkedList *newNode = new LinkedList(data);
        LinkedList *current = this;

        while (current->NextNode != nullptr)
        {
            current = current->NextNode;
        }
        current->NextNode = newNode;
    }

    // Display the linked list
    void display() const
    {
        const LinkedList *current = this;
        while (current != nullptr)
        {
            std::cout << current->val << " -> ";
            current = current->NextNode;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Delete the first occurrence of a value
    void deleteValue(t data)
    {
        LinkedList *current = this;
        LinkedList *previous = nullptr;

        while (current != nullptr && current->val != data)
        {
            previous = current;
            current = current->NextNode;
        }

        if (current == nullptr)
        {
            std::cout << "Value not found in the list." << std::endl;
            return;
        }

        if (previous == nullptr)
        {
            // The node to delete is the head node
            LinkedList *temp = this->NextNode;
            this->val = temp->val;
            this->NextNode = temp->NextNode;
            temp->NextNode = nullptr;
            delete temp;
        }
        else
        {
            previous->NextNode = current->NextNode;
            current->NextNode = nullptr;
            delete current;
        }
    }
};

int main()
{
    LinkedList<int> *head = new LinkedList(10);
    head->insertEnd(20);
    head->insertEnd(30);
    head->insertEnd(40);

    std::cout << "Linked list: ";
    head->display();

    head->deleteValue(30);

    std::cout << "Linked list after deleting 30: ";
    head->display();

    delete head; // This will recursively delete the entire list

    return 0;
}
