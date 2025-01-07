#include <iostream>
using namespace std;

// Define a Node structure to represent each element in the linked list
struct Node {
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node in the list
};

// Define a LinkedList class to manage the linked list
class LinkedList {
public:
    // Constructor initializes the head pointer to nullptr
    LinkedList() : head(nullptr) {}

    // Method to append a new node with the given data to the end of the list
    void append(int data) {
        // Create a new node and set its data and next pointer
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        // If the list is empty, set the head to the new node
        if (head == nullptr) {
            head = newNode;
        } else {
            // Otherwise, traverse to the end of the list and add the new node
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Method to display the contents of the list
    void display() {
        Node* temp = head;  // Start from the head of the list
        while (temp != nullptr) {  // Traverse the list until the end
            cout << temp->data << " ";  // Print the data of each node
            temp = temp->next;  // Move to the next node
        }
        cout << endl;  // Print a newline at the end
    }

    // Recursive method to display the contents of the list
    void displayRecursive(Node* p) {
        if (p != nullptr) {
            cout << p->data << " "; // Print the data of the current node
            displayRecursive(p->next); // Recursive call to the next node
        }
    }

    // Method to count the number of nodes in the list
    int countNodes(Node* p) {
        int count = 0; // Initialize a counter
        while (p != nullptr) { // Traverse the list
            count++; // Increment the counter for each node
            p = p->next; // Move to the next node
        }
        return count; // Return the total count
    }

    // Recursive method to calculate the sum of node data
    int sumRecursive(Node* p) {
        if (p == nullptr) { // Base case: no nodes left
            return 0;
        }
        return sumRecursive(p->next) + p->data; // Recursive sum calculation
    }

    // Method to calculate the sum of node data iteratively
    int sum(Node* p) {
        int sum = 0; // Initialize the sum
        while (p != nullptr) { // Traverse the list
            sum += p->data; // Add the data of the current node
            p = p->next; // Move to the next node
        }
        return sum; // Return the total sum
    }

    // Method to find the maximum node value iteratively
    int max(Node* p) {
        int max = INT_MIN; // Initialize to the smallest possible integer
        while (p != nullptr) { // Traverse the list
            if (p->data > max) { // Update max if current node's data is larger
                max = p->data;
            }
            p = p->next; // Move to the next node
        }
        return max; // Return the maximum value
    }

    // Recursive method to find the maximum node value
    int maxRecursive(Node* p) {
        if (p == nullptr) { // Base case: no nodes left
            return INT_MIN;
        }
        int x = maxRecursive(p->next); // Recursive call to find the max in the rest of the list
        return x > p->data ? x : p->data; // Compare current node's data with the rest
    }

    // Method to perform a linear search iteratively
    int linearSearch(Node* p, int key) {
        while (p != nullptr) { // Traverse the list
            if (p->data == key) { // If the key is found
                return p->data;
            }
            p = p->next; // Move to the next node
        }
        return -1; // Return -1 if the key is not found
    }

    // Recursive method to perform a linear search
    int linearSearchRecursive(Node* p, int key) {
        if (p == nullptr) { // Base case: no nodes left
            return -1;
        }
        if (p->data == key) { // If the key is found
            return p->data;
        }
        return linearSearchRecursive(p->next, key); // Recursive call for the next node
    }

    // Iterative method to reverse the linked list
    void reverse(Node* p) {
        Node* q = nullptr; // Previous node pointer
        Node* r = nullptr; // Temporary node pointer
        while (p != nullptr) { // Traverse the list
            r = q; // Store the previous node
            q = p; // Update the current node
            p = p->next; // Move to the next node
            q->next = r; // Reverse the link
        }
        head = q; // Update the head pointer to the new first node
    }

    // Recursive method to reverse the linked list
    void reverseRecursive(Node* q, Node* p) {
        if (p != nullptr) { // Base case: nodes left to reverse
            reverseRecursive(p, p->next); // Recursive call for the next node
            p->next = q; // Reverse the link
        } else {
            head = q; // Update the head pointer to the new first node
        }
    }

    // Method to concatenate two linked lists
    void concatenate(Node* p, Node* q) {
        while (p->next != nullptr) { // Traverse to the end of the first list
            p = p->next;
        }
        p->next = q; // Link the last node of the first list to the first node of the second list
    }

    // Iterative method to reverse the list using an array
    void reverseList2(Node* p) {
        Node* temp = p; // Temporary pointer
        int i = 0; // Index counter
        int A[countNodes(p)]; // Array to store node data
        while (temp != nullptr) { // Traverse the list
            A[i] = temp->data; // Store node data in the array
            temp = temp->next; // Move to the next node
            i++;
        }
        temp = p; // Reset temp to the head of the list
        i--; // Adjust index to the last element of the array
        while (temp != nullptr) { // Traverse the list again
            temp->data = A[i]; // Assign reversed data from the array
            temp = temp->next; // Move to the next node
            i--; // Decrement the index
        }
    }

        void merge(LinkedList& list, LinkedList& list2) {
    Node* p = list.head;
    Node* q = list2.head;
    Node* last = nullptr;

    if (!p) {
        list.head = q;
        return;
    }
    if (!q) {
        return;
    }

    if (p->data < q->data) {
        list.head = last = p;
        p = p->next;
    } else {
        list.head = last = q;
        q = q->next;
    }
    last->next = nullptr;

    while (p != nullptr && q != nullptr) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
        } else {
            last->next = q;
            last = q;
            q = q->next;
        }
        last->next = nullptr;
    }

    if (p != nullptr) {
        last->next = p;
    } else {
        last->next = q;
    }

    list2.head = nullptr;
}

private:
    Node* head; // Pointer to the first node in the list
};

int main() {
    LinkedList list; // Create a linked list object

    // Append elements to the list
    list.append(1);
    list.append(2);
    list.append(3);

    // Display the contents of the list
    cout << "List contents: ";
    list.display();

    // Reverse the list iteratively
    cout << "Reversing list..." << endl;
    list.reverse(list.head);

    // Display the reversed list
    cout << "Reversed list: ";
    list.display();

    return 0;
}
