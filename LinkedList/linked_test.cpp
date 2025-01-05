#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};

class LinkedList {
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

    void deleteNode(int index){

    }

    void sorted(){

    }

    void removeDuplicates(){

    }

    void reverse(){

    }

    void concatenate(){
        
    }

private:
    Node* head; 
};

int main(){
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.displayList();
    list.countNodes();
    list.sum();
    list.max();
    list.insert(3,7);
    list.displayList();
    list.insertLast(100);
    list.displayList();
    list.sum();
    list.max();

    return 0;
}