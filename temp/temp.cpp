#include <iostream>

// Define the structure of a node in the doubly linked list
template <typename T>
struct Node {
    T data;            // Data stored in the node
    Node<T>* prev;     // Pointer to the previous node
    Node<T>* next;     // Pointer to the next node

    // Constructor to initialize a new node
    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

// Define the DoublyLinkedList class
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;  // Pointer to the head (first) node
    Node<T>* tail;  // Pointer to the tail (last) node

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to deallocate memory
    ~DoublyLinkedList() {
        clear();
    }

    // Method to check if the list is empty
    bool isEmpty() const { 
        return head == nullptr; 
    }

    // Method to insert a node at the beginning of the list
    void insertAtBeginning(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Method to insert a node at the end of the list
    void insertAtEnd(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Method to delete a node at a given position (0-indexed)
    void deleteAt(int position) {
        if (isEmpty() || position < 0) {
            return;
        }

        if (position == 0) { // Delete at the beginning
            Node<T>* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr; 
            } else {
                tail = nullptr; // If the list had only one node
            }
            delete temp;
            return;
        }

        Node<T>* current = head;
        int count = 0;
        while (current != nullptr && count < position) {
            current = current->next;
            count++;
        }

        if (current == nullptr) { // Position out of range
            return; 
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else { 
            tail = current->prev; // If deleting the last node
        }

        current->prev->next = current->next;
        delete current;
    }

    // Method to clear the entire list (deallocate memory)
    void clear() {
        while (!isEmpty()) {
            deleteAt(0); // Keep deleting the first node until the list is empty
        }
    }

    // Method to print the elements of the linked list
    void printList() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

// Example usage
int main() {
    DoublyLinkedList<int> list;

    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtBeginning(0);
    list.insertAtEnd(5);

    std::cout << "List: ";
    list.printList();  // Output: 0 1 3 5

    list.deleteAt(2); 
    std::cout << "List after deleting at position 2: ";
    list.printList(); // Output: 0 1 5 

    return 0;
}