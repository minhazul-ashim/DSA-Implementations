// This Program Contains the Structure of Singly Linked Lists and all it's operations;

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

void printLinkedList(Node * head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl << endl;
}

void insert_at_tail(Node * & head, int v) {
    Node *newNode = new Node(v);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << "Inserted at Tail" << endl << endl;
}

void insert_at_any_pos(Node *head, int pos, int v) {
    Node *newNode = new Node(v);
    Node *temp = head;
    for (int i = 1; i <= pos-1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted at pos" << pos << endl<< endl;
}

void insert_at_head(Node *& head, int v) {
    Node *newNode = new Node(v);
    newNode->next = head;
    head = newNode;
    cout << endl << "Inserted at Head" << endl << endl;
}

void delete_from_position(Node * head, int pos) {
    Node *temp = head;
    for (int i = 1; i <= pos-1; i++) {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
    cout << "Deleted from position " << pos << endl << endl;
}

void delete_head(Node *& head) {
    Node * deleteHead = head;
    head = head->next;
    delete deleteHead;
    cout << "Deleted Head" << endl << endl;
}

void delete_tail(Node * head) {
    Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    Node *deleteNode = temp->next->next;
    temp->next = NULL;
    delete deleteNode;
    cout << "Deleted Tail" << endl << endl;
}

int main () {
    Node *head = NULL;
    while(true) {
        cout << "Option 1 : Insert at Tailing Position" << endl;
        cout << "Option 2 : Insert at any Position" << endl;
        cout << "Option 3 : Insert at Heading Position" << endl;
        cout << "Option 4 : Delete from Position" << endl;
        cout << "Option 5 : Delete Head" << endl;
        cout << "Option 6 : Delete Tail" << endl;
        cout << "Option 7 : Take a Linked List as Input" << endl;
        cout << "Option 8 : Print LinkedList" << endl;
        cout << "Option 0 : Terminate Program" << endl;
        cout << "Your Option : ";
        int op;
        cin >> op;
        cout << endl;
        if(op == 0) {
            cout << "Terminated";
            return 0;
        }
        if(op == 1) {
            int v;
            cout << "Enter value to add at Tail ";
            cin >> v;
            cout << endl;
            insert_at_tail(head, v);
        } else if(op == 2) {
            int pos, v;
            cout << "Enter position ";
            cin >> pos;
            cout << "Enter value ";
            cin >> v;
            if(pos == 0) {
                insert_at_head(head, v);
            }
            insert_at_any_pos(head, pos, v);
        } else if(op == 3) {
            int v;
            cout << "Enter value " << " " << endl;
            cin >> v;
            insert_at_head(head, v);
        } else if(op == 4) {
            int pos;
            cout << "Enter position ";
            cin >> pos;
            cout << endl;
            delete_from_position(head, pos);
        } else if(op == 5) {
            delete_head(head);
        } else if(op == 6) {
            delete_tail(head);
        } else if(op == 7) {
            int flag = true;
            while(flag) {
                int v;
                cout << "Enter value ";
                cin >> v;
                cout << endl;
                if(v == -1) {
                    flag = false;
                } else {
                    insert_at_tail(head, v);
                }
            }
        } else if(op == 8) {
            printLinkedList(head);
        }
    }
}