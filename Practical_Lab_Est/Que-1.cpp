#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Stack{
    Node* top;

    public:
    Stack(){
        top = NULL;
    }

    void push(int x){
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (top == NULL){
            cout<<"Stack Underflow\n";
            return;
        }
        Node* temp=top;
        top = top->next;
        delete temp;
    }

    int peek(){
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }
};