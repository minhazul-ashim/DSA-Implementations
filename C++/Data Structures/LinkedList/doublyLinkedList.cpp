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

void print_normal (Node * head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_reverse(Node * tail) {
    Node *temp = tail;
    while(temp != NULL) {
        cout << temp->value << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int get_size (Node * head) {
    int count = 0;
    Node *temp = head;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void insert_head (Node *& head, Node *& tail, int v) {
    Node *newNode = new Node(v);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_tail(Node *& head, Node *&tail, int v) {

    Node *newNode = new Node(v);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void insert_any_position(Node *& head, Node *& tail, int v, int pos) {

    if(pos >= get_size(head)) {
        cout << "Invalid Position" << endl;
        insert_tail(head, tail, v);
        cout << "Inserted at Tail" << endl;
        return;
    } else if(pos == 0) {
        insert_head(head, tail, v);
        cout << "Inserted at Head" << endl;
        return;
    }
    Node *newNode = new Node(v);
    Node *temp = head;
    for (int i = 1; i <= pos-1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
    cout << "Inserted at Position " << pos << endl;
}

void delete_head(Node *& head) {
    Node *deleteNode = head;
    head->next->prev = NULL;
    head = head->next;
    delete deleteNode;
}

void delete_tail(Node *& tail) {
    Node *deleteNode = tail;
    tail->prev->next = NULL;
    tail = tail->prev;
    delete deleteNode;
}

void delete_at_position(Node *& head, Node *& tail, int pos) {
    if(pos == 0) {
        delete_head(head);
        cout << "Deleted Head" << endl;
        return;
    } else if(pos >= get_size(head)) {
        delete_tail(tail);
        cout << "Deleted Tail" << endl;
        return;
    }

    Node *deleteNode = head;
    for (int i = 1; i <= pos; i++) {
        deleteNode = deleteNode->next;
    }
    deleteNode->next->prev = deleteNode->prev;
    deleteNode->prev->next = deleteNode->next;
    delete deleteNode;
    cout << "Deleted from Position " << pos << endl;
}

void insert_linked_list (Node *& head, Node *& tail) {
    while(true) {
        int val;
        cin >> val;
        if(val == -1) {
            break;
        } else {
            insert_tail(head, tail, val);
        }
    }
}

void sort_linked_list(Node *& head, bool asc) {
    for (Node *i = head; i->next != NULL; i=i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if(asc && i->value > j->value) {
                swap(i->value, j->value);
            } else if(!asc && i->value < j->value) {
                swap(i->value, j->value);
            }
        }
    }
    cout << "Linked List Sorted Successfully" << endl << endl;
}


int main () {
    Node *head = NULL;
    Node *tail = NULL;
    while(true) {
        int op;
        cout << "Option 0: Insert Head" << endl;
        cout << "Option 1: Insert Tail" << endl;
        cout << "Option 2: Insert at any Position" << endl;
        cout << "Option 3: Insert a Linked List" << endl;
        cout << "Option 4: Delete Head" << endl;
        cout << "Option 5: Delete Tail" << endl;
        cout << "Option 6: Delete from any Position" << endl;
        cout << "Option 7: Print Linked List Normally" << endl;
        cout << "Option 8: Print Linked List Reversely" << endl;
        cout << "Option 9: Sort Linked List in Ascending Order" << endl;
        cout << "Option 10: Sort Linked List in Descending Order" << endl;
        cout << "Option 11: Terminate Program" << endl;
        cout << "Enter your Choice" << " ";
        cin >> op;
        cout << endl;
        if(op == 0) {
            cout << "Enter Value" << " ";
            int val;
            cin >> val;
            insert_head(head, tail, val);
            cout << endl;
        } else if(op == 1) {
            cout << "Enter Value" << " ";
            int val;
            cin >> val;
            insert_tail(head, tail, val);
            cout << endl;
        } else if(op == 2) {
            cout << "Enter Value" << " ";
            int val;
            cin >> val;
            cout << endl;
            cout << "Enter Position" << " ";
            int pos;
            cin >> pos;
            insert_any_position(head, tail, val, pos);
            cout << endl;
        } else if(op == 3) {
            cout << "Enter your linked list. Insert -1 to indicate the end of the linked list" << endl;
            insert_linked_list(head, tail);
        } else if(op == 4) {
            delete_head(head);
            cout << "Deleted Head" << endl;
        } else if(op == 5) {
            delete_tail(tail);
            cout << "Deleted Tail" << endl;
        } else if(op == 6) {
            cout << "Enter Deleting Node Position ";
            int pos;
            cin >> pos;
            cout << endl;
            delete_at_position(head, tail, pos);
        } else if(op == 7) {
            print_normal(head);
        } else if(op == 8) {
            print_reverse(tail);
        } else if(op == 9) {
            sort_linked_list(head, true);
        } else if(op == 10) {
            sort_linked_list(head, false);
        } else if(op == 11) {
            cout << "Program Terminated" << endl << endl;
            break;
        } else {
            cout << "Invalid Choice Entered" << endl << endl;
        }
    }
    return 0;
}