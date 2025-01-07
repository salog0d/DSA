#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};

class LinkedList {

private:
    Node* head; 

public:
    
    LinkedList() : head(nullptr) {}

    void append(int data){
        Node * newnode = new Node();
        newnode->data = data;
        newnode->next = nullptr;

        if(head==nullptr){
            head=newnode;
            return;
        }
        Node * temp = head;
        while(temp->next != nullptr){
            temp= temp->next;
        }
        temp->next = newnode;
    }

    void displayList(){
        Node * temp = head;
        while(temp != nullptr){
            cout<<temp->data<<endl;
            temp=temp->next; 
        } 
    }

    void countNodes(){
        int nodes = 0;
        Node * temp = head;
        while(temp != nullptr){
            temp = temp->next;
            nodes ++;
        }
        cout<<"The list has " << nodes << " nodes."<<endl;
    }

    void sum(){
        int sum = 0;
        Node * temp = head;
        while(temp != nullptr){
            sum += temp->data;
            temp = temp->next;
        }
        cout<<"The sum of the list is: " << sum <<endl;
    }

    void max(){
        int max = 0;
        Node * temp = head;
        while(temp != nullptr){
            if(temp->data > max){
                max = temp->data;
            }
            temp = temp->next;
        }
        cout<<"The maximum value of the list is: " << max <<endl;
    }

    void insert(int index, int x){
        Node * temp = head;

        Node * inserction = new Node();
        inserction->data = x;
        inserction->next = nullptr;

        if(index==0){
            inserction->next = temp;
            head = inserction;

        }else{
            for(int i=0;i<index-1;i++){
                temp = temp -> next;
            }
            inserction ->next = temp->next;
            temp->next = inserction;
        }
    }

    void insertLast(int x){
        Node * temp = head;
        Node * inserction = new Node();
        inserction->data = x;
        inserction->next = nullptr;

        while(temp->next != nullptr){
            temp=temp->next;
        }
        temp->next = inserction;
    }

    void deleteNode(int index) {
        if (head == nullptr) {  
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        if (index == 0) {
            head = temp->next;  
            delete temp;        
            return;
        }

        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Index out of range!" << endl;
            return;
        }

        Node* temp2 = temp->next;  
        temp->next = temp2->next;   
        delete temp2;              
    }


    void sorted(){
        Node * temp = head;
        while(temp != nullptr && temp->next != nullptr){
            if(temp->data>temp->next->data){
                cout<<"The list is not sorted"<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"The list is sorted"<<endl;
    }

    void removeDuplicates(){

    }

    void reverse(){
        Node *p= head;
        Node *q = nullptr;
        Node *r = nullptr;

        while(p != nullptr){
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head = q;   
     }

    void concatenate(LinkedList list, LinkedList list2){
        Node * temp = list.head;
        while(temp->next!=nullptr){
            temp= temp->next;
        }
        temp->next=list2.head;
    }

    void merge(LinkedList list, LinkedList list2){
        
    }


};

int main(){
    LinkedList list;
    LinkedList list2;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list2.append(1);
    list2.append(2);
    list2.append(3);
    list2.append(4);
    list2.append(5);
    list.merge(list, list2);
    list.displayList();

    return 0;
}