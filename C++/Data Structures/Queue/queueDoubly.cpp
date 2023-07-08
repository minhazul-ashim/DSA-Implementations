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
        newNode->prev = tail;
        tail = newNode;
    }
    void pop() {
        sz--;
        Node *deleteNode = head;
        head = head->next;
        if(head == NULL) {
            tail = NULL;
            delete deleteNode;
            return;
        }
        head->prev = NULL;
        delete deleteNode;
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