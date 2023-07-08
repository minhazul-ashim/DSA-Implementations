#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int value;
    Node *next;
    Node(int v) {
        this->value = v;
        this->next = NULL;
    }
};

class MyQueue {
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
        tail = newNode;
    }
    void pop() {
        sz--;
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
        if(head == NULL) {
            tail == NULL;
        }
    }
    int front() {
        return head->value;
    }
    int size() {
        return sz;
    }
    bool empty() {
        if(sz == 0) {
            return true;
        } else {
            return false;
        }
    }
};

int main () {
    MyQueue q;
    q.push(10);
    q.push(20);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    return 0;
}