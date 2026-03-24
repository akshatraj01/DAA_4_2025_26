#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};
class DoublyLinkedList{
public:
    Node* head;
    DoublyLinkedList(){
        head=NULL;
    }

    void insertEnd(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=newNode;
            return;
        }

        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=newNode;
        newNode->prev=temp;
    }

    void display(){
        Node* temp=head;
        cout<<"Doubly Linked List";
        while(temp!=NULL) {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main(){
    DoublyLinkedList dll;
    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertEnd(30);
    dll.display();
    return 0;
}
