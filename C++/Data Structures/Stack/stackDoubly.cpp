#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *next;
    Node *prev;
    Node(int v) {
        this->value = v;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyStack {
    public:
        Node *head = NULL;
        Node *tail = NULL;
        int sz = 0;
        void push(int val) {
            sz++;
            Node *newNode = new Node(val);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        void pop() {
            sz--;
            Node *deleteNode = tail;
            tail = tail->prev;
            if(tail == NULL) {
                head = NULL;
            }
            delete deleteNode;
        }
        int top() {
            return tail->value;
        }
        int size() {
            return sz;
        }
        bool empty() {
            if(head == NULL) {
                return true;
            } else {
                return false;
            }
        }
};

int main () {
    MyStack stack;
    stack.push(10);
    stack.push(20);
    stack.pop();
    stack.pop();
    if(!stack.empty()) {
        cout << stack.top() << endl;
    }
    return 0;
}