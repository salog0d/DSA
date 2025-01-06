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

    void displayRecursive(Node* p) {
        if (p != nullptr) {
            cout << p->data << " ";
            displayRecursive(p->next);
        }

        // Method to count the number of nodes in the list
        int countNodes(Node* p) {
            int count = 0;
            while (p != nullptr) {
                count++;
                p = p->next;
            }
            return count;
        }

    int sumRecursive(Node *p) {
        if (p == nullptr) {
            return 0;
        }
        return sum(p->next) + p->data;
    }

    int sum(Node *p) {
        int sum = 0;
        while (p != nullptr) {
            sum += p->data;
            p = p->next;
        }
        return sum;
    }

    int max(Node *p) {
        int max = INT_MIN;
        while (p != nullptr) {
            if (p->data > max) {
                max = p->data;
            }
            p = p->next;
        }
        return max;
    }

    int maxRecursive(Node *p) {
        if (p == nullptr) {
            return INT_MIN;
        }
        int x = maxRecursive(p->next);
        return x > p->data ? x : p->data;
    }

    int linearSearch(Node *p, int key) {
        while (p != nullptr) {
            if (p->data == key) {
                return p->data;
            }
            p = p->next;
        }
        return -1;
    }

    int linearSearchRecursive(Node *p, int key) {
        if (p == nullptr) {
            return -1;
        }
        if (p->data == key) {
            return p->data;
        }
        return linearSearchRecursive(p->next, key);
    }

    int binarySearch(Node *p, int key) {
        int low = 0;
        int high = countNodes(p) - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            Node *temp = p;
            for (int i = 0; i < mid; i++) {
                temp = temp->next;
            }
            if (temp->data == key) {
                return temp->data;
            } else if (temp->data < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    int binarySearchRecursive(Node *p, int low, int high, int key) {
        if (low > high) {
            return -1;
        }
        int mid = (low + high) / 2;
        Node *temp = p;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        if (temp->data == key) {
            return temp->data;
        } else if (temp->data < key) {
            return binarySearchRecursive(p, mid + 1, high, key);
        } else {
            return binarySearchRecursive(p, low, mid - 1, key);
        }
    }

    int insert(Node *p, int index, int x) {
        if (index < 0 || index > countNodes(p)) {
            return -1;
        }
        Node *temp = new Node();
        temp->data = x;
        if (index == 0) {
            temp->next = head;
            head = temp;
        } else {
            Node *q = head;
            for (int i = 0; i < index - 1 && q; i++) {
                q = q->next;
            }
            temp->next = q->next;
            q->next = temp;
        }
        return x;
    }

    int insertLast(int x) {
        Node * next = new Node();
        t->data = x;
        t->next = nullptr;
        if(first==nullptr){
            first = last = t;
    }
        else{
            last->next = t;
            last = t;
    }
        return x;
    }
    
    int insertSorted(Node* p, int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = nullptr;

    // Si la lista está vacía o el nuevo nodo debe ser el primero
    if (head == nullptr || head->data >= x) {
        temp->next = p;
        p = temp;
        return x;
    }

    // Encuentra la posición correcta para insertar el nuevo nodo
    Node* current = p;
    while (current->next != nullptr && current->next->data < x) {
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;

    return x;
}

int delete(int index){
    Node *p, *q;
    int x = -1;
    if(index < 1 || index > countNodes(head)){
        return -1;
    }

    if(index == 1){
        p = head;
        head = head->next;
        x = p->data;
        delete p;

    }else{
        p = head;
        for(int i=0; i<index-1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
}

bool sortedList(Node *head){
    Node * temp = head;
    for(int i=0; i<countNodes(head)-1; i++){
        if(temp->data > temp->next->data){
            return false;
        }
        temp = temp->next;
    }
    return true;
}

bool sortedList2(Node* head) {
    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->data > temp->next->data) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void removeDuplicates(Node* head) {
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}



private:
    Node* head;  // Pointer to the first node in the list
};
}
int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.display();
    return 0;
}